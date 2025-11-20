/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:43:58 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/24 17:09:04 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		ft_printf("\n");
		i++;
	}
}

void	print_list(int len, long *list)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%ld\n", list[i]);
		i++;
	}
}

void	print_node_a(t_node *node)
{
	ft_printf("D:%d\n", node->index);
}

void	print_node_b(t_node *node)
{
	ft_printf("I:%d, T_P:%d, P:%d, C_A:%d, C_B:%d, T_C:%d\n", node->index,
		node->target_pos, node->pos, node->cost_a,
		node->cost_b, node->total_cost);
}

void	lstiter(t_node *lst, void (f)(t_node *))
{
	t_node	*temp;

	temp = lst;
	if (!lst)
		return ;
	while (1)
	{
		f(temp);
		temp = temp->next;
		if (temp == lst)
			break ;
	}
}
