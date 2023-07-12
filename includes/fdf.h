/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:08:14 by hbalasan          #+#    #+#             */
/*   Updated: 2023/07/12 20:48:37 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include "../minilibx_macos/mlx.h"
# include "get_next_line.h"

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**matrix;
	void	*mlx_ptr;
	void	*win_ptr;
} t_fdf;

//___________________/ft_split\___________________//
char	**ft_split(char const *s, char c);
//___________________/fdf_utils\___________________//
void	to_free(char **str);
void	error(void);
int		ft_atoi(const char *str);
//___________________/read_file\___________________//
void	read_file(t_fdf *fdf, char *file_name);
int		get_height(char *file_name);

#endif