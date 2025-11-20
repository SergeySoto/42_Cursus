/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:31:10 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/23 18:33:35 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	path_1(t_node **node)
{
	if ((*node)->cost_a > (*node)->cost_b)
		(*node)->total_cost = (*node)->cost_a;
	else
		(*node)->total_cost = (*node)->cost_b;
}

void	path_2(t_node **node)
{
	int	a;
	int	b;

	a = ft_abs((*node)->cost_a);
	b = ft_abs((*node)->target->cost_b);
	if (a > b)
		(*node)->total_cost = a;
	else
		(*node)->total_cost = b;
}

void	path_3(t_node **node)
{
	(*node)->total_cost = ft_abs((*node)->cost_a)
		+ ft_abs((*node)->target->cost_b);
}

void	path_4(t_node **node)
{
	(*node)->total_cost = ft_abs((*node)->cost_a)
		+ ft_abs((*node)->target->cost_b);
}

void	cheapest_path(t_stack **stack_b, t_stack **stack_a, t_node *cheapest)
{
	if (cheapest->cost_a < 0 && cheapest->cost_b < 0)
		path_2_move(stack_b, stack_a, cheapest);
	else if (cheapest->cost_a > 0 && cheapest->cost_b > 0)
		path_1_move(stack_b, stack_a, cheapest);
	else if (cheapest->cost_a < 0 || cheapest->cost_b < 0)
		path_3_move(stack_b, stack_a, cheapest);
	else if (cheapest->cost_a > 0 || cheapest->cost_b > 0)
		path_4_move(stack_b, stack_a, cheapest);
}
