#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, "Esta es la letra: ",18);
	write(1, &a, 1);
}

int	main(int argc,char **argv)
{
	char a = argv[2][0];

	ft_putchar(a);
	
	return (0);
}
