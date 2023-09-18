/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heghine <heghine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:08:14 by hbalasan          #+#    #+#             */
/*   Updated: 2023/09/18 21:16:01 by heghine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"

# define WIDTH 1200
# define HEIGHT 1000

#define YELLOW 0x00FFFF66 
#define BLUE 0x0099CCFF
#define GREEN 0x0099FF33
#define VIOLET 0x00CC99FF
#define CYAN 0x0000FFFF
#define ROSE 0x00FF00CC	
#define DARKBLUE 0x006633CC

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
#  define Z_UP 119 // W
#  define Z_DOWN 115 // S
//
#  define ANGLE_LEFT 97 // A
#  define ANGLE_RIGHT 100 // D
//
#  define COLOR 99 // C
//
#  define TOP 116 // T
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
#  define Z_UP 13 // W 
#  define Z_DOWN 1 // S
//
#  define ANGLE_LEFT 0 // A
#  define ANGLE_RIGHT 2 // D
//
#  define COLOR 8 // C
//
#  define TOP 17 // T
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
	float	zoom;
	int		color;
	int		color_flag;
	int		isometric_flag;
	int		z_shift;
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
void	image_start_position(t_fdf *fdf);
//void	what_color_is_my_stupid_pixel(t_fdf *fdf, float x1, float x2);
int interpolate(int color1, int color2, float fraction);

char	*ft_strrchr(const char *s, int c);
int 	strcmp(const char *x, const char *y);
int		input_check(int argc, char *file);
void	ft_error(char *str);

//-framework OpenGL -framework AppKit

#endif