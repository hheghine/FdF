/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:40:06 by hbalasan          #+#    #+#             */
/*   Updated: 2023/07/20 20:26:07 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_height_and_width(t_fdf *fdf, char *file_name)
{
	int		fd;
	int		width;
	char	*line;
	char	**tmp;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error();
	fdf->height = 0;
	fdf->width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || (fdf->width != 0 && fdf->width != width))
		{
			free(line);
			break ;
		}
		fdf->height++;
		tmp = ft_split(line, ' ');
		free(line);
		width = 0;
		while (tmp[width] && tmp[width][0] != '\n')
			width++;
		fdf->width = width;
		to_free(tmp);
	}
	close (fd);
}

void	fill_matrix(t_fdf *fdf, char *file_name)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**splitted;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error();
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		splitted = ft_split(line, ' ');
		free(line);
		j = -1;
		while (++j < fdf->width)
			fdf->matrix[i][j] = ft_atoi(splitted[j]);
		i++;
		to_free(splitted);
	}
	close(fd);
}

void	read_file(t_fdf *fdf, char *file_name)
{
	int	i;

	get_height_and_width(fdf, file_name);
	fdf->matrix = (int **)malloc(sizeof(int *) * (fdf->height));
	i = -1;
	while (++i < fdf->height)
		fdf->matrix[i] = (int *)malloc(sizeof(int) * (fdf->width));
	fill_matrix(fdf, file_name);
}
