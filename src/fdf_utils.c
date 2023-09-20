#include "../includes/fdf.h"

void	to_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;
	size_t		s_size;

	last = NULL;
	if (!s)
		return (NULL);
	s_size = ft_strlen(s) + 1;
	while (s_size--)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	return ((char *)last);
}

int strcmp(const char *x, const char *y)
{
	while (*x)
	{
		if (*x != *y) 
			break;
		x++;
		y++;
	}
	return *(const unsigned char*)x - *(const unsigned char*)y;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (*(str + i) == ' ' || (*(str + i) > 8 && *(str + i) < 14))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			neg *= -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		res *= 10;
		res += *(str + i) - '0';
		i++;
	}
	return (res * neg);
}
