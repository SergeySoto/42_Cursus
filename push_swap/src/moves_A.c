/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_A.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:32:07 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/03 19:10:27 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack	**stack_a)
{
	if (!*stack_a || (*stack_a)->len < 2)
		return ;
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	if (!*stack_b)
		return ;
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}
