/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:36:10 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/02/09 20:19:24 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	givemenum(int n)
{
	char	*l;

	l = "0123456789";
	write(1, l + n, 1);
}

void	func_write(int a, int b, int c)
{
	givemenum(a);
	givemenum(b);
	givemenum(c);
}

void	write_char(int a, int b, int c)
{
	if (a != 7 || b != 8 || c != 9)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				func_write(a, b, c);
				write_char(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
