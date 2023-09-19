#include "../includes/fdf.h"

void	color_and_view_control(t_fdf *fdf, int keycode)
{
	if (keycode == COLOR)
		fdf->color_flag *= -1;
	if (keycode == TOP)
		fdf->isometric_flag *= -1;
}

void	zoom_and_angle_control(t_fdf *fdf, int keycode)
{
	if (keycode == ZOOM_IN )
		if (fdf->zoom <= 1000)
			fdf->zoom += 0.2;
	if (keycode == ZOOM_OUT )
		if (fdf->zoom >= 1)
			fdf->zoom -= 0.2;
	if (keycode == ANGLE_LEFT)
		fdf->angle -= 0.05;
	if (keycode == ANGLE_RIGHT)
		fdf->angle += 0.05;
}

void    shift_control(t_fdf *fdf, int keycode)
{
	if (keycode == UP)
		fdf->shift_y -= 10;
	if (keycode == DOWN)
		fdf->shift_y += 10;
	if (keycode == LEFT)
		fdf->shift_x -= 10;
	if (keycode == RIGHT)
		fdf->shift_x += 10;
	if (keycode == Z_UP)
		fdf->z_shift += 5;
	if (keycode == Z_DOWN)
		fdf->z_shift -= 5;
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(fdf->mlx_ptr, fdf->img.img);
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	shift_control(fdf, keycode);
	zoom_and_angle_control(fdf, keycode);
	color_and_view_control(fdf, keycode);
	image_init(fdf);
	draw(fdf);
	return (0);
}