/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:37:06 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/14 13:08:57 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printunsignedint(unsigned int n, int *count)
{
	long	nbr;

	nbr = n;
	if (nbr >= 10)
	{
		ft_printunsignedint(nbr / 10, count);
		ft_printchar((nbr % 10) + '0', count);
	}
	else
		ft_printchar(nbr + '0', count);
}

void	ft_printhexaupper(unsigned int n, int *count)
{
	long	nbr;
	char	*hexa;

	hexa = "0123456789ABCDEF";
	nbr = n;
	if (nbr >= 16)
	{
		ft_printhexaupper(nbr / 16, count);
		ft_printchar(hexa[nbr % 16], count);
	}
	else
		ft_printchar(hexa[nbr], count);
}

void	ft_printhexalower(unsigned int n, int *count)
{
	long	nbr;
	char	*hexa;

	hexa = "0123456789abcdef";
	nbr = n;
	if (nbr >= 16)
	{
		ft_printhexalower(nbr / 16, count);
		ft_printchar(hexa[nbr % 16], count);
	}
	else
		ft_printchar(hexa[nbr], count);
}

void	ft_printhexapointer(unsigned long n, int *count)
{
	unsigned long	nbr;
	char			*hexa;

	hexa = "0123456789abcdef";
	nbr = n;
	if (nbr >= 16)
	{
		ft_printhexapointer(nbr / 16, count);
		ft_printchar(hexa[nbr % 16], count);
	}
	else
		ft_printchar(hexa[nbr], count);
}

void	ft_printpointer(void *ptr, int *count)
{
	unsigned long	address;
	char			*hexa;

	hexa = "0123456789abcdef";
	address = (unsigned long)ptr;
	if (ptr == 0)
	{
		ft_printstr("(nil)", count);
	}
	else
	{
		ft_printstr("0x", count);
		ft_printhexapointer(address, count);
	}
}
