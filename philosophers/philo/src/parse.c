/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:17:03 by mcarapie          #+#    #+#             */
/*   Updated: 2026/10/31 16:58:26 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Digits only (is_valid checks that first). Returns 1 above INT_MAX. */
static int	ft_atol(const char *strg, long *res)
{
	int	i;

	*res = 0;
	i = 0;
	while (strg[i] >= '0' && strg[i] <= '9')
	{
		*res = *res * 10 + (strg[i] - '0');
		if (*res > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

/* Stores a strictly positive int in *out, or returns 1 on error. */
static int	read_arg(const char *s, int *out)
{
	long	value;

	if (ft_atol(s, &value) || value <= 0)
		return (1);
	*out = (int)value;
	return (0);
}

static int	is_valid(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		if (!argv[j] || argv[j][0] == '\0')
			return (0);
		while (argv[j][i])
		{
			if (argv[j][i] > '9' || argv[j][i] < '0')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_sim *sim)
{
	if (argc != 5 && argc != 6)
	{
		write(2, "Error: expected 4 or 5 arguments\n", 33);
		return (1);
	}
	sim->number_of_times_each_philosopher_must_eat = -1;
	if (!is_valid(argc, argv)
		|| read_arg(argv[1], &sim->number_of_philosophers)
		|| read_arg(argv[2], &sim->time_to_die)
		|| read_arg(argv[3], &sim->time_to_eat)
		|| read_arg(argv[4], &sim->time_to_sleep)
		|| (argc == 6 && read_arg(argv[5],
				&sim->number_of_times_each_philosopher_must_eat)))
	{
		write(2, "Error: arguments must be positive integers\n", 43);
		return (1);
	}
	return (0);
}
