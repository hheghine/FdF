/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heghine <heghine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:12:20 by hbalasan          #+#    #+#             */
/*   Updated: 2023/09/18 21:16:24 by heghine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	image_start_state(t_fdf *fdf)
{
	if (fdf->img.img)
		mlx_destroy_image(fdf->mlx_ptr, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, \
		&fdf->img.line_length, &fdf->img.endian);
	draw(fdf);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(fdf->mlx_ptr, fdf->img.img);
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	if (keycode == UP)
		fdf->shift_y -= 10;
	if (keycode == DOWN)
		fdf->shift_y += 10;
	if (keycode == RIGHT)
		fdf->shift_x += 10;
	if (keycode == LEFT)
		fdf->shift_x -= 10;
	if (keycode == ZOOM_IN ) //|| keycode == ZOOM_IN1)
		if (fdf->zoom <= 1000)
			fdf->zoom += 0.2;
	if (keycode == ZOOM_OUT ) //|| keycode == ZOOM_OUT1)
		if (fdf->zoom >= 1)
			fdf->zoom -= 0.2;
	if (keycode == ANGLE_LEFT)
		fdf->angle -= 0.05;
	if (keycode == ANGLE_RIGHT)
		fdf->angle += 0.05;
	if (keycode == COLOR)
		fdf->color_flag *= -1;
	if (keycode == TOP)
		fdf->isometric_flag *= -1;
	if (keycode == Z_UP)
		fdf->z_shift += 5;
	if (keycode == Z_DOWN)
		fdf->z_shift -= 5;
	
	image_start_state(fdf);
	draw(fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf		fdf;

	if (input_check(argc, argv[1]))
		return (1);

	read_file(&fdf, argv[1]);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIDTH, HEIGHT, argv[1]);
	fdf.img.img = mlx_new_image(fdf.mlx_ptr, WIDTH, HEIGHT);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel, \
	&fdf.img.line_length, &fdf.img.endian);

	fdf.angle = 0.8;
	fdf.color_flag = 1;
	fdf.isometric_flag = 1;
	fdf.z_shift = 0;
	image_start_position(&fdf);
	image_start_state(&fdf);
	
	mlx_hook(fdf.win_ptr, 2, 1l, key_hook, &fdf);
	mlx_loop(fdf.mlx_ptr);
}