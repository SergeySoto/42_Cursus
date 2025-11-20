void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a / *b;
	*b = *a % *b;
	*a = temp;
}

int	main(void)
{
	int 	a;
	int	b;

	a = 2;
	b = 40;

	ft_ultimate_div_mod(&a, &b);
	return (0);
}
