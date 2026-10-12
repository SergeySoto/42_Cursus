NAME		= inception
COMPOSE		= srcs/docker-compose.yml
DATA_DIR	= $(HOME)/data
COMPOSE_BONUS	= srcs/docker-compose.bonus.yml
ALL_FILES	= -f $(COMPOSE) -f $(COMPOSE_BONUS)

all: up

up:
	@mkdir -p $(DATA_DIR)/wordpress $(DATA_DIR)/mariadb
	docker compose -f $(COMPOSE) up --build -d -y

bonus:
	@mkdir -p $(DATA_DIR)/wordpress $(DATA_DIR)/mariadb
	docker compose $(ALL_FILES) up --build -d -y

down:
	docker compose $(ALL_FILES) down

stop:
	docker compose $(ALL_FILES) stop

clean: down
	docker compose $(ALL_FILES) down --volumes
	docker system prune -af

fclean: clean
	sudo rm -rf $(DATA_DIR)

re: fclean all

.PHONY: all up bonus down stop clean fclean re