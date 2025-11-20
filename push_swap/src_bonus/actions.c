/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:08:45 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/24 13:46:43 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	t_node	*first;
	t_node	*second;

	if ((*stack)->len < 2)
		return ;
	else if ((*stack)->len >= 3)
	{
		first = (*stack)->node_lst;
		second = first->next;
		first->prev->next = second;
		second->next->prev = first;
		first->next = second->next;
		second->prev = first->prev;
		second->next = first;
		first->prev = second;
		(*stack)->node_lst = second;
	}
	else
		(*stack)->node_lst = (*stack)->node_lst->next;
}

void	if_dest(t_node *first, t_stack **dest)
{
	if ((*dest)->len == 0)
	{
		(*dest)->node_lst = first;
		first->next = first;
		first->prev = first;
	}
	else
	{
		first->next = (*dest)->node_lst;
		first->prev = (*dest)->node_lst->prev;
		(*dest)->node_lst->prev->next = first;
		(*dest)->node_lst->prev = first;
		(*dest)->node_lst = first;
	}
	(*dest)->len++;
}

void	push(t_stack **src, t_stack **dest)
{
	t_node	*first;

	if (!src || (*src)->len == 0)
		return ;
	first = (*src)->node_lst;
	if ((*src)->len == 1)
		(*src)->node_lst = NULL;
	else
	{
		(*src)->node_lst = first->next;
		first->prev->next = first->next;
		first->next->prev = first->prev;
	}
	(*src)->len--;
	if_dest(first, dest);
}

void	rotate(t_stack **node)
{
	if (!(*node)->node_lst || (*node)->len == 0)
		return ;
	(*node)->node_lst = (*node)->node_lst->next;
}

void	reverse_rotate(t_stack **node)
{
	if (!(*node)->node_lst || (*node)->len == 0)
		return ;
	(*node)->node_lst = (*node)->node_lst->prev;
}
