/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:36:18 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/24 13:44:30 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss_bonus(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->len < 2 || (*stack_b)->len < 2)
		return ;
	swap(stack_a);
	swap(stack_b);
}

void	rr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a)->node_lst && !(*stack_b)->node_lst)
		return ;
	rotate(stack_a);
	rotate(stack_b);
}

void	rrr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a)->node_lst && !(*stack_b)->node_lst)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
