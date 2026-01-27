/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:17:22 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/27 10:22:44 by mcarapie         ###   ########.fr       */
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

long	*parse_arg(int argc, char **argv, int *index)
{
	long	*list;
	int		size;

	list = NULL;
	size = 1;
	*index = 0;
	list = malloc((argc - 1) * sizeof(long));
	if (list == NULL)
		return (NULL);
	while (size < argc)
	{
		list[*index] = ft_strtol(argv[size]);
		if ((list[*index] > INT_MAX) || (list[*index] < INT_MIN))
		{
			free(list);
			return (NULL);
		}
		*index += 1;
		size += 1;
	}
	return (list);
}

long	*check_duplicate(long *list, int *size)
{
	int	i;
	int	j;
	int	*unique_list;

	i = 0;
	unique_list = malloc(*size * sizeof(long));
	if (!*list || !unique_list)
		return (NULL);
	while (i < *size)
	{
		j = 0;
		while (j < i)
		{
			if (unique_list[j] == list[i])
			{
				free(unique_list);
				return (NULL);
			}
			j++;
		}
		unique_list[i] = list[i];
		i++;
	}
	free(unique_list);
	return (list);
}

int	validate_arg(int argc, char **argv, int *size, long **list)
{
	*list = parse_arg(argc, argv, size);
	if (!*list)
		return (print_error("Error\n"));
	*list = check_duplicate(*list, size);
	if (!*list)
		return (print_error("Error\n"));
	return (0);
}

int	print_error(char *str)
{
	printf("%s", str);
	return (1);
}
