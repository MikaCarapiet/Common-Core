/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:35 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/06 16:23:53 by mcarapie         ###   ########.fr       */
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

int	close_window(t_fractol *fractol)
{
	return (ft_close(fractol, 0));
}

int	ft_keypress(int keycode, t_fractol *mlxptr)
{
	if (keycode == 65307)
		ft_close(mlxptr, 0);
	return (0);
}

int	mouse_handler(int button, int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractol->min_imag *= 0.95;
		fractol->max_imag *= 0.95;
		fractol->min_real *= 0.95;
		fractol->max_real *= 0.95;
	}
	if (button == 5)
	{
		fractol->min_imag /= 0.95;
		fractol->max_imag /= 0.95;
		fractol->min_real /= 0.95;
		fractol->max_real /= 0.95;
	}
	render(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	init_vars(&fractol);
	if (!parse_args(argc, argv, &fractol))
		return (1);
	if (init_fractol(&fractol))
		return (1);
	init_image(&fractol);
	render(&fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
	mlx_mouse_hook(fractol.win, mouse_handler, &fractol);
	mlx_hook(fractol.win, 17, 0, &close_window, &fractol);
	mlx_hook(fractol.win, KeyPress, KeyPressMask, &ft_keypress, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
