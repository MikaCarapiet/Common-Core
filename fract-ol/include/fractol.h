/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:43:08 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/06 14:25:14 by mcarapie         ###   ########.fr       */
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

	double	julia_real;
	double	julia_imag;
	int		type;
	int		max_iterations;
	int		width;
	int		height;

	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_fractol;

typedef struct s_render
{
	int		x;
	int		y;
	int		pixel;
	int		color;
	double	real_x;
	double	imag_y;
	int		iteration;
}			t_render;

// init mlx
void		init_vars(t_fractol *fractol);
int			init_fractol(t_fractol *fractol);
void		init_image(t_fractol *fractol);
int			ft_close(t_fractol *fractol, int status);
// rendering and mapping values
void		render(t_fractol *fractol);
void		buffer_fill(t_fractol *fractol, int pixel, int color);
double		map_real(int x, t_fractol *fractol);
double		map_imag(int y, t_fractol *fractol);
int			make_color_from_iterations(int iteration, t_fractol *fractol);
int			get_iterations(double real_x, double imag_y, t_fractol *fractol);
int			julia_iterations(double z_real, double z_imag, t_fractol *fractol);
int			mandelbrot_iterations(double c_real, double c_imag,
				t_fractol *fractol);

// parsing & validating arguments
int			parse_args(int argc, char **argv, t_fractol *fractol);
int			is_valid_double(char *str);
double		ft_atod(const char *str);
int			get_sign(const char *str, int *i);
void		skip_space(const char *str, int *i);
void		print_error(void);
#endif