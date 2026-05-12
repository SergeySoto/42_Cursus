/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:17:58 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/05 17:16:58 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <limits.h>
# include <unistd.h>

typedef struct t_node
{
	int				data;
	int				target;
	int				index;
	int				pos;
	int				cost;
	struct t_node	*prev;
	struct t_node	*next;
}					t_node;

typedef struct t_stack
{
	struct t_node	*node_lst;
	int				len;
}					t_stack;

//Creating nodes and stacks functions
t_node	*ft_newnode(int data, int position);
void	add_node_back(t_node **lst, t_node *new);
t_node	*ft_last_node(t_node *node);
t_stack	*create_node_list(int *len, long *list);
void	list_to_circle(t_stack **head);
void	create_stack(int argc, char **argv, t_stack **stack_a,
			t_stack **stack_b);
//Utils functions
void	lstiter(t_node *lst, void (f)(t_node *));
long	ft_atol(char *str);
int		len_array(char **array);
//Node utils functions
void	set_pos(t_node *stack);
void	set_index(t_stack **stack);
t_node	*find_smallest_node(t_stack **stack);
t_node	*find_target(t_stack **stack_a, t_node *node_b);
void	set_target(t_stack **stack_a, t_stack **stack_b);
//Moves or actions functions
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	if_dest(t_node *first, t_stack **dest);
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	rotate(t_stack **stack_a);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	reverse_rotate(t_stack **node);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
//Sorting functions
void	sort_numbers(t_stack **stack_a, t_stack **stack_b);
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_all(t_stack **stack_a, t_stack **stack_b);
//Prints functions
void	printf_error(void);
void	print_array(char **argv);
void	print_list(int len, long *list);
void	print_node(t_node *node);
//Free memory functions
void	free_array(char **str);
void	free_str(char *str);
void	free_long(long *str);
void	free_stack(t_stack *node);
//Parsing functions
long	*parse_input(int argc, char **argv, int *len);
int		has_duplicates(int *size, long *num_list);
int		is_int_in_range(long num);
int		is_number_valid(char *str);
char	*join_args(int argc, char **argv, char *initial_str);
char	**get_input(int argc, char **argv);
int		only_space(char *argv);
long	*parse_array(char **array, int *len);
int		parse_list(long	*num_list, int *len);
char	**get_input(int argc, char **argv);
int		is_sorted(long *list, int len);
#endif
