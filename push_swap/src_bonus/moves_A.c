/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_A.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:32:07 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/23 20:11:17 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa_bonus(t_stack	**stack_a)
{
	if (!*stack_a || (*stack_a)->len < 2)
		return ;
	swap(stack_a);
}

void	pa_bonus(t_stack **stack_b, t_stack **stack_a)
{
	if (!*stack_b)
		return ;
	push(stack_b, stack_a);
}

void	ra_bonus(t_stack **stack_a)
{
	rotate(stack_a);
}

void	rra_bonus(t_stack **stack_a)
{
	reverse_rotate(stack_a);
}
