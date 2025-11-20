/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:19:26 by msedeno-          #+#    #+#             */
/*   Updated: 2025/02/05 16:40:51 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

char	wletter(int y, int x, int col, int row)
{
	if ((row == 1 && col == 1) || (row == x && col == 1))
		return ('A');
	else if ((row == 1 && col == y) || (row == x && col == y))
		return ('C');
	else if ((row == 1 && col >= 1 && col < y) || (row > 1 && col == 1))
		return ('B');
	else if ((row > 1 && col == y) || (row == x && col < y))
		return ('B');
	else
		return (' ');
}

void	rush(int y, int x)
{
	int	column;
	int	row;

	column = 1;
	row = 1;
	while (row <= x)
	{
		while (column <= y)
		{
			ft_putchar(wletter(y, x, column, row));
			column++;
		}
		row++;
		column = 1;
		ft_putchar('\n');
	}
}
