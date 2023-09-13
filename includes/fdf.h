/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heghine <heghine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:08:14 by hbalasan          #+#    #+#             */
/*   Updated: 2023/09/14 02:40:24 by heghine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"

# define WIDTH 1000
# define HEIGHT 700

# ifdef __linux__
#  define ESC 65307
//
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
//
#  define ZOOM_IN 61
#  define ZOOM_OUT 45
#  define ZOOM_IN1 119 // W
#  define ZOOM_OUT1 115 // S
//
#  define ANGLE_LEFT 97 // A
#  define ANGLE_RIGHT 100 // D
# else
#  define ESC 53
//
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
//
#  define ZOOM_IN 24
#  define ZOOM_OUT 27
#  define ZOOM_IN1 13 // W 
#  define ZOOM_OUT 1 // S
//
#  define ANGLE_LEFT 0 // A
#  define ANGLE_RIGHT 2 // D
# endif


typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

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
	t_data	img;
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