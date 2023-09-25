/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:35:03 by hbalasan          #+#    #+#             */
/*   Updated: 2023/09/25 23:26:32 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_max(int a, int  b)
{
	if (a > b)
		return (a);
	return (b);
}

int ft_mod(int a)
{
	if (a > 0)
		return (a);
	return (-a);
}