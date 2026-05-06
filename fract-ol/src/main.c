/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:35 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/06 14:25:00 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/libft.h"

int	ft_close(t_fractol *fractol, int status)
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
	exit(status);
	return (status);
}

int	ft_keypress(int keycode, t_fractol *mlxptr)
{
	if (keycode == 65307)
		ft_close(mlxptr, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (!parse_args(argc, argv, &fractol))
		return (1);
	init_vars(&fractol);
	if (init_fractol(&fractol))
		return (1);
	init_image(&fractol);
	render(&fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
	mlx_hook(fractol.win, 17, 0, &ft_close, &fractol);
	mlx_hook(fractol.win, KeyPress, KeyPressMask, &ft_keypress, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
