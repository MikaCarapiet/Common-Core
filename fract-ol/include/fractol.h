/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:43:08 by mcarapie          #+#    #+#             */
/*   Updated: 2026/05/03 15:30:03 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct s_fractol
{
	void	*mlx;
	void	*win;

	int		width;
	int		height;
}			t_fractol;

# include <X11/X.h>
# include <stdlib.h>
#endif