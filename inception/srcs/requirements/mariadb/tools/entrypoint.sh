#!/bin/bash
set -e

MYSQL_DATA_DIR="/var/lib/mysql"
MYSQL_SOCKET="/run/mysqld/mysqld.sock"
INIT_MARKER="$MYSQL_DATA_DIR/.initialized"

MYSQL_ROOT_PASSWORD="$(cat /run/secrets/db_root_password)"
MYSQL_PASSWORD="$(cat /run/secrets/db_password)"

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld "$MYSQL_DATA_DIR"

if [ ! -d "$MYSQL_DATA_DIR/mysql" ]; then
    mariadb-install-db \
        --user=mysql \
        --datadir="$MYSQL_DATA_DIR"
fi

if [ ! -f "$INIT_MARKER" ]; then
    mariadbd \
        --user=mysql \
        --skip-networking \
        --socket="$MYSQL_SOCKET" &

    TEMP_SERVER_PID=$!

    until mariadb-admin \
        --socket="$MYSQL_SOCKET" \
        ping --silent
    do
        sleep 1
    done

    mariadb \
        --socket="$MYSQL_SOCKET" \
        -u root <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
ALTER USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    touch "$INIT_MARKER"

    kill "$TEMP_SERVER_PID"
    wait "$TEMP_SERVER_PID" || true
fi

exec mariadbd --user=mysql