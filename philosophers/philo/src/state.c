/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:17:03 by mcarapie          #+#    #+#             */
/*   Updated: 2026/11/01 17:03:46 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation_stopped(t_sim *sim)
{
	int	stopped;

	pthread_mutex_lock(&sim->state_lock);
	stopped = sim->stop;
	pthread_mutex_unlock(&sim->state_lock);
	return (stopped);
}

void	stop_simulation(t_sim *sim)
{
	pthread_mutex_lock(&sim->state_lock);
	sim->stop = 1;
	pthread_mutex_unlock(&sim->state_lock);
}

void	print_status(t_philo *philo, const char *status)
{
	pthread_mutex_lock(&philo->sim->print_lock);
	if (!simulation_stopped(philo->sim))
		printf("%lld %d %s\n", get_time_ms() - philo->sim->start_time,
			philo->position, status);
	pthread_mutex_unlock(&philo->sim->print_lock);
}
