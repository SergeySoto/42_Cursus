NAME= get_next_line.a

CC= cc

AR=ar rcs

CFLAGS=-Wall -Werror -Wextra

FSANITAZER = -fsanitize=address 

RM=rm -rf

SRC =

INCLUDE = get_next_line.h

OBJS=$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^

shit:
	$(CC) $(CFLAGS) $(FSANITAZER) $(SRC) main.c -o pileOfShit
	clear && ./pileOfShit
	$(RM) ./pileOfShit

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re