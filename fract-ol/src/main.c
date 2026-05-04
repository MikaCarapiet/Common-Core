/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:35 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/04 17:53:59 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../mlx_linux/mlx.h"

static int	ft_close(t_fractol *mlxptr)
{
	if (mlxptr->img)
		mlx_destroy_image(mlxptr->mlx, mlxptr->img);
	if (mlxptr->win)
		mlx_destroy_window(mlxptr->mlx, mlxptr->win);
	if (mlxptr->mlx)
	{
		mlx_destroy_display(mlxptr->mlx);
		free(mlxptr->mlx);
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
	t_fractol	mlxptr;
	int			x;
	int			y;
	int			pixel;
	char		*buffer;
	int			color;

	mlxptr.height = 600;
	mlxptr.width = 800;
	mlxptr.mlx = mlx_init();
	if (!mlxptr.mlx)
		return (1);
	mlxptr.win = mlx_new_window(mlxptr.mlx, mlxptr.width, mlxptr.height,
			"Hello");
	if (!mlxptr.win)
	{
		mlx_destroy_display(mlxptr.mlx);
		free(mlxptr.mlx);
		return (1);
	}
	mlxptr.img = mlx_new_image(mlxptr.mlx, mlxptr.width, mlxptr.height);
	mlxptr.addr = mlx_get_data_addr(mlxptr.img, &mlxptr.bits_per_pixel,
			&mlxptr.size_line, &mlxptr.endian);
	buffer = (char *)mlxptr.addr;
	y = 0;
	color = 0xABCDEF;
	while (y < (mlxptr.height))
	{
		x = 0;
		while (x < mlxptr.width)
		{
			pixel = (y * mlxptr.size_line) + (x * (mlxptr.bits_per_pixel / 8));
			if (mlxptr.endian == 1)
			{
				buffer[pixel + 0] = (color >> 24);
				buffer[pixel + 1] = (color >> 16) & 0xFF;
				buffer[pixel + 2] = (color >> 8) & 0xFF;
				buffer[pixel + 3] = (color)&0xFF;
			}
			else if (mlxptr.endian == 0)
			{
				buffer[pixel + 0] = (color)&0xFF;
				buffer[pixel + 1] = (color >> 8) & 0xFF;
				buffer[pixel + 2] = (color >> 16) & 0xFF;
				buffer[pixel + 3] = (color >> 24);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlxptr.mlx, mlxptr.win, mlxptr.img, 0, 0);
	mlx_hook(mlxptr.win, 17, 0, &ft_close, &mlxptr);
	mlx_hook(mlxptr.win, KeyPress, KeyPressMask, &ft_keypress, &mlxptr);
	mlx_loop(mlxptr.mlx);
	return (0);
}
