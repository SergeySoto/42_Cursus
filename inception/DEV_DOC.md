# Developer Documentation — Inception

This guide explains how to set up the environment from scratch, how to build
and launch the project, useful commands to manage containers and volumes, and
where the data is stored.

## 1. Setting up the environment from scratch

### Prerequisites

- A (Linux) virtual machine with Docker Engine and the Docker Compose plugin
  (`docker compose`, no hyphen) installed.
- Administrator access to edit `/etc/hosts`.

### Configuration files to create

None of these files are versioned in Git (they are listed in `.gitignore`):

1. **`secrets/`** (at the repository root), with one single-line file per
   password:
   - `db_root_password.txt`
   - `db_password.txt`
   - `wp_admin_password.txt`
   - `wp_user_password.txt`

2. **`srcs/.env`**, with the project's non-sensitive variables:
   ```env
   DOMAIN_NAME=ssoto-su.42.fr

   MYSQL_DATABASE=wordpress
   MYSQL_USER=wp_user

   WP_TITLE=Inception
   WP_ADMIN_USER=boss_ssoto
   WP_ADMIN_EMAIL=admin@ssoto-su.42.fr
   WP_USER=editor_ssoto
   WP_USER_EMAIL=editor@ssoto-su.42.fr
   ```
   Important: `WP_ADMIN_USER` must not contain `admin`/`administrator` in any
   form — this is an explicit restriction from the subject.

3. **`/etc/hosts`** on the VM, adding a line that points your domain to your
   own local IP:
   ```
   127.0.0.1   ssoto-su.42.fr
   ```
   (or the VM's IP, depending on how you are accessing it).

## 2. Building and launching the project

Everything goes through the `Makefile` at the root, which in turn calls
Docker Compose pointing at `srcs/docker-compose.yml`:

```
make          # creates the data folders and starts the stack with --build -d
make down     # docker compose down
make stop     # docker compose stop
make clean    # down + docker system prune -af
make fclean   # clean + removes /home/ssoto-su/data
make re       # fclean + make
```

If you need to run Compose directly (for example, to debug something), the
equivalent invocation is:

```
docker compose -f srcs/docker-compose.yml up --build -d
```

## 3. Useful commands to manage containers and volumes

| What you want to do | Command |
|---|---|
| Check service status | `docker compose -f srcs/docker-compose.yml ps` |
| View a service's logs | `docker compose -f srcs/docker-compose.yml logs -f <service>` |
| Get a shell inside a container | `docker exec -it <container_name> bash` |
| List named volumes | `docker volume ls` |
| Inspect a volume (see where it points on the host) | `docker volume inspect <volume_name>` |
| Rebuild a single service | `docker compose -f srcs/docker-compose.yml build <service>` |
| List networks | `docker network ls` |

To debug a container that keeps restarting in a loop, checking its logs
(`logs -f`) is more useful than trying `exec -it`, since the container may be
crashing before you get a chance to get a shell inside it.

## 4. Where and how the data persists

The project uses two named volumes:

- **`mariadb_data`** → mounted at `/var/lib/mysql` inside the MariaDB
  container (this is where the database physically lives).
- **`wordpress_data`** → mounted at `/var/www/html` inside both the
  WordPress and NGINX containers (the site's PHP files, shared between the
  two).

Although these are named volumes (managed by Docker, visible with
`docker volume ls`), both are configured with `bind`-type `driver_opts`,
physically pointing to:

```
/home/ssoto-su/data/mariadb
/home/ssoto-su/data/wordpress
```

This means the data survives a `make down` (which only removes containers
and the network), but is deliberately destroyed by `make fclean`, which, in
addition to stopping the stack, also removes that host directory — this is
meant to allow rebuilding the project completely from scratch when needed.

Each stateful service (MariaDB and WordPress) checks, in its own
`entrypoint.sh`, whether its data has already been initialized before
repeating the installation process — so a `make down` followed by `make up`
preserves both the database and the WordPress content, while only
`make fclean` forces a brand-new installation.
