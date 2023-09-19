#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	image_init(t_fdf *fdf)
{
	if (fdf->img.img)
		mlx_destroy_image(fdf->mlx_ptr, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, \
		&fdf->img.line_length, &fdf->img.endian);
	draw(fdf);
}

void    fdf_init(t_fdf *fdf)
{
    float	height;
	float	width;

	height = fdf->width * sin(fdf->angle) + fdf->height * cos(fdf->angle);
	width = fdf->width * cos(fdf->angle) + fdf->height * sin(fdf->angle);
	if (height < width)
		fdf->zoom = (HEIGHT - 650) / height;
	else
		fdf->zoom = (WIDTH - 650) / width;
	
	fdf->shift_x = (WIDTH / 3) + 100;
	fdf->shift_y = (HEIGHT / 3) - 50;
	fdf->z_shift = 0;
    fdf->angle = 0.8;
	fdf->color_flag = 1;
	fdf->isometric_flag = 1;
}

void    minilibx_init(t_fdf *fdf, char *win_name)
{
    fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, win_name);
	fdf->img.img = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, \
	&fdf->img.line_length, &fdf->img.endian);
}