#!/bin/bash
set -e

WP_DIR="/var/www/html"

if [ -f "/run/secrets/ftp_password" ]; then
    FTP_PASSWORD="$(cat /run/secrets/ftp_password)"
else
    echo "Error: Secret ftp_password no encontrado."
    exit 1
fi

if ! id -u "$FTP_USER" >/dev/null 2>&1; then
    echo "Creando usuario FTP: $FTP_USER"
    
    useradd -m -d "$WP_DIR" -s /usr/sbin/nologin -g www-data "$FTP_USER"
    
    echo "$FTP_USER:$FTP_PASSWORD" | chpasswd
    
    chown -R www-data:www-data "$WP_DIR"
    chmod -R 775 "$WP_DIR"
    
    echo "Usuario FTP configurado exitosamente."
else
    echo "El usuario FTP ya existe."
fi

exec vsftpd /etc/vsftpd.conf