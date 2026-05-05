/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:39 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/05 19:24:51 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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

int	make_color_from_mapped_values(double real_x, double imag_y)
{
	int	red;
	int	green;
	int	blue;
	int	color;

	red = ((real_x + 2.0) / 4.0) * 255.0;
	green = ((1.5 - imag_y) / 3.0) * 255.0;
	blue = 0;
	color = (red << 16) | (green << 8) | blue;
	return (color);
}

void	buffer_fill(t_fractol *fractol, int pixel, int color)
{
	char	*buffer;

	buffer = (char *)fractol->addr;
	if (fractol->endian == 1)
	{
		buffer[pixel + 0] = (color >> 24);
		buffer[pixel + 1] = (color >> 16) & 0xFF;
		buffer[pixel + 2] = (color >> 8) & 0xFF;
		buffer[pixel + 3] = (color)&0xFF;
	}
	else if (fractol->endian == 0)
	{
		buffer[pixel + 0] = (color)&0xFF;
		buffer[pixel + 1] = (color >> 8) & 0xFF;
		buffer[pixel + 2] = (color >> 16) & 0xFF;
		buffer[pixel + 3] = (color >> 24);
	}
}

int	get_iterations(double real_x, double imag_y, t_fractol *fractol)
{
	if (fractol->type == MANDELBROT)
	{
		render_mandelbrot();
	}
	else if (fractol->type == JULIA)
	{
		render_julia();
	}
}

void	render(t_fractol *fractol)
{
	int		x;
	int		y;
	int		pixel;
	int		color;
	double	real_x;
	double	imag_y;

	y = 0;
	while (y < (fractol->height))
	{
		x = 0;
		while (x < fractol->width)
		{
			real_x = map_real(x, fractol);
			imag_y = map_imag(y, fractol);
			pixel = (y * fractol->size_line) + (x * (fractol->bits_per_pixel
						/ 8));
			color = make_color_from_mapped_values(real_x, imag_y);
			buffer_fill(fractol, pixel, color);
			x++;
		}
		y++;
	}
}
