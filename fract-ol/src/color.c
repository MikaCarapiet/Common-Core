/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:30 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/06 15:23:27 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/libft.h"

int	make_color_from_iterations(int iteration, t_fractol *fractol)
{
	int	t;
	int	red;
	int	green;
	int	blue;

	if (iteration == fractol->max_iterations)
		return (0x000000);
	t = (iteration * 255) / fractol->max_iterations;
	red = t;
	green = t / 4;
	blue = 255 - t / 2;
	return ((red << 16) | (green << 8) | blue);
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
		buffer[pixel + 3] = (color) & 0xFF;
	}
	else if (fractol->endian == 0)
	{
		buffer[pixel + 0] = (color) & 0xFF;
		buffer[pixel + 1] = (color >> 8) & 0xFF;
		buffer[pixel + 2] = (color >> 16) & 0xFF;
		buffer[pixel + 3] = (color >> 24);
	}
}
