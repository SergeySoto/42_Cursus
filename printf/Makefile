NAME=libftprintf.a

CC= cc

AR=ar rcs

CFLAGS=-Wall -Werror -Wextra

FSANITAZER = -fsanitize=address 

RM=rm -rf

SRC = ft_printf.c ft_format.c ft_pf_putchar.c ft_pf_putint.c ft_pf_putnbr.c \
	ft_pf_putptr.c ft_pf_putstr.c ft_pf_putuint.c ft_pf_putunbr.c ft_pf_puthexalow.c \
	ft_pf_puthexaup.c

INCLUDE = ft_printf.h

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
