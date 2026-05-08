/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 00:00:00 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/07 00:00:00 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static int	count_tokens(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

int	count_values(int argc, char **argv)
{
	char	**tokens;
	int		i;
	int		count;
	int		total;

	i = 1;
	total = 0;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (-1);
		count = count_tokens(tokens);
		free_tokens(tokens);
		if (count == 0)
			return (-1);
		total += count;
		i++;
	}
	return (total);
}

int	fill_values(long *list, int argc, char **argv)
{
	char	**tokens;
	int		i;
	int		j;
	int		pos;

	i = 1;
	pos = 0;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (1);
		j = 0;
		while (tokens[j])
		{
			if (!ft_atol_checked(tokens[j], &list[pos]))
				return (free_tokens(tokens), 1);
			pos++;
			j++;
		}
		free_tokens(tokens);
		i++;
	}
	return (0);
}
