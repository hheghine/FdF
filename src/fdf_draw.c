/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heghine <heghine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:48:14 by hbalasan          #+#    #+#             */
/*   Updated: 2023/09/20 19:55:36 by heghine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw(t_fdf *fdf)
{
	fdf->dots.y = 0;
	while (fdf->dots.y < fdf->height)
	{
		fdf->dots.x = 0;
		while (fdf->dots.x < fdf->width)
		{
			if (fdf->dots.x < fdf->width - 1)
				bresenham(fdf, fdf->dots.x + 1, fdf->dots.y);
			if (fdf->dots.y < fdf->height - 1)
				bresenham(fdf, fdf->dots.x, fdf->dots.y + 1);
			fdf->dots.x++;
		}
		fdf->dots.y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img, 0, 0);
}