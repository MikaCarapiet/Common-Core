/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:37:56 by mcarapie          #+#    #+#             */
/*   Updated: 2026/04/30 21:37:30 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _DEFAULT_SOURCE

#include "../include/minitalk.h"

void	send_string(int pid, char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		send_char(pid, c[i]);
		i++;
	}
	send_char(pid, '\0');
}

void	send_char(int pid, char c)
{
	int	bit_index;
	int	current_bit;

	bit_index = 7;
	while (bit_index >= 0)
	{
		current_bit = (c >> bit_index) & 1;
		if (current_bit == 0)
			kill(pid, SIGUSR1);
		else if (current_bit == 1)
			kill(pid, SIGUSR2);
		usleep(300);
		bit_index--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		if (!is_valid_pid(argv[1]))
		{
			write(2, "Error: invalid PID\n", 19);
			return (1);
		}
		pid = ft_atoi(argv[1]);
		send_string(pid, argv[2]);
	}
	else
		write(2, "Please enter in this format: ./client <PID> \"message\"\n",
			55);
	return (0);
}
