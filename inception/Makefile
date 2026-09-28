NAME		= inception
COMPOSE		= srcs/docker-compose.yml
DATA_DIR	= $(HOME)/data

all: up

up:
	@mkdir -p $(DATA_DIR)/wordpress $(DATA_DIR)/mariadb
	docker compose -f $(COMPOSE) up --build -d -y

down:
	docker compose -f $(COMPOSE) down

stop:
	docker compose -f $(COMPOSE) stop

clean: down
	docker compose -f $(COMPOSE) down --volumes
	docker system prune -af

fclean: clean
	sudo rm -rf $(DATA_DIR)

re: fclean all

.PHONY: all up down stop clean fclean re