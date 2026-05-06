/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:42:34 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/05 23:48:45 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	julia_iterations(double z_real, double z_imag, t_fractol *fractol)
{
	int		iteration;
	double	c_real;
	double	c_imag;
	double	new_real;
	double	new_imag;

	iteration = 1;
	c_real = fractol->julia_real;
	c_imag = fractol->julia_imag;
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
