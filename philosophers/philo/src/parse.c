/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:17:03 by mcarapie          #+#    #+#             */
/*   Updated: 2026/09/25 16:07:56 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *strg)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((strg[i] >= 9 && strg[i] <= 13) || strg[i] == ' ')
		i++;
	if (strg[i] == '-')
	{
		sign *= -1;
		i += 1;
	}
	else if (strg[i] == '+')
		i += 1;
	while (strg[i] != '\0')
	{
		if (strg[i] >= '0' && strg[i] <= '9')
			res = res * 10 + (strg[i] - '0');
		else
			return (res * sign);
		i++;
	}
	return (res * sign);
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
	if (!is_valid(argc, argv))
	{
		write(2, "Error: invalid numeric argument\n", 32);
		return (1);
	}
	sim->number_of_philosophers = ft_atoi(argv[1]);
	sim->time_to_die = ft_atoi(argv[2]);
	sim->time_to_eat = ft_atoi(argv[3]);
	sim->time_to_sleep = ft_atoi(argv[4]);
	sim->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
		sim->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	return (0);
}
