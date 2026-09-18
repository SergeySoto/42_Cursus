#!/bin/bash
set -e

WORDPRESS_DIR="/var/www/html"
DB_HOST="${MYSQL_HOST:-mariadb}"
DB_PORT="${MYSQL_PORT:-3306}"

MYSQL_PASSWORD="$(cat /run/secrets/db_password)"
WP_ADMIN_PASSWORD="$(cat /run/secrets/wp_admin_password)"
WP_USER_PASSWORD="$(cat /run/secrets/wp_user_password)"

: "${DOMAIN_NAME:?DOMAIN_NAME is required}"
: "${MYSQL_DATABASE:?MYSQL_DATABASE is required}"
: "${MYSQL_USER:?MYSQL_USER is required}"
: "${WP_ADMIN_USER:?WP_ADMIN_USER is required}"
: "${WP_ADMIN_EMAIL:?WP_ADMIN_EMAIL is required}"
: "${WP_TITLE:?WP_TITLE is required}"

mkdir -p "$WORDPRESS_DIR"
chown -R www-data:www-data "$WORDPRESS_DIR"

until mariadb-admin ping \
	--host="$DB_HOST" \
	--port="$DB_PORT" \
	--user="$MYSQL_USER" \
	--password="$MYSQL_PASSWORD" \
	--silent
do
	sleep 2
done

cd "$WORDPRESS_DIR"

if [ ! -f wp-config.php ]; then
	wp config create \
		--dbname="$MYSQL_DATABASE" \
		--dbuser="$MYSQL_USER" \
		--dbpass="$MYSQL_PASSWORD" \
		--dbhost="$DB_HOST:$DB_PORT" \
		--skip-check \
		--allow-root
fi

if ! wp core is-installed --allow-root; then
	wp core install \
		--url="https://${DOMAIN_NAME}" \
		--title="$WP_TITLE" \
		--admin_user="$WP_ADMIN_USER" \
		--admin_password="$WP_ADMIN_PASSWORD" \
		--admin_email="$WP_ADMIN_EMAIL" \
		--skip-email \
		--allow-root
fi

if [ -n "${WP_USER:-}" ] && [ -n "${WP_USER_EMAIL:-}" ] \
	&& ! wp user get "$WP_USER" --allow-root >/dev/null 2>&1; then
	wp user create "$WP_USER" "$WP_USER_EMAIL" \
		--user_pass="$WP_USER_PASSWORD" \
		--role=author \
		--allow-root
fi

chown -R www-data:www-data "$WORDPRESS_DIR"

exec php-fpm8.2 -F
