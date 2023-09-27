/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:34:15 by hbalasan          #+#    #+#             */
/*   Updated: 2023/09/28 00:21:06 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(char *str)
{
	write (2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

int	format_check(char *file)
{
	file = ft_strrchr(file, '.');
	if (!file || ft_strcmp(file, ".fdf"))
		return (1);
	return (0);
}

int	file_check(char *file)
{
	char	buf;
	char	*buf2;
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	while (read(fd, &buf, 1) > 0)
		i++;
	buf2 = malloc(i + 1);
	close(fd);
	fd = open(file, O_RDONLY);
	read(fd, buf2, i);
	buf2[i] = 0;
	str = ft_strtrim(buf2, "\n ");
	if (!str || !*str)
		ft_error("Invalid file\n");
	free(buf2);
	free(str);
	if (i == 0)
		return (1);
	close(fd);
	return (0);
}

int	input_check(int argc, char *file)
{
	if (argc != 2)
		ft_error("Fdf Error: Wrong arguments\n");
	if (format_check(file))
		ft_error("Fdf Error: Wrong file format\n");
	if (file_check(file))
		ft_error("Fdf Error: Empty or invalid file\n");
	return (0);
}
