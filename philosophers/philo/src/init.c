/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:17:03 by mcarapie          #+#    #+#             */
/*   Updated: 2026/10/31 20:47:21 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutexes(t_sim *sim)
{
	int	i;

	if (pthread_mutex_init(&sim->state_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&sim->print_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&sim->state_lock);
		return (1);
	}
	sim->locks_ready = 1;
	i = 0;
	while (i < sim->number_of_philosophers)
	{
		if (pthread_mutex_init(&sim->forks[i], NULL) != 0)
			return (1);
		sim->forks_ready++;
		i++;
	}
	return (0);
}

static void	init_philos(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->number_of_philosophers)
	{
		sim->philos[i].position = i + 1;
		sim->philos[i].meals_eaten = 0;
		sim->philos[i].left_fork = i;
		sim->philos[i].right_fork = (i + 1) % sim->number_of_philosophers;
		sim->philos[i].sim = sim;
		i++;
	}
}

int	initialize_simulation(t_sim *sim)
{
	sim->philos = malloc(sizeof(t_philo) * sim->number_of_philosophers);
	if (!sim->philos)
		return (1);
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->number_of_philosophers);
	if (!sim->forks)
		return (1);
	if (init_mutexes(sim))
		return (1);
	init_philos(sim);
	return (0);
}
