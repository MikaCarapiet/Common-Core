/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:39 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/06 13:45:36 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/libft.h"

double	map_real(int x, t_fractol *fractol)
{
	double	real_x;

	real_x = ((double)x / (fractol->width - 1)) * 4.0 - 2.0;
	return (real_x);
}

double	map_imag(int y, t_fractol *fractol)
{
	double	imag_y;

	imag_y = 1.5 - ((double)y / (fractol->height - 1)) * 3.0;
	return (imag_y);
}

int	get_iterations(double real_x, double imag_y, t_fractol *fractol)
{
	if (fractol->type == MANDELBROT)
		return (mandelbrot_iterations(real_x, imag_y, fractol));
	else
		return (julia_iterations(real_x, imag_y, fractol));
}

void	render(t_fractol *fractol)
{
	t_render	r;

	r.y = 0;
	while (r.y < (fractol->height))
	{
		r.x = 0;
		while (r.x < fractol->width)
		{
			r.real_x = map_real(r.x, fractol);
			r.imag_y = map_imag(r.y, fractol);
			r.pixel = (r.y * fractol->size_line) + (r.x
					* (fractol->bits_per_pixel / 8));
			r.iteration = get_iterations(r.real_x, r.imag_y, fractol);
			r.color = make_color_from_iterations(r.iteration, fractol);
			buffer_fill(fractol, r.pixel, r.color);
			r.x++;
		}
		r.y++;
	}
}
