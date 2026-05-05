/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:32 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/05 19:46:13 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_vars(t_fractol *fractol)
{
	fractol->mlx = NULL;
	fractol->img = NULL;
	fractol->addr = NULL;
	fractol->win = NULL;
	fractol->height = 600;
	fractol->width = 800;
	fractol->max_iterations = 100;
	fractol->type = 1;
}

int	init_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		return (1);
	fractol->win = mlx_new_window(fractol->mlx, fractol->width, fractol->height,
			"Hello");
	if (!fractol->win)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		return (1);
	}
	return (0);
}

void	init_image(t_fractol *fractol)
{
	fractol->img = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel,
			&fractol->size_line, &fractol->endian);
}
