/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:32 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/06 14:23:48 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/libft.h"

void	init_vars(t_fractol *fractol)
{
	fractol->mlx = NULL;
	fractol->img = NULL;
	fractol->addr = NULL;
	fractol->win = NULL;
	fractol->height = 600;
	fractol->width = 800;
	fractol->max_iterations = 100;
}

int	init_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
	{
		ft_printf("Error: Failed to initialize MiniLibX\n");
		exit(1);
	}
	fractol->win = mlx_new_window(fractol->mlx, fractol->width, fractol->height,
			"Hello");
	if (!fractol->win)
	{
		ft_printf("Error: Failed to create window\n");
		ft_close(fractol, 1);
		free(fractol->mlx);
		exit(1);
	}
	return (0);
}

void	init_image(t_fractol *fractol)
{
	fractol->img = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
	if (!fractol->img)
	{
		ft_printf("Error: Failed to create image\n");
		ft_close(fractol, 1);
		exit(1);
	}
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel,
			&fractol->size_line, &fractol->endian);
	if (!fractol->addr)
	{
		ft_printf("Error: Failed to get image buffer\n");
		ft_close(fractol, 1);
		exit(1);
	}
}
