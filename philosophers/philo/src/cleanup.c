/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:17:03 by mcarapie          #+#    #+#             */
/*   Updated: 2026/10/31 21:07:13 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->forks_ready)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		i++;
	}
	if (sim->locks_ready)
	{
		pthread_mutex_destroy(&sim->state_lock);
		pthread_mutex_destroy(&sim->print_lock);
	}
	free(sim->philos);
	free(sim->forks);
}
