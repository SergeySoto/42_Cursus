#include <unistd.h>

char	ft_putchr(char c)
{
	write(1, &c, 1);
	return (c);
}
