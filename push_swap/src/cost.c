/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:07:35 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/23 18:05:50 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calc_cost(t_node **stack, int pos)
{
	int	ret;
	int	size;

	size = node_size(stack);
	ret = 0;
	if (pos > node_size(stack) / 2)
		ret = (-1) * (size - pos);
	else
		ret = pos;
	return (ret);
}

void	set_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*aux_a;
	t_node	*aux_b;

	aux_a = (*stack_a)->node_lst;
	aux_b = (*stack_b)->node_lst;
	while (1)
	{
		aux_b->cost_a = calc_cost(&aux_a, aux_b->target_pos);
		aux_b->cost_b = calc_cost(&aux_b, aux_b->pos);
		aux_b = aux_b->next;
		if (aux_b == (*stack_b)->node_lst)
			break ;
	}
}

void	set_total_cost(t_stack **stack_src, t_stack **stack_dst)
{
	t_node	*aux_b;
	t_node	*aux_a;

	aux_b = (*stack_src)->node_lst;
	aux_a = (*stack_dst)->node_lst;
	while (1)
	{
		aux_b->total_cost = ft_abs(aux_b->cost_a) + ft_abs(aux_b->cost_b);
		aux_b = aux_b->next;
		if (aux_b == (*stack_src)->node_lst)
			break ;
	}
}
