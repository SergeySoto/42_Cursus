FROM alpine:3.18

RUN apk update && apk add --no-cache \
    wget \
    tar \
    ca-certificates

WORKDIR /opt

RUN wget https://github.com/portainer/portainer/releases/download/2.19.4/portainer-2.19.4-linux-amd64.tar.gz \
    && tar -xvf portainer-2.19.4-linux-amd64.tar.gz \
    && rm portainer-2.19.4-linux-amd64.tar.gz

EXPOSE 9000

ENTRYPOINT ["/opt/portainer/portainer"]