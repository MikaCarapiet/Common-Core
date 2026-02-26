/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:17:22 by mcarapie          #+#    #+#             */
/*   Updated: 2026/02/26 11:56:14 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

long	ft_strtol(const char *strg)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	if ((strg[i] < '0' || strg[i] > '9') && strg[i] != '-')
		return (LONG_MAX);
	else if (strg[i] == '-')
	{
		sign *= -1;
		i += 1;
	}
	while (strg[i] != '\0')
	{
		if (strg[i] >= '0' && strg[i] <= '9')
			res = res * 10 + (strg[i] - '0');
		else
			return (LONG_MAX);
		i++;
	}
	return (res * sign);
}

long	*parse_arg(int argc, char **argv)
{
	long	*list;
	int		i;

	list = NULL;
	list = malloc((argc - 1) * sizeof(long));
	if (list == NULL)
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		list[i - 1] = ft_strtol(argv[i]);
		if ((list[i - 1] > INT_MAX) || (list[i - 1] < INT_MIN))
			return (free(list), NULL);
	}
	return (list);
}

long	*check_duplicate(long *list, int size)
{
	int	i;
	int	j;
	int	*unique_list;

	i = 0;
	unique_list = malloc(size * sizeof(long));
	if (!*list || !unique_list)
		return (NULL);
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (unique_list[j] == list[i])
			{
				free(list);
				return (free(unique_list), NULL);
			}
			j++;
		}
		unique_list[i] = list[i];
		i++;
	}
	return (free(unique_list), list);
}

int	validate_arg(int argc, char **argv, long **list)
{
	*list = parse_arg(argc, argv);
	if (!*list)
		return (print_error("Error\n"));
	*list = check_duplicate(*list, (argc - 1));
	if (!*list)
		return (print_error("Error\n"));
	return (0);
}

int	print_error(char *str)
{
	printf("%s", str);
	return (1);
}
