*This project has been created as part of the 42 curriculum by ssoto-su.*

# Inception

## Description

Inception is a System Administration project from the 42 curriculum. Its goal is to
build a small, self-contained web infrastructure using Docker, with every image
built from scratch (no pre-made images pulled from Docker Hub, except for the
Alpine/Debian base layer).

The stack is composed of three services, each running in its own dedicated
container, connected through a single Docker network:

- **NGINX** — the only entry point of the infrastructure, listening on port 443
  with TLSv1.2/TLSv1.3 only.
- **WordPress + php-fpm** — the CMS itself, with php-fpm as the process manager
  (no web server bundled in this container).
- **MariaDB** — the database engine that stores WordPress data.

Two named Docker volumes persist the WordPress database and the WordPress files
on the host, at `/home/ssoto-su/data`.

## Instructions

### Prerequisites

- A virtual machine with Docker and Docker Compose installed.
- An entry in `/etc/hosts` pointing `ssoto-su.42.fr` to the VM's local IP address.

### Setup

1. Clone the repository.
2. Create the `secrets/` files (`db_password.txt`, `db_root_password.txt`,
   `wp_admin_password.txt`, `wp_user_password.txt`) at the repository root —
   these are intentionally not versioned.
3. Create `srcs/.env` with the required configuration variables (domain name,
   database name/user, WordPress admin/user info).

### Build and run

```
make          # builds every image and starts the stack in the background
make down     # stops and removes the containers
make stop     # stops the containers without removing them
make clean    # stops the stack and prunes unused Docker resources
make fclean   # clean + removes the persisted data on the host
make re       # fclean + make (full rebuild from scratch)
```

Once running, the site is reachable at `https://ssoto-su.42.fr`.

## Project description: Docker design choices

### Virtual Machines vs Docker

A virtual machine virtualizes an entire computer, including its own kernel, which
makes it heavier to run and slower to start. A Docker container instead shares
the host machine's kernel and only isolates the application layer (processes,
filesystem, network), which makes it lightweight and fast to start. In this
project, each service (NGINX, WordPress, MariaDB) runs in its own container
rather than its own VM, which keeps resource usage low while still isolating
each service from the others.

### Secrets vs Environment Variables

An environment variable declared in `docker-compose.yml` (or loaded from a
`.env` file) is visible in plain text inside the container — through
`docker inspect`, `printenv`, or the container's process environment — and can
end up in logs or crash reports. A Docker secret is mounted as a read-only file
under `/run/secrets/<name>`, backed by `tmpfs` (memory, not disk), and is not
exposed through `docker inspect`. For this reason, all passwords in this
project (database root password, database user password, WordPress admin and
user passwords) are handled as Docker secrets, while non-sensitive
configuration (domain name, database name, usernames, WordPress title) is kept
in the `.env` file.

### Docker Network vs Host Network

With `network: host`, a container shares the host's network stack directly,
which removes network isolation and is explicitly forbidden by the subject.
This project instead defines a dedicated user-defined bridge network
(`inception`). Every container that joins this network gets its own virtual
network interface, and Docker provides automatic DNS resolution between
containers by their service name (for example, `wordpress` can reach the
database simply by connecting to the host `mariadb`). This keeps services
isolated from the host and from each other, while still letting them talk to
one another only through the ports they choose to expose inside the network.

### Docker Volumes vs Bind Mounts

A bind mount maps a specific folder on the host directly into a container; it
is simple, but it is fully managed by the user and not tracked by Docker as a
first-class resource. A Docker named volume is created and managed by Docker
itself (`docker volume ls`, `docker volume inspect`), and its lifecycle is
decoupled from any single container. The subject requires named volumes whose
data is nonetheless physically stored at `/home/ssoto-su/data`, which this
project achieves by declaring named volumes with `driver_opts` of
`type: none, o: bind`, pointing to that exact host path — combining the
Docker-managed identity of a named volume with a predictable, inspectable
location on disk.

## Resources

- Docker documentation: https://docs.docker.com/
- Docker Compose file reference: https://docs.docker.com/compose/compose-file/
- WordPress CLI documentation: https://developer.wordpress.org/cli/commands/
- MariaDB documentation: https://mariadb.com/kb/en/documentation/
- NGINX documentation: https://nginx.org/en/docs/

### AI usage

An AI assistant (Claude, by Anthropic) was used throughout this project as a
learning aid, not as a code generator to copy verbatim. Its use was split in
two ways: for purely declarative configuration (Dockerfiles, `docker-compose.yml`,
NGINX and PHP-FPM configuration files), the assistant provided complete
examples together with a line-by-line explanation of what each instruction
does and why it is required by the subject. For the scripted logic (the
`entrypoint.sh` files for MariaDB and WordPress, which include conditionals,
loops, and idempotency checks), the assistant acted as a Socratic mentor:
explaining Bash syntax with generic, out-of-project examples, and reviewing
drafts written by the student, pointing out bugs and reasoning about them,
rather than writing that logic directly. The student also brought a
Bash script suggested by a different AI tool for the WordPress entrypoint;
this was reviewed together with Claude, which identified a critical bug (a
required environment variable that was never populated from its Docker
secret) and a design inconsistency (a secrets file format that did not match
the project's own conventions), which the student then chose how to resolve.
