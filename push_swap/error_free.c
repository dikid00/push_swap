/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikid00 <dikid00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:08:03 by dikid00           #+#    #+#             */
/*   Updated: 2023/08/12 09:05:01 by dikid00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **av)
{
	int	i;

	i = -1;
	if (NULL == av || NULL == *av)
		return ;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack_node **a, char **av, bool ac_2)
{
	free_stack(a);
	if (ac_2)
		free_matrix(av);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *s_nb)
{
	if (!(*s_nb == '+'
			|| *s_nb == '-'
			|| (*s_nb >= '0' && *s_nb <= '9')))
		return (1);
	if ((*s_nb == '+'
			|| *s_nb == '-')
		&& !(s_nb[1] >= '0' && s_nb[1] <= '9'))
		return (1);
	while (*++s_nb)
		if (!(*s_nb >= '0' && *s_nb <= '9'))
			return (1);
	return (0);
}	

int	error_rep(t_stack_node *a, int nb)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == nb)
			return (1);
		a = a->next;
	}
	return (0);
}
