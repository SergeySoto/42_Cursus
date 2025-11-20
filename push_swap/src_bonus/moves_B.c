/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_B.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:34:00 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/23 20:12:45 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb_bonus(t_stack **stack_b)
{
	if (!*stack_b || (*stack_b)->len < 2)
		return ;
	swap(stack_b);
}

void	pb_bonus(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a)
		return ;
	push(stack_a, stack_b);
}

void	rb_bonus(t_stack **stack_b)
{
	rotate(stack_b);
}

void	rrb_bonus(t_stack **stack_b)
{
	reverse_rotate(stack_b);
}
