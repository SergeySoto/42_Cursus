/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:09:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/19 20:08:25 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

int	len_array(char **array)
{
	int	len;

	len = 0;
	if (!array)
		return (0);
	while (array[len] != NULL)
		len++;
	return (len);
}

long	ft_atol(char *str)
{
	int		i;
	int		symbol;
	long	res;

	if (!str)
		return (0);
	res = 0;
	symbol = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			symbol *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
		if (res * symbol < INT_MIN || res * symbol > INT_MAX)
			return (res);
	}
	return (res * symbol);
}

t_node	*find_smallest_node(t_stack **stack)
{
	t_node	*smallest;
	t_node	*current;
	int		i;

	smallest = NULL;
	current = (*stack)->node_lst;
	i = 0;
	while (i < (*stack)->len)
	{
		if (current->index == -1)
		{
			smallest = current;
			break ;
		}
		current = current->next;
		i++;
	}
	while (i < (*stack)->len)
	{
		if (current->data < smallest->data && current->index == -1)
			smallest = current;
		current = current->next;
		i++;
	}
	return (smallest);
}

t_node	*find_biggest_node(t_stack **stack)
{
	t_node	*biggest;
	t_node	*current;
	int		i;

	current = (*stack)->node_lst;
	biggest = current;
	i = 0;
	while (i < (*stack)->len)
	{
		if (current->data > biggest->data)
			biggest = current;
		current = current->next;
		i++;
	}
	return (biggest);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
