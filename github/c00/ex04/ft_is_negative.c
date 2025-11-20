/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:31:16 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/02/01 14:33:38 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n)
{
	char	lp;
	char	ln;

	lp = 'P';
	ln = 'N';
	if (n < 0)
	{
		write (1, &ln, 1);
	}
	else if (n > 0)
	{
		write (1, &lp, 1);
	}
	else
	{
		write (1, &lp, 1);
	}
}
