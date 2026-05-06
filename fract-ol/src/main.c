/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:35 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/05 23:47:39 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	ft_close(t_fractol *fractol)
{
	static int	closing;

	if (closing)
		return (0);
	closing = 1;
	if (fractol->img)
	{
		mlx_destroy_image(fractol->mlx, fractol->img);
		fractol->img = NULL;
	}
	if (fractol->win)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		fractol->win = NULL;
	}
	// if (fractol->mlx)
	// {
	// 	mlx_destroy_display(fractol->mlx);
	// 	free(fractol->mlx);
	// }
	exit(0);
	return (0);
}

int	ft_keypress(int keycode, t_fractol *mlxptr)
{
	if (keycode == ESC_KEY)
		ft_close(mlxptr);
	return (0);
}

int	main(void)
{
	t_fractol	fractol;

	init_vars(&fractol);
	if (init_fractol(&fractol))
		return (1);
	init_image(&fractol);
	render(&fractol);
	fractol.type = 2;
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
	mlx_hook(fractol.win, DESTROY_NOTIFY, 0, &ft_close, &fractol);
	mlx_hook(fractol.win, KEY_PRESS, KEY_PRESS_MASK, &ft_keypress, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
