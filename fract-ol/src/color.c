/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:30 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/06 13:45:21 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/libft.h"

int	make_color_from_iterations(int iteration, t_fractol *fractol)
{
	int	color;
	int	intensity;

	intensity = (iteration * 255) / fractol->max_iterations;
	if (iteration == fractol->max_iterations)
		color = 0x00000000;
	else
		color = (intensity << 16) | (intensity << 8) | intensity;
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
