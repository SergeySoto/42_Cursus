/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:21:06 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/23 18:35:47 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_size(t_stack **stack)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = (*stack)->node_lst;
	while (1)
	{
		i++;
		aux = aux->next;
		if ((*stack)->node_lst == aux)
			break ;
	}
	return (i);
}

t_node	*find_smallest_node_b(t_stack **stack)
{
	t_node	*smallest;
	t_node	*current;
	int		i;

	smallest = NULL;
	current = (*stack)->node_lst;
	i = 0;
	smallest = current;
	while (i < (*stack)->len)
	{
		if (current->data < smallest->data)
			smallest = current;
		current = current->next;
		i++;
	}
	return (smallest);
}
