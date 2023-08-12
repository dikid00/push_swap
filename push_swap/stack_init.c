/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikid00 <dikid00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:51:25 by dikid00           #+#    #+#             */
/*   Updated: 2023/08/12 09:55:28 by dikid00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long int	ft_atol(const char *str)
{
	long int	n;
	int			neg;
	int			i;

	n = 0;
	neg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			||str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] + '0');
		i++;
	}
	return (n * neg);
}

void	stack_init(t_stack_node **a, char **av, bool ac_2)
{
	long	nb;
	int		i;

	i = 0;
	while (av[i])
	{	
		if (error_syntax(av[i]))
			error_free(a, av, ac_2);
		nb = (int)ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error_free(a, av, ac_2);
		if (error_rep(*a, nb))
			error_free(a, av, ac_2);
		append_node(a, nb);
		++i;
	}
	if (ac_2)
		free_matrix(av);
}
