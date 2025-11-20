/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:08:51 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/11/17 12:48:28 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_putendl_fd(char *s, int fd);
int		ft_strcmp(const char *s1, const char *s2);
int		select_mode(char **argv);

int	main(int argc, char **argv)
{
	char	*message;

	message = argv[2];
	if (argc != 3)
	{
		ft_putendl_fd("Error: Incorrect number of arguments", 1);
		return (1);
	}
	if (ft_strcmp("encode", argv[1]) == 0
		|| ft_strcmp("decode", argv[1]) == 0)
	{
		if (select_mode(argv) != 0)
		{
			ft_putendl_fd("Error", 1);
			return (1);
		}
	}
	else
	{
		ft_putendl_fd("Error", 1);
		return (1);
	}
	return (0);
}
