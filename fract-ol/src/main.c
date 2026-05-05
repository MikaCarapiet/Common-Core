/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:35 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/05 19:21:36 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../mlx_linux/mlx.h"

static int	ft_close(t_fractol *fractol)
{
	if (fractol->img)
		mlx_destroy_image(fractol->mlx, fractol->img);
	if (fractol->win)
		mlx_destroy_window(fractol->mlx, fractol->win);
	if (fractol->mlx)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	exit(0);
	return (0);
}

int	ft_keypress(int keycode, t_fractol *mlxptr)
{
	if (keycode == 65307)
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
	fractol.type = 1;
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
	mlx_hook(fractol.win, 17, 0, &ft_close, &fractol);
	mlx_hook(fractol.win, KeyPress, KeyPressMask, &ft_keypress, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
