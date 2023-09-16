#include "../includes/fdf.h"

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
        if (*x != *y) {
            break;
        }
        x++;
        y++;
    }
    return *(const unsigned char*)x - *(const unsigned char*)y;
}