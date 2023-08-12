/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikid00 <dikid00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:29:09 by dikid00           #+#    #+#             */
/*   Updated: 2023/08/12 09:01:25 by dikid00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_wrds(char *str, char sep)
{
	int		count;
	bool	in_wd;

	count = 0;
	while (*str)
	{
		in_wd = false;
		while (*str == sep)
			++str;
		while (*str != sep && *str)
		{
			if (!in_wd)
			{
				++count;
				in_wd = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_wrd(char *str, char sep)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == sep)
		++cursor;
	while ((str[cursor + len] != sep) && str[cursor + len])
		++len;
	next_str = malloc(sizeof(char) * (size_t)(len + 1));
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != sep) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char sep)
{
	int		wrd_nb;
	char	**str_split;
	int		i;

	i = 0;
	wrd_nb = count_wrds(str, sep);
	if (!wrd_nb)
		exit(1);
	str_split = malloc(sizeof(char *) * (size_t)(wrd_nb + 2));
	if (NULL == str_split)
		return (NULL);
	while (wrd_nb-- >= 0)
	{
		if (i == 0)
		{
			str_split[i] = malloc(sizeof(char));
			if (NULL == str_split[i])
				return (NULL);
			str_split[i++][0] = '\0';
			continue ;
		}
		str_split[i++] = get_next_wrd(str, sep);
	}
	str_split[i] = NULL;
	return (str_split);
}
