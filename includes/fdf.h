/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:08:14 by hbalasan          #+#    #+#             */
/*   Updated: 2023/07/17 20:11:27 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	double	angle;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

typedef struct s_pixels
{
	float	x;
	float	x1;
	float	y;
	float	y1;
}	t_pixels;

//___________________/ft_split\___________________//
char	**ft_split(char const *s, char c);
//___________________/fdf_utils\___________________//
void	to_free(char **str);
void	error(void);
int		ft_atoi(const char *str);
//___________________/read_file\___________________//
void	read_file(t_fdf *fdf, char *file_name);
void	get_height_and_width(t_fdf *fdf, char *file_name);
void	fill_matrix(t_fdf *fdf, char *file_name);
//_____________________/draw\_____________________//
void	bresenham_algo(t_fdf *fdf, float x, float y, float x1, float y1);
void	draw(t_fdf *fdf);
void	isometric_change(float *x, float *y, int z, double fdf);

//-framework OpenGL -framework AppKit


#endif