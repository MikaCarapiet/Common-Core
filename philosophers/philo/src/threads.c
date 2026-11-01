/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:17:03 by mcarapie          #+#    #+#             */
/*   Updated: 2026/11/01 18:57:04 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* TODO: Create threads and record how many started successfully. */
int	start_threads(t_sim *sim)
{
	int	i;

	sim->start_time = get_time_ms();
	i = 0;
	while (i < sim->number_of_philosophers)
	{
		sim->philos[i].last_meal = sim->start_time;
		if (pthread_create(&sim->philos[i].thread, NULL, routine,
				&sim->philos[i]))
			return (1);
		sim->threads_started++;
		i++;
	}
	return (0);
}

/* TODO: Join only the threads that were successfully created. */
void	join_threads(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->threads_started)
	{
		pthread_join(sim->philos[i].thread, NULL);
		i++;
	}
}
