/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:16:54 by jucheval          #+#    #+#             */
/*   Updated: 2022/11/18 19:16:40 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdlib.h>

inline void	set_pxl(t_img *img, int x, int y, int color)
{
	*(img->data + (y * img->width) + x) = color;
}

void	set_x_pxls(t_img *img, t_intxy pos, int n, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < n
		&& pos.y + i < img->height)
	{
		j = 0;
		while (j < n
			&& pos.x + j < img->width)
		{
			set_pxl(img, pos.x + j, pos.y + i, color);
			j++;
		}
		i++;
	}
}
