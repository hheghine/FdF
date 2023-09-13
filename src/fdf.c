/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heghine <heghine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:12:20 by hbalasan          #+#    #+#             */
/*   Updated: 2023/09/13 22:26:07 by heghine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	if ((keycode >= 123 && keycode <= 126)
		|| keycode == 13 || keycode == 1
		|| keycode == 0 || keycode == 2)
	{
		if (keycode == 126)
			fdf->shift_y -= 10;
		if (keycode == 125)
			fdf->shift_y += 10;
		if (keycode == 124)
			fdf->shift_x += 10;
		if (keycode == 123)
			fdf->shift_x -= 10;
		if (keycode == 13)
			fdf->zoom += 5;
		if (keycode == 1)
			fdf->zoom -= 5;
		if (keycode == 0)
			fdf->angle -= 0.05;
		if (keycode == 2)
			fdf->angle += 0.05;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw(fdf);
	}
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
	mlx_hook(fdf.win_ptr, 2, 1L, key_hook, &fdf);
	mlx_loop(fdf.mlx_ptr);
}