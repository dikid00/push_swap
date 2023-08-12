/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikid00 <dikid00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:22:12 by dikid00           #+#    #+#             */
/*   Updated: 2023/08/12 08:57:54 by dikid00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_mid;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

// split.c
char			**ft_split(char *str, char sep);
// error_free.c
int				error_syntax(char *s_nb);
void			error_free(t_stack_node **a, char **av, bool ac_2);
int				error_rep(t_stack_node *a, int nb);
void			free_stack(t_stack_node **stack);
void			free_matrix(char **av);
// stack_init.c
void			stack_init(t_stack_node **a, char **av, bool ac_2);

// stack_utils.c
void			append_node(t_stack_node **stack, int nb);
t_stack_node	*find_last_node(t_stack_node *head);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
// swap_cmd.c
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
// rotate_cmd.c
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
// rrotate.c
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
// push_cmd.c
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);
// push_swap_cmd.c
void			push_swap(t_stack_node **a, t_stack_node **b);
void			finish_rotation(t_stack_node **s, t_stack_node *n, char c);
// push_swap_init.c
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			set_current_position(t_stack_node *stack);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);
// tiny_sort.c
void			tiny_sort(t_stack_node **a);
void			handle_five(t_stack_node **a, t_stack_node **b);
bool			stack_sorted(t_stack_node *stack);

#endif
