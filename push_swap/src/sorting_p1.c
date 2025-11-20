/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_p1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:37:19 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/24 16:38:51 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->len == 2)
	{
		if ((*stack)->node_lst->data > (*stack)->node_lst->next->data)
			sa(stack);
	}
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	if ((*stack)->len == 3)
	{
		a = (*stack)->node_lst->data;
		b = (*stack)->node_lst->next->data;
		c = (*stack)->node_lst->next->next->data;
		if (a < b && b < c)
			return ;
		if (a > b && a > c)
			ra(stack);
		else if (b > a && b > c)
			rra(stack);
		a = (*stack)->node_lst->data;
		b = (*stack)->node_lst->next->data;
		if (a > b)
			sa(stack);
	}
}

void	push_b_p2(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*current;
	int		i;
	int		size;

	current = (*stack_a)->node_lst;
	size = stack_size(stack_a);
	i = size;
	while (i)
	{
		if ((*stack_a)->node_lst->index < (size / 2) + (size % 2))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i--;
	}
	while (1)
	{
		if ((*stack_a)->node_lst->index < size - 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		if (stack_size(stack_a) == 3)
			break ;
	}
	sort_three(stack_a);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push_b_p2(stack_a, stack_b);
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	push_a(stack_a, stack_b);
	put_small_top(stack_a);
}
