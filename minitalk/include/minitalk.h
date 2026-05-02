/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:39:54 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/02 15:22:51 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 200809L
# define _DEFAULT_SOURCE

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putnbr(int c);
int		ft_atoi(const char *strg);
void	send_char(int pid, char c);
void	send_string(int pid, char *c);
int		is_valid_pid(char *str);
#endif