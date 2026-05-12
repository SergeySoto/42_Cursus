/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:10:28 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/05 17:33:30 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(long *list, int len)
{
	int	i;

	i = 0;
	while (i + 1 < len)
	{
		if (list[i] > list[i + 1])
			return (0);
		i++;
	}
	return (1);
}

long	*parse_input(int argc, char **argv, int *len)
{
	char	**arr;
	long	*list;

	arr = get_input(argc, argv);
	if (!arr)
		return (0);
	list = parse_array(arr, len);
	if (!list)
		return (0);
	if (is_sorted(list, *len))
	{
		free_array(arr);
		free_long(list);
		exit(0);
	}
	if (!parse_list(list, len))
	{
		free_long(list);
		free_array(arr);
		printf_error();
		return (0);
	}
	free_array(arr);
	return (list);
}

void	create_stack(int argc, char **argv, t_stack **stack_a,
	t_stack **stack_b)
{
	int		len;
	long	*list;

	list = parse_input(argc, argv, &len);
	if (!list)
		return ;
	(*stack_a) = create_node_list(&len, list);
	(*stack_b) = malloc(sizeof(t_stack));
	(*stack_b)->node_lst = NULL;
	(*stack_b)->len = 0;
	list_to_circle(stack_a);
	free_long(list);
}

void	sort_numbers(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->len == 2)
		sort_two(stack_a);
	else if ((*stack_a)->len == 3)
		sort_three(stack_a);
	else
		sort_all(stack_a, stack_b);
}
