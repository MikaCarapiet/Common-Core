/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:17:19 by mcarapie          #+#    #+#             */
/*   Updated: 2026/04/29 18:47:01 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_over_int(long res, int sign)
{
	if (sign == 1 && res > INT_MAX)
		return (1);
	if (sign == -1 && -(res) < INT_MIN)
		return (1);
	return (0);
}
