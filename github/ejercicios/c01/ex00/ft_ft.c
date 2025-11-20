void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int	main(void)
{
	int	n;

	n = 22;
	ft_ft(&n);
	return (0);
}
