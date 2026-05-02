/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:37:52 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/02 14:44:17 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handle_signal(int signal)
{
	static unsigned char	current_char;
	static int				bit_count;

	current_char = current_char << 1;
	if (signal == SIGUSR2)
		current_char = current_char | 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &current_char, 1);
		current_char = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	action.sa_handler = handle_signal;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
