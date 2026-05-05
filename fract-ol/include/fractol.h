/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:43:08 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/05 19:45:37 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysymdef.h>
# include <stdlib.h>
# define MANDELBROT 1
# define JULIA 2
typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;

	int		type;
	int		max_iterations;
	int		width;
	int		height;

	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_fractol;

void		init_vars(t_fractol *fractol);
int			init_fractol(t_fractol *fractol);
void		init_image(t_fractol *fractol);

void		render(t_fractol *fractol);
void		buffer_fill(t_fractol *fractol, int pixel, int color);

double		map_real(int x, t_fractol *fractol);
double		map_imag(int y, t_fractol *fractol);
int			make_color_from_mapped_values(double real_x, double imag_y);

int			get_iterations(double real_x, double imag_y, t_fractol *fractol);
int			render_mandelbrot(double real_x, double imag_y, t_fractol *fractol);
int			render_julia(double real_x, double imag_y, t_fractol *fractol);
#endif