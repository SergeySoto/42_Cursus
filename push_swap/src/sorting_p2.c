/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:33:12 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/24 16:55:07 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*cheap;

	while ((*stack_b)->len > 0)
	{
		set_pos((*stack_a)->node_lst);
		set_pos((*stack_b)->node_lst);
		set_target(stack_a, stack_b, NULL);
		set_cost(stack_a, stack_b);
		set_total_cost(stack_b, stack_a);
		cheap = cheapest(stack_b);
		if (cheap)
		{
			cheapest_path(stack_b, stack_a, cheap);
		}
		pa(stack_b, stack_a);
	}
}

void	put_small_top(t_stack **stack_a)
{
	t_node	*current;
	t_node	*smallest;

	current = (*stack_a)->node_lst;
	smallest = find_smallest_node_b(stack_a);
	while (smallest->pos > 0)
	{
		if (smallest->pos >= (*stack_a)->len / 2)
			rra(stack_a);
		else if (smallest->pos < (*stack_a)->len / 2)
			ra(stack_a);
		if (smallest == (*stack_a)->node_lst)
			break ;
		current = current->next;
	}
}
