/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heghine <heghine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:12:20 by hbalasan          #+#    #+#             */
/*   Updated: 2023/09/14 02:39:54 by heghine          ###   ########.fr       */
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
	if (keycode == ZOOM_IN)
		fdf->zoom += 5;
	if (keycode == ZOOM_OUT)
		fdf->zoom -= 5;
	if (keycode == ANGLE_LEFT)
		fdf->angle -= 0.05;
	if (keycode == ANGLE_RIGHT)
		fdf->angle += 0.05;
	image_start_state(fdf);
	//mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw(fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf		fdf;
	// t_pixels	pixels;

	if (argc != 2)
		error();
	read_file(&fdf, argv[1]);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1000, 1000, "fdf");
	fdf.img.img = mlx_new_image(fdf.mlx_ptr, 1000, 1000);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel, \
	&fdf.img.line_length, &fdf.img.endian);
	fdf.zoom = 20;
	fdf.angle = 0.8;

	// bresenham_algo(&fdf);
	draw(&fdf);
	mlx_hook(fdf.win_ptr, 2, 1l, key_hook, &fdf);
	mlx_loop(fdf.mlx_ptr);
}