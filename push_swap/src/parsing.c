/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:01:38 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/23 16:39:37 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_number_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_int_in_range(long num)
{
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	has_duplicates(int *size, long *num_list)
{
	int	i;
	int	j;

	i = 0;
	while (i < *size)
	{
		j = i + 1;
		while (j < *size)
		{
			if (num_list[i] == num_list[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long	*parse_array(char **array, int *len)
{
	int		i;
	long	*num_list;

	if (!array || !len)
		return (NULL);
	*len = len_array(array);
	i = 0;
	num_list = (long *)malloc(*len * sizeof(long));
	if (!num_list)
		return (NULL);
	while (i < *len)
	{
		if (!is_number_valid(array[i]))
		{
			free_long(num_list);
			free_array(array);
			printf_error();
			return (0);
		}
		num_list[i] = ft_atol(array[i]);
		i++;
	}
	return (num_list);
}

int	parse_list(long	*num_list, int *len)
{
	int	i;

	i = 0;
	while (i < *len)
	{
		if (!is_int_in_range(num_list[i]))
			return (0);
		i++;
	}
	if (has_duplicates(len, num_list))
		return (0);
	return (1);
}
