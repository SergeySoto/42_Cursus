/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:02:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/24 14:09:31 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_both_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a)
		free_stack((*stack_a));
	if (stack_b)
		free_stack((*stack_b));
	ft_putstr_fd("Error\n", 2);
	exit(2);
}

void	check_moves(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		pa_bonus(stack_b, stack_a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb_bonus(stack_a, stack_b);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		sa_bonus(stack_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb_bonus(stack_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss_bonus(stack_a, stack_b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra_bonus(stack_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb_bonus(stack_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr_bonus(stack_a, stack_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra_bonus(stack_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb_bonus(stack_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr_bonus(stack_a, stack_b);
	else
		free_both_stack(stack_a, stack_b);
}

int	node_size(t_node **stack)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = (*stack);
	while (1)
	{
		i++;
		aux = aux->next;
		if ((*stack) == aux)
			break ;
	}
	return (i);
}

int	stack_is_sorted(t_stack **stack)
{
	t_node	*aux;
	int		len;
	int		i;

	aux = (*stack)->node_lst;
	len = node_size(&(*stack)->node_lst);
	i = 0;
	while (i < len - 1)
	{
		if (aux->data > aux->next->data)
			return (0);
		aux = aux->next;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (argc == 1)
		return (0);
	create_stack(argc, argv, &stack_a, &stack_b);
	line = get_next_line(0);
	while (line != NULL)
	{
		check_moves(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (stack_is_sorted(&stack_a) == 1 && stack_b->node_lst == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(stack_a);
	free_stack(stack_b);
}
