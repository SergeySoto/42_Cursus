/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:32:21 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/02/10 18:13:47 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	giveme_num(int n1, int n2)
{
	char	ch_num;	

	ch_num = (n1 / 10) + '0';
	write(1, &ch_num, 1);
	ch_num = (n1 % 10) + '0';
	write(1, &ch_num, 1);
	write(1, " ", 1);
	ch_num = (n2 / 10) + '0';
	write(1, &ch_num, 1);
	ch_num = (n2 % 10) + '0';
	write(1, &ch_num, 1);
}

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;

	n1 = -1;
	while (n1++ < 98)
	{
		n2 = n1;
		while (n2++ < 99)
		{
			giveme_num(n1, n2);
			if (n1 < 98)
			{
				write(1, ", ", 2);
			}
		}
	}
}
