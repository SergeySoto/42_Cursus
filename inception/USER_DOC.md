# User Documentation — Inception

This guide explains, in simple terms, how to use the infrastructure deployed
by this project: which services it provides, how to start and stop it, how to
access the site, where the credentials live, and how to check that everything
is working.

## 1. Services provided by the stack

The project runs multiple pieces, each in its own container:

**Core Services:**
- **NGINX**: the single entry point to the main website. It receives all traffic over HTTPS (port 443) and forwards it internally to WordPress.
- **WordPress**: the content management system where your website and its admin panel live.
- **MariaDB**: the database where WordPress stores all its information.

**Bonus Services:**
- **Redis**: Works silently in the background caching WordPress database queries to speed up the site.
- **FTP**: An FTP server (vsftpd) that allows transferring files directly to the WordPress web directory.
- **Adminer**: A web-based database management tool to inspect the MariaDB database directly.
- **Static Site**: A standalone static HTML page (CV) served independently.
- **Portainer**: A graphical user interface (GUI) to monitor and manage all these Docker containers easily.

## 2. Starting and stopping the project

From the repository root (where the `Makefile` is):

| Action | Command |
|---|---|
| Start the whole project | `make` (equivalent to `make up`) |
| Stop the containers (without removing anything) | `make stop` |
| Stop and remove the containers | `make down` |
| Clean up unused containers/images | `make clean` |
| Full teardown, including stored data | `make fclean` |
| Rebuild everything from scratch | `make re` |

The first time you run `make`, building the images and installing WordPress can take a minute or two.

## 3. Accessing the services

Once the stack is up, you can access the different services using your browser or an FTP client:

- **Main Website (WordPress)**: `https://ssoto-su.42.fr`
  *(Note: Since the SSL certificate is self-signed, your browser will show a security warning the first time. Accept the risk to continue).*
- **WP Admin Panel**: `https://ssoto-su.42.fr/wp-admin`
- **Adminer**: `http://ssoto-su.42.fr:8080`
  *(Login System: MySQL, Server: `mariadb`, Username: `root` or `wp_user`, Database: `wordpress`)*
- **Static Site (CV)**: `http://ssoto-su.42.fr:8081`
- **Portainer**: `http://localhost:9000` or `http://ssoto-su.42.fr:9000`
- **FTP Server**: Connect using an FTP client (like FileZilla or `ftp` command) to `ssoto-su.42.fr` on port `21`.

## 4. Where the credentials are

Credentials in this project are split across two places:

- **Passwords** (never committed to the repository): stored in the `secrets/` folder, one file per password:
  - `secrets/db_root_password.txt` → MariaDB's root password.
  - `secrets/db_password.txt` → password of the database user used by WordPress.
  - `secrets/wp_admin_password.txt` → WordPress administrator's password.
  - `secrets/wp_user_password.txt` → password of the second WordPress user.
  - `secrets/ftp_password.txt` → FTP user's password.
- **Usernames and other configuration** (not sensitive): stored in `srcs/.env` — there you will find `WP_ADMIN_USER`, `WP_USER`, and the FTP username among others.

## 5. Checking that services are running correctly

The easiest way to check the status of all your services visually is by logging into **Portainer** (`http://localhost:9000`).

Alternatively, via the terminal:

```bash
docker compose -f srcs/docker-compose.yml ps
```

You should see 8 containers (`nginx`, `wordpress`, `mariadb`, `redis`, `ftp`, `adminer`, `static_site`, `portainer`) with an `Up` status. If any of them keeps restarting, check its logs with:

```bash
docker compose -f srcs/docker-compose.yml logs <service_name>
```