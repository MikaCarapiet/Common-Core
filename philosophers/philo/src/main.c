/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:17:03 by mcarapie          #+#    #+#             */
/*   Updated: 2026/09/25 16:07:56 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_sim	sim;
	int		status;

	memset(&sim, 0, sizeof(sim));
	if (parse_args(argc, argv, &sim) != 0)
		return (1);
	if (initialize_simulation(&sim) != 0)
	{
		cleanup(&sim);
		return (1);
	}
	status = start_threads(&sim);
	if (status == 0)
		monitor_simulation(&sim);
	stop_simulation(&sim);
	join_threads(&sim);
	cleanup(&sim);
	return (status);
}
