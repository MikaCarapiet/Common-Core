/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:17:03 by mcarapie          #+#    #+#             */
/*   Updated: 2026/11/01 22:53:34 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	all_ate(t_sim *sim)
{
	int	done;
	int	i;
	int	must_eat;

	must_eat = sim->number_of_times_each_philosopher_must_eat;
	if (must_eat == -1)
		return (0);
	done = 0;
	i = 0;
	pthread_mutex_lock(&sim->state_lock);
	while (i < sim->number_of_philosophers)
	{
		if (sim->philos[i].meals_eaten >= must_eat)
			done++;
		i++;
	}
	pthread_mutex_unlock(&sim->state_lock);
	return (done == sim->number_of_philosophers);
}

static int	check_death(t_sim *sim)
{
	int	i;
	int	is_dead;

	is_dead = 0;
	i = 0;
	while (i < sim->number_of_philosophers)
	{
		pthread_mutex_lock(&sim->state_lock);
		if (get_time_ms() - sim->philos[i].last_meal > sim->time_to_die)
			is_dead = 1;
		pthread_mutex_unlock(&sim->state_lock);
		if (is_dead == 1)
		{
			pthread_mutex_lock(&sim->print_lock);
			printf("%lld %d died\n", get_time_ms() - sim->start_time,
				sim->philos[i].position);
			stop_simulation(sim);
			pthread_mutex_unlock(&sim->print_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

void	monitor_simulation(t_sim *sim)
{
	while (1)
	{
		if (check_death(sim))
			return ;
		if (all_ate(sim))
		{
			stop_simulation(sim);
			return ;
		}
		usleep(500);
	}
}
