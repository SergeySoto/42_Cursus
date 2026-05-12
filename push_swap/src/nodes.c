/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:37:26 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/05 16:06:45 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_newnode(int data, int position)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->pos = position;
	node->prev = NULL;
	node->next = NULL;
	node->index = -1;
	node->target = -1;
	return (node);
}

t_node	*ft_last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	list_to_circle(t_stack **head)
{
	t_stack	*temp;
	t_node	*last;

	temp = (*head);
	last = ft_last_node((*head)->node_lst);
	last->next = temp->node_lst;
	temp->node_lst->prev = last;
}

void	add_node_back(t_node **list_head, t_node *new)
{
	t_node	*last;

	if (!new)
		return ;
	if (*list_head == NULL)
	{
		*list_head = new;
		return ;
	}
	last = ft_last_node(*list_head);
	last->next = new;
	new->prev = last;
}

t_stack	*create_node_list(int *len, long *list)
{
	t_node	*head;
	t_node	*new;
	t_stack	*stack_ptr;
	int		i;

	head = NULL;
	stack_ptr = malloc(sizeof(t_stack));
	i = 0;
	if (!stack_ptr)
		return (NULL);
	while (i < *len)
	{
		new = ft_newnode((int)*list, i);
		add_node_back(&head, new);
		i++;
		list++;
	}
	stack_ptr->node_lst = head;
	stack_ptr->len = *len;
	set_index(&stack_ptr);
	return (stack_ptr);
}
