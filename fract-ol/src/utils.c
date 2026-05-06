/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:57:42 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/06 16:45:17 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/libft.h"

void	skip_space(const char *str, int *i)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		*i += 1;
}

int	get_sign(const char *str, int *i)
{
	if (str[*i] == '-')
	{
		*i += 1;
		return (-1);
	}
	else if (str[*i] == '+')
		*i += 1;
	return (1);
}

double	ft_atod(const char *str)
{
	double	res;
	int		i;
	int		sign;
	double	divisor;

	divisor = 10.0;
	res = 0.0;
	i = 0;
	sign = 1;
	skip_space(str, &i);
	sign = get_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
	}
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			res = res + (str[i++] - '0') / divisor;
			divisor *= 10.0;
		}
	}
	return (res * sign);
}

int	is_valid_double(char *str)
{
	int	i;
	int	digits;

	digits = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		digits++;
		i++;
	}
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		digits++;
		i++;
	}
	if (str[i] == '\0' && digits > 0)
		return (1);
	return (0);
}

void	print_error(void)
{
	ft_printf("Error: Invalid Arguments\n\n");
	ft_printf("Available parameters:\n");
	ft_printf("  mandelbrot\n");
	ft_printf("  julia <real> <imag>\n\n");
	ft_printf("Examples:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia -0.79 0.15\n");
}
