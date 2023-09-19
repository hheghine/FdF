#include "../includes/fdf.h"

void	ft_error(char *str)
{
	write (2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

int	format_check(char *file)
{
	file = ft_strrchr(file, '.');
	if (!file)
		return (1);
	if (strcmp(file, ".fdf"))
		return (1);
	return (0);
}

int	file_check(char *file)
{
	char	*buf;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	while (read(fd, &buf, 1) > 0)
		i++;
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