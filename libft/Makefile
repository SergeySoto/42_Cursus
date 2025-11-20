# nombre del archivo de la biblioteca
NAME = libft.a

# compilador y bandeas de compilacion
CC = cc
CFLAGS = -Wall -Wextra -Werror

# archivos fuente y archivos objeto
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c\
ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c\
ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
ft_putnbr_fd.c 
SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o) 

# archivo de encabezado
INCLUDE = libft.h

# regla por defecto que compila todo
all: $(NAME)

# regla para crear la biblioteca
$(NAME): $(OBJ)  
	ar rcs $(NAME) $(OBJ)

# pasar archivos .c a .o
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

ejecutarall:
	$(CC) $(CFLAGS) *.c
		a.out

# regla para eliminar todos los archivos objetos creados
clean:
	rm -f $(OBJ)

# Eliminar todos los archivos .o y .a
fclean: clean
	rm -f $(NAME)

# recompila
re: fclean all

# indica que las siguientes reglas no son archivos reales
.PHONY: all bonus clean fclean re 
