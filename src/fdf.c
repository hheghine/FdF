/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heghine <heghine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:12:20 by hbalasan          #+#    #+#             */
/*   Updated: 2023/09/20 20:03:09 by heghine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf		fdf;

	if (input_check(argc, argv[1]))
		return (1);
	read_file(&fdf, argv[1]);
	minilibx_init(&fdf, argv[1]);
	fdf_init(&fdf);
	image_init(&fdf);
	mlx_hook(fdf.win_ptr, 2, 1l, key_hook, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
