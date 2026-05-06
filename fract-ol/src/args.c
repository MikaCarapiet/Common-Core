/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:28 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/06 14:12:49 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/libft.h"

int	parse_args(int argc, char **argv, t_fractol *fractol)
{
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		fractol->type = MANDELBROT;
		return (1);
	}
	if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (is_valid_double(argv[2]) && is_valid_double(argv[3]))
		{
			fractol->julia_real = ft_atod(argv[2]);
			fractol->julia_imag = ft_atod(argv[3]);
			fractol->type = JULIA;
			return (1);
		}
	}
	print_error();
	return (0);
}
