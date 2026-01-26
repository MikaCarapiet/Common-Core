/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:36:03 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/14 13:09:05 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = c;
	if (ch == '\0')
	{
		i = ft_strlen(str);
		return ((char *)str + i++);
	}
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

void	ft_printchar(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_printstr(char *s, int *count)
{
	if (s == NULL)
		ft_printstr("(null)", count);
	else
	{
		while (*s != '\0')
		{
			ft_printchar(*s, count);
			s++;
		}
	}
}

void	ft_printnbr(int n, int *count)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_printchar('-', count);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_printnbr(nbr / 10, count);
		ft_printchar((nbr % 10) + '0', count);
	}
	else
		ft_printchar(nbr + '0', count);
}
