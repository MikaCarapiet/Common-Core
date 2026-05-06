/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:36 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/05 22:11:11 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot_iterations(double c_real, double c_imag, t_fractol *fractol)
{
	int		iteration;
	double	z_real;
	double	z_imag;
	double	new_real;
	double	new_imag;

	iteration = 1;
	z_real = 0.0;
	z_imag = 0.0;
	while (iteration <= fractol->max_iterations)
	{
		new_real = (z_real * z_real) - (z_imag * z_imag) + c_real;
		new_imag = 2 * z_real * z_imag + c_imag;
		if (new_real * new_real + new_imag * new_imag > 4)
			return (iteration);
		z_real = new_real;
		z_imag = new_imag;
		iteration++;
	}
	return (fractol->max_iterations);
}

// int	render_mandelbrot(double c_real, double c_imag, t_fractol *fractol)
// {
// 	int iterations;

// 	iterations = mandelbrot_iterations(c_real, c_imag, fractol);

// }
