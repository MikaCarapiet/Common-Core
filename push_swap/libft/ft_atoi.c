/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:25:20 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/25 12:00:22 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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
// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	escape[] = {9, 10, 11, 12, 13, 0};
// 	int		result;

// 	result = ft_atoi("9");
// 	printf("%d", result);
// }
