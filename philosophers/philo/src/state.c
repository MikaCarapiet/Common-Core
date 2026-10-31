/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:17:03 by mcarapie          #+#    #+#             */
/*   Updated: 2026/09/25 16:07:56 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* TODO: Read the stop flag while holding state_lock. */
int	simulation_stopped(t_sim *sim)
{
	(void)sim;
	return (0);
}

/* TODO: Set the stop flag while holding state_lock. */
void	stop_simulation(t_sim *sim)
{
	(void)sim;
}

/* TODO: Serialize status output and respect the simulation stop state. */
void	print_status(t_philo *philo, const char *status)
{
	(void)philo;
	(void)status;
}
