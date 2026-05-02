/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:37:56 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/02 14:56:51 by mcarapie         ###   ########.fr       */
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
	int	signal_to_send;

	bit_index = 7;
	while (bit_index >= 0)
	{
		current_bit = ((unsigned char)c >> bit_index) & 1;
		signal_to_send = SIGUSR1;
		if (current_bit == 1)
			signal_to_send = SIGUSR2;
		if (kill(pid, signal_to_send) == -1)
		{
			write(2, "Error: failed to send signal\n", 29);
			exit(1);
		}
		usleep(500);
		bit_index--;
	}
}

int	is_valid_pid(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || !is_valid_pid(argv[1]))
	{
		write(2, "Error: invalid arguments\n", 26);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "Error: invalid PID\n", 20);
		return (1);
	}
	send_string(pid, argv[2]);
	return (0);
}
