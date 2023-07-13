/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:48:14 by hbalasan          #+#    #+#             */
/*   Updated: 2023/07/13 20:37:12 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define MAX(a, b) (a > b ? a : b)
#define MOD(a) (a > 0 ? a : -a)

void	bresenham_algo(t_fdf *fdf, t_pixels *pixels)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = pixels->x1 - pixels->x;
	y_step = pixels->y1 - pixels->y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(pixels->x - pixels->x1) || (int)(pixels->y - pixels->y1))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, pixels->x, pixels->y, 0x0000FF00);
		pixels->x += x_step;
		pixels->y += y_step;
	}
}