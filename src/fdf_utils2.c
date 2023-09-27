/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:35:03 by hbalasan          #+#    #+#             */
/*   Updated: 2023/09/27 21:11:05 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_mod(int a)
{
	if (a > 0)
		return (a);
	return (-a);
}

static int	check(char const *set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

void	st_end(char const *s1, char const *set, int *start, int *end)
{
	int	i;

	i = -1;
	while (s1[++i])
	{
		if (!check(set, s1[i]))
		{
			*start = i;
			break ;
		}
	}
	i = ft_strlen(s1);
	while (--i >= 0)
	{
		if (!check(set, s1[i]))
		{
			*end = i;
			break ;
		}
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*s;

	i = 0;
	start = 0;
	end = 0;
	if (!s1 || !set)
		return (NULL);
	st_end (s1, set, &start, &end);
	if (start == 0 && start == end)
		return (ft_strdup(""));
	s = malloc (sizeof(char) * (end - start + 2));
	if (!s)
		return (NULL);
	while (start <= end)
		s[i++] = s1[start++];
	s[i] = 0;
	return (s);
}
