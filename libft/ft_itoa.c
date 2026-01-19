/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:16:16 by mcarapie          #+#    #+#             */
/*   Updated: 2025/12/01 16:10:06 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert(char *str, int len, long sign, int n)
{
	int	i;

	i = len;
	while (len > 0)
	{
		str[len - 1] = (sign % 10) + '0';
		sign /= 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	str[i] = '\0';
	return (str);
}

static long	is_negative(int *len, int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		*len += 1;
		nb = nb * -1;
		return (nb);
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*str;
	long	sign;

	len = 0;
	sign = is_negative(&len, n);
	nb = sign;
	while (nb >= 0)
	{
		len += 1;
		nb /= 10;
		if (nb == 0)
			break ;
	}
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = convert(str, len, sign, n);
	return (str);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_itoa(INT_MAX);
// 	printf("%s", str);
// }
