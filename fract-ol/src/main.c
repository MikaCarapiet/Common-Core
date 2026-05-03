/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:35 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/03 15:31:55 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../mlx_linux/mlx.h"

static int	ft_close(t_fractol *mlxptr)
{
	(void)mlxptr;
	exit(0);
	return (0);
}
int	main(void)
{
	t_fractol mlxptr;

	mlxptr.height = 600;
	mlxptr.width = 800;

	mlxptr.mlx = mlx_init();
	if (!mlxptr.mlx)
	{
		free(mlxptr.mlx);
		return (1);
	}
	mlxptr.win = mlx_new_window(mlxptr.mlx, mlxptr.width, mlxptr.height,
			"Hello");

	mlx_hook(mlxptr.win, 17, 1 << 17, &ft_close, &mlxptr);
	mlx_loop(mlxptr.mlx);
	return (0);
}