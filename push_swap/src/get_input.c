/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:58:26 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/21 16:58:26 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*join_args(int argc, char **argv, char *initial_str)
{
	int		i;
	char	*joined_args;
	char	*temp;

	joined_args = initial_str;
	i = 2;
	while (i < argc)
	{
		temp = joined_args;
		joined_args = ft_strjoin(temp, " ");
		free(temp);
		temp = joined_args;
		joined_args = ft_strjoin(temp, argv[i]);
		free(temp);
		i++;
	}
	return (joined_args);
}

int	only_space(char *argv)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (argv[i])
	{
		if (argv[i] > 32)
			flag = 1;
		i++;
	}
	return (flag);
}

char	**get_input(int argc, char **argv)
{
	char	**num_array;
	char	*joined_args;

	num_array = NULL;
	if (argc == 1)
		return (NULL);
	if (only_space(&argv[1][0]))
	{
		joined_args = ft_strdup(argv[1]);
		if (argc > 2)
			joined_args = join_args(argc, argv, joined_args);
		num_array = ft_split(joined_args, ' ');
		free(joined_args);
	}
	else
		printf_error();
	return (num_array);
}
