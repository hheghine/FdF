/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:12:20 by hbalasan          #+#    #+#             */
/*   Updated: 2023/07/14 20:39:04 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode >= 123 && keycode <= 126)
	{
		if (keycode == 126)
			fdf->shift_y -= 10;
		if (keycode == 125)
			fdf->shift_y += 10;
		if (keycode == 124)
			fdf->shift_x += 10;
		if (keycode == 123)
			fdf->shift_x -= 10;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw(fdf);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf		fdf;
	// t_pixels	pixels;

	if (argc == 2)
	{
		read_file(&fdf, argv[1]);
		fdf.mlx_ptr = mlx_init();
		fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1000, 1000, "fdf");
		fdf.zoom = 20;

		// bresenham_algo(&fdf);
		draw(&fdf);

		mlx_key_hook(fdf.win_ptr, key_hook, &fdf);
		mlx_loop(fdf.mlx_ptr);
	}
	else
		error();
}