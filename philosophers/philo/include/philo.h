/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:17:34 by mcarapie          #+#    #+#             */
/*   Updated: 2026/10/31 19:55:43 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_sim
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long long		start_time;
	int				stop;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	state_lock;
	pthread_mutex_t	print_lock;
	int				forks_ready;
	int				locks_ready;
	int				threads_started;
}					t_sim;

typedef struct s_philo
{
	int				position;
	long long		last_meal;
	int				meals_eaten;
	int				left_fork;
	int				right_fork;
	pthread_t		thread;
	t_sim			*sim;
}					t_philo;

int					parse_args(int argc, char **argv, t_sim *sim);
int					initialize_simulation(t_sim *sim);
int					start_threads(t_sim *sim);
void				join_threads(t_sim *sim);
void				*routine(void *arg);
void				monitor_simulation(t_sim *sim);
long long			get_time_ms(void);
void				sleep_ms(t_sim *sim, long long duration);
int					simulation_stopped(t_sim *sim);
void				stop_simulation(t_sim *sim);
void				print_status(t_philo *philo, const char *status);
void				cleanup(t_sim *sim);

#endif
