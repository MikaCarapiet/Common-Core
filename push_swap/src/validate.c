/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:17:22 by mcarapie          #+#    #+#             */
/*   Updated: 2026/04/29 18:26:50 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

int	ft_atol_checked(const char *str, long *out)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		res = res * 10 + (str[i++] - '0');
		if (is_over_int(res, sign))
			return (0);
	}
	*out = res * sign;
	return (1);
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
		if (!ft_atol_checked(argv[i], &list[i - 1]))
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
	if (!list || !unique_list)
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
		return (print_error());
	*list = check_duplicate(*list, (argc - 1));
	if (!*list)
		return (print_error());
	return (0);
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
