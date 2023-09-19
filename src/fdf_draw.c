/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heghine <heghine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:48:14 by hbalasan          #+#    #+#             */
/*   Updated: 2023/09/19 19:53:19 by heghine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define MAX(a, b) (a > b ? a : b)
#define MOD(a) (a > 0 ? a : -a)

void	isometric_change(float *x, float *y, int z, double angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	bresenham(t_fdf *fdf, float x, float y, float x1, float y1)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	
	z = fdf->matrix[(int)y][(int)x];
	z1 = fdf->matrix[(int)y1][(int)x1];
	if (z != 0)
		z += fdf->z_shift;
	if (z1 != 0)
		z1 += fdf->z_shift;
//____________________________________zoom_
	x *= fdf->zoom;
	x1 *= fdf->zoom;
	y *= fdf->zoom;
	y1 *= fdf->zoom;
//______________________________________3D_
	if (fdf->isometric_flag > 0)
	{
		isometric_change(&x, &y, z, fdf->angle);
		isometric_change(&x1, &y1, z1, fdf->angle);
	}
//____________________________________shift_
	x += fdf->shift_x;
	y += fdf->shift_y;
	x1 += fdf->shift_x;
	y1 += fdf->shift_y;
//____________________________________color_
	if (fdf->isometric_flag > 0)
	{
		if (fdf->color_flag > 0)
			fdf->color = interpolate(VIOLET, BLUE, MOD(y1 - y));
		else
			fdf->color = interpolate(ROSE, VIOLET, MOD(y1 - y));
	}
	else
	{
		if (fdf->color_flag > 0)
			fdf->color = interpolate(VIOLET, BLUE, MOD(z1 - z));
		else
			fdf->color = interpolate(ROSE, VIOLET, MOD(z1 - z));
	}

	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(&(fdf->img), x, y, fdf->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *fdf)
{
	// int	x;
	// int	y;

	fdf->pixels.y = 0;
	while (fdf->pixels.y < fdf->height)
	{
		fdf->pixels.x = 0;
		while (fdf->pixels.x < fdf->width)
		{
			if (fdf->pixels.x < fdf->width - 1)
				bresenham(fdf, fdf->pixels.x, fdf->pixels.y, fdf->pixels.x + 1, fdf->pixels.y);
			if (fdf->pixels.y < fdf->height - 1)
				bresenham(fdf, fdf->pixels.x, fdf->pixels.y, fdf->pixels.x, fdf->pixels.y + 1);
			fdf->pixels.x++;
		}
		fdf->pixels.y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img, 0, 0);
}