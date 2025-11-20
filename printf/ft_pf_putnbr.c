/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:19:26 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/05/23 16:48:08 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_putnbr(long int num)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		count += ft_pf_putchar('0');
		return (count);
	}
	if (num < 0)
	{
		count += ft_pf_putchar('-');
		num = -num;
	}
	if (num >= 10)
	{
		count += ft_pf_putnbr(num / 10);
		count += ft_pf_putchar((num % 10) + '0');
	}
	else
		count += ft_pf_putchar(num + '0');
	return (count);
}
