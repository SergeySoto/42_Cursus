/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:43:35 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/24 17:02:58 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		target = find_smallest_node_b(stack_a);
	return (target);
}

static int	find_smallest_pos(t_node **stack_a)
{
	t_node	*aux;
	t_node	*lowest;
	int		pos;

	aux = *stack_a;
	lowest = *stack_a;
	pos = 0;
	while (aux)
	{
		if (lowest->index > aux->index)
		{
			pos = aux->pos;
			lowest = aux;
		}
		aux = aux->next;
	}
	return (pos);
}

void	set_target(t_stack **stack_a, t_stack **stack_b, t_node *lolita)
{
	t_node	*aux_a;
	t_node	*aux_b;

	aux_a = (*stack_a)->node_lst;
	aux_b = (*stack_b)->node_lst;
	while (1)
	{
		lolita = NULL;
		while (1)
		{
			if (aux_a->index > aux_b->index && (lolita == NULL
					|| lolita->index > aux_a->index))
				lolita = aux_a;
			aux_a = aux_a->next;
			if (aux_a == (*stack_a)->node_lst)
				break ;
		}
		if (lolita)
			aux_b->target_pos = lolita->pos;
		else
			aux_b->target_pos = find_smallest_pos(&(*stack_a)->node_lst);
		aux_b = aux_b->next;
		if (aux_b == (*stack_b)->node_lst)
			break ;
	}
}
