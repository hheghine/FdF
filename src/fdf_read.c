/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:40:06 by hbalasan          #+#    #+#             */
/*   Updated: 2023/09/21 20:34:32 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	height_and_width(t_fdf *fdf, int fd, char **line, int *width)
{
	char	**tmp;	

	*line = get_next_line(fd);
	if (!*line || (fdf->width != 0 && fdf->width != *width))
	{
		free(*line);
		return (1);
	}
	fdf->height++;
	tmp = ft_split(*line, ' ');
	free(*line);
	*width = 0;
	while (tmp[*width] && tmp[*width][0] != '\n')
		*width += 1;
	if (fdf->width && fdf->width != *width)
		ft_error("Fdf Error: Uneven lines in file\n");
	fdf->width = *width;
	to_free(tmp);
	return (0);
}

void	get_height_and_width(t_fdf *fdf, char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error("Fdf Error: Bad file descriptor\n");
	fdf->height = 0;
	fdf->width = 0;
	width = 0;
	while (1)
		if (height_and_width(fdf, fd, &line, &width))
			break ;
	close (fd);
}

int	actually_fill(t_fdf *fdf, int fd, char **line, int *i)
{
	char	**splitted;
	int		j;
	
	*line = get_next_line(fd);
	if (!*line)
	{
		free(*line);
		return (1);
	}
	splitted = ft_split(*line, ' ');
	free(*line);
	j = -1;
	while (++j < fdf->width)
		fdf->matrix[*i][j] = ft_atoi(splitted[j]);
	*i += 1;
	to_free(splitted);
	return (0);
}

void	fill_matrix(t_fdf *fdf, char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error("Fdf Error: Bad file descriptor\n");
	i = 0;
	while (1)
		if (actually_fill(fdf, fd, &line, &i))
			break ;
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
