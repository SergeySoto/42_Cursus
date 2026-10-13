FROM debian:12

RUN apt-get update && apt-get install -y \
    nginx \
    && rm -rf /var/lib/apt/lists/*

COPY ./conf/nginx.conf /etc/nginx/conf.d/default.conf

COPY ./app /var/www/html

RUN chown -R www-data:www-data /var/www/html

EXPOSE 80

ENTRYPOINT ["nginx", "-g", "daemon off;"]