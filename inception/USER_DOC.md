# User Documentation — Inception

This guide explains, in simple terms, how to use the infrastructure deployed
by this project: which services it provides, how to start and stop it, how to
access the site, where the credentials live, and how to check that everything
is working.

## 1. Services provided by the stack

The project runs three pieces, each in its own container:

- **NGINX**: the single entry point to the website. It receives all traffic
  over HTTPS (port 443) and forwards it internally to WordPress.
- **WordPress**: the content management system where your website and its
  admin panel live.
- **MariaDB**: the database where WordPress stores all its information
  (users, posts, configuration).

As an end user, you only interact directly with NGINX and WordPress; MariaDB
works behind the scenes and is not reachable from outside the infrastructure.

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

The first time you run `make`, building the images and installing WordPress
can take a minute or two — that is expected, no need to interrupt it.

## 3. Accessing the website and the admin panel

- **Website**: once the project is up, visit `https://ssoto-su.42.fr` in your
  browser. Since the certificate is self-signed (it does not come from a
  public certificate authority), the browser will show a security warning the
  first time — that is expected in this project, you just need to accept and
  continue.
- **Admin panel**: at `https://ssoto-su.42.fr/wp-admin`, using the
  administrator's credentials (see the next section for where to find them).

## 4. Where the credentials are

Credentials in this project are split across two places, depending on whether
they are sensitive or not:

- **Passwords** (never committed to the repository): stored in the
  `secrets/` folder, one file per password:
  - `secrets/db_root_password.txt` → MariaDB's root password.
  - `secrets/db_password.txt` → password of the database user used by
    WordPress.
  - `secrets/wp_admin_password.txt` → WordPress administrator's password.
  - `secrets/wp_user_password.txt` → password of the second WordPress user
    (non-administrator).
- **Usernames and other configuration** (not sensitive): stored in
  `srcs/.env` — there you will find, among others, `WP_ADMIN_USER` (the
  username used to log into the admin panel) and `WP_USER` (the second user).

## 5. Checking that services are running correctly

To see the status of the three containers at a glance:

```
docker compose -f srcs/docker-compose.yml ps
```

You should see `nginx`, `wordpress`, and `mariadb` with a `running` (or `Up`)
status. If any of them keeps restarting or is stopped, you can check its
activity log with:

```
docker compose -f srcs/docker-compose.yml logs <service_name>
```

for example, `docker compose -f srcs/docker-compose.yml logs wordpress` to see
what is happening inside that specific container.
