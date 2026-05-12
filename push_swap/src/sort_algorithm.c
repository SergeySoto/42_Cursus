/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:37:19 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/05 16:02:34 by ssoto-su         ###   ########.fr       */
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

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	mid;
	int	len;
	int	pushed;

	pushed = 0;
	i = 0;
	mid = ((*stack_a)->len / 2);
	len = (*stack_a)->len;
	while (pushed < mid && i < len)
	{
		if ((*stack_a)->node_lst->index < mid)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while ((*stack_a)->len > 3)
		pb(stack_a, stack_b);
	set_target(stack_a, stack_b);
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	sort_numbers(stack_a, stack_b);
}
