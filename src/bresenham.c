/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:33:40 by hbalasan          #+#    #+#             */
/*   Updated: 2023/09/25 23:26:59 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric_change(float *x, float *y, int z, double angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	zoom_and_3d(t_fdf *fdf, t_coordinates *xyz)
{
	xyz->x *= fdf->zoom;
	xyz->x1 *= fdf->zoom;
	xyz->y *= fdf->zoom;
	xyz->y1 *= fdf->zoom;
	if (fdf->isometric_flag > 0)
	{
		isometric_change(&xyz->x, &xyz->y, xyz->z, fdf->angle);
		isometric_change(&xyz->x1, &xyz->y1, xyz->z1, fdf->angle);
	}
}

void    step_and_put_pixels(t_fdf *fdf, t_coordinates *xyz)
{
	int max;

	xyz->x_step = xyz->x1 - xyz->x;
	xyz->y_step = xyz->y1 - xyz->y;
	max = ft_max(ft_mod(xyz->x_step), ft_mod(xyz->y_step));
	xyz->x_step /= max;
	xyz->y_step /= max;
	while ((int)(xyz->x - xyz->x1) || (int)(xyz->y - xyz->y1))
	{
		my_mlx_pixel_put(&(fdf->img), xyz->x, xyz->y, fdf->color);
		xyz->x += xyz->x_step;
		xyz->y += xyz->y_step;
	}
}

void	bresenham(t_fdf *fdf, float x1, float y1)
{
	t_coordinates	xyz;

	xyz.x = (float)fdf->dots.x;
	xyz.y = (float)fdf->dots.y;
	xyz.y1 = y1;
	xyz.x1 = x1;
	xyz.z = fdf->matrix[(int)xyz.y][(int)xyz.x];
	xyz.z1 = fdf->matrix[(int)xyz.y1][(int)xyz.x1];
	if (xyz.z != 0)
		xyz.z += fdf->z_shift;
	if (xyz.z1 != 0)
		xyz.z1 += fdf->z_shift;
	zoom_and_3d(fdf, &xyz);
	xyz.x += fdf->shift_x;
	xyz.y += fdf->shift_y;
	xyz.x1 += fdf->shift_x;
	xyz.y1 += fdf->shift_y;
	picasso(fdf, &xyz);
	step_and_put_pixels(fdf, &xyz);
}
