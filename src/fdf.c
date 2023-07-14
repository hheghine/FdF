/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:12:20 by hbalasan          #+#    #+#             */
/*   Updated: 2023/07/14 17:43:00 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, void *fdf)
{
	(void)fdf;
	printf("%d", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	t_fdf		fdf;
	t_pixels	pixels;
	
	read_file(&fdf, argv[1]);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1000, 1000, "fdf");

	pixels.x = 10;
	pixels.x1 = 600;
	pixels.y = 10;
	pixels.y1 = 300;

	bresenham_algo(&fdf, &pixels);

	mlx_key_hook(fdf.win_ptr, key_hook, NULL);
	mlx_loop(fdf.mlx_ptr);
}