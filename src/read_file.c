/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:40:06 by hbalasan          #+#    #+#             */
/*   Updated: 2023/07/12 20:59:37 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		error();
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;
	char	**tmp;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		error();
	line = get_next_line(fd);
	tmp = ft_split(line, ' ');
	free(line);
	close(fd);
	width = 0;
	while (tmp[width])
		width++;
	to_free(tmp);
	return (width);
}

void	fill_matrix(t_fdf *fdf, char *file_name)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**splitted;

	fd = open(file_name, O_RDONLY, 0);
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
		j = -1;
		while (++j <= fdf->width)
			fdf->matrix[i][j] = ft_atoi(splitted[j]);
		i++;
		free(line);
		to_free(splitted);
	}
	close(fd);
}

void	read_file(t_fdf *fdf, char *file_name)
{
	int	i;

	fdf->height = get_height(file_name);
	fdf->width = get_width(file_name);
	fdf->matrix = (int **)malloc(sizeof(int *) * (fdf->height + 1));
	i = -1;
	while (++i <= fdf->height)
		fdf->matrix[i] = (int *)malloc(sizeof(int) * (fdf->width + 1));
	fill_matrix(fdf, file_name);
}