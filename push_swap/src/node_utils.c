/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:20:40 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/05 16:13:28 by ssoto-su         ###   ########.fr       */
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

	i = 0;
	while (i < (*stack)->len)
	{
		smallest = find_smallest_node(stack);
		if (smallest)
			smallest->index = i;
		i++;
	}
}

t_node	*find_target(t_stack **stack_a, t_node *node_b)
{
	int		i;
	int		min_diff;
	t_node	*target;
	t_node	*current;
	int		diff;

	diff = 0;
	min_diff = INT_MAX;
	target = NULL;
	i = 0;
	current = (*stack_a)->node_lst;
	while (i < (*stack_a)->len)
	{
		diff = current->data - node_b->data;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			target = current;
		}
		i++;
		current = current->next;
	}
	if (!target)
		target = find_smallest_node(stack_a);
	return (target);
}

void	set_target(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_node	*target_node;
	t_node	*aux;

	aux = (*stack_b)->node_lst;
	i = 0;
	while (i < (*stack_b)->len)
	{
		target_node = find_target(stack_a, aux);
		(*aux).target = target_node->data;
		i++;
		aux = aux->next;
	}
}
