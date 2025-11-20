# Define el nombre del ejecutable
NAME = execute
CC = cc
# Define las flags del compilador
CFLAGS = -Wall -Wextra -Werror
# Lista de archivos fuente del proyecto
SRC = src/utils.c src/main.c
# Regla principal que compila el programa
all: $(NAME)
	
$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

# Elimina el archivo ejecutable
clean:
	rm -f $(NAME)
# Ejecuta clean y luego all para recompilar todo
re: clean all
# Ejecuta el programa
run: $(NAME)
	./$(NAME)
# Declara las reglas que no generan archivos
.PHONY: all clean re run