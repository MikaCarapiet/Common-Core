/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:39:19 by mcarapie          #+#    #+#             */
/*   Updated: 2026/04/30 19:51:22 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_atoi(const char *strg)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((strg[i] >= 9 && strg[i] <= 13) || strg[i] == ' ')
		i++;
	if (strg[i] == '-')
	{
		sign *= -1;
		i += 1;
	}
	else if (strg[i] == '+')
		i += 1;
	while (strg[i] != '\0')
	{
		if (strg[i] >= '0' && strg[i] <= '9')
			res = res * 10 + (strg[i] - '0');
		else
			return (res * sign);
		i++;
	}
	return (res * sign);
}

void	ft_putnbr(int c)
{
	long	n;
	char	digit;

	n = c;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}
