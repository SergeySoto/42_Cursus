#include <string.h>
#include <unistd.h>

<<<<<<< HEAD
=======
char	ft_putstr(char *s)
{
	int	i;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
	}
	return(s);
}


>>>>>>> carmegon
int	main(void)
{
	prinf("Hola mundo %");
	return (0);
}
