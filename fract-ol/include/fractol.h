/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:43:08 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/04 11:05:07 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;

	int		width;
	int		height;

	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_fractol;

# include <X11/X.h>
# include <X11/keysymdef.h>
# include <stdlib.h>
#endif