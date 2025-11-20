/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:20:40 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/23 18:00:59 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_pos(t_node *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack;
	while (1)
	{
		temp->pos = i;
		temp = temp->next;
		if (temp == stack)
			break ;
		i++;
	}
}

void	set_index(t_stack **stack)
{
	t_node	*smallest;
	int		i;

	i = 1;
	while (i <= (*stack)->len)
	{
		smallest = find_smallest_node(stack);
		if (smallest)
			smallest->index = i;
		i++;
	}
}

t_node	*cheapest(t_stack **stack)
{
	t_node	*cheapest;
	t_node	*current;

	current = (*stack)->node_lst;
	cheapest = current;
	while (1)
	{
		if (current->total_cost < cheapest->total_cost)
			cheapest = current;
		current = current->next;
		if (current == (*stack)->node_lst)
			break ;
	}
	return (cheapest);
}

int	node_size(t_node **stack)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = (*stack);
	while (1)
	{
		i++;
		aux = aux->next;
		if ((*stack) == aux)
			break ;
	}
	return (i);
}
