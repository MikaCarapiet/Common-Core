/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:17:03 by mcarapie          #+#    #+#             */
/*   Updated: 2026/11/01 21:56:24 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think(t_philo *philo)
{
	t_sim		*sim;
	long long	t;

	sim = philo->sim;
	print_status(philo, "is thinking");
	t = sim->time_to_eat - sim->time_to_sleep;
	if (sim->number_of_philosophers % 2)
		t = sim->time_to_eat * 2 - sim->time_to_sleep;
	if (t > 0)
		sleep_ms(sim, t);
}

static void	eat(t_philo *philo)
{
	t_sim	*sim;

	sim = philo->sim;
	pthread_mutex_lock(&sim->forks[philo->left_fork]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&sim->forks[philo->right_fork]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&sim->state_lock);
	philo->last_meal = get_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&sim->state_lock);
	print_status(philo, "is eating");
	sleep_ms(sim, sim->time_to_eat);
	pthread_mutex_unlock(&sim->forks[philo->left_fork]);
	pthread_mutex_unlock(&sim->forks[philo->right_fork]);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->sim->number_of_philosophers == 1)
	{
		pthread_mutex_lock(&philo->sim->forks[philo->left_fork]);
		print_status(philo, "has taken a fork");
		sleep_ms(philo->sim, philo->sim->time_to_die);
		pthread_mutex_unlock(&philo->sim->forks[philo->left_fork]);
		return (NULL);
	}
	if (philo->position % 2 == 0)
		sleep_ms(philo->sim, philo->sim->time_to_eat / 2);
	while (!simulation_stopped(philo->sim))
	{
		eat(philo);
		print_status(philo, "is sleeping");
		sleep_ms(philo->sim, philo->sim->time_to_sleep);
		think(philo);
	}
	return (NULL);
}
