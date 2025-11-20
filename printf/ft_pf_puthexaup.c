/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_puthexaup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:29:55 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/05/23 16:02:15 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_puthexaup(unsigned int p)
{
	int					count;
	char				*hexa;

	hexa = "0123456789ABCDEF";
	count = 0;
	if (p >= 16)
		count += ft_pf_puthexaup(p / 16);
	count += ft_pf_putchar(hexa[p % 16]);
	return (count);
}
