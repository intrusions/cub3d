/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:54:33 by jucheval          #+#    #+#             */
/*   Updated: 2022/11/18 19:38:18 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdbool.h>
#include <math.h>

static void	map_draw(t_self *self)
{
	int		y;
	int		x;
	t_intxy	pos;

	y = -1;
	while (self->map.line[++y])
	{
		x = -1;
		while (self->map.line[y][++x])
		{
			if (self->map.line[y][x] == ' '
				|| self->map.line[y][x] == self->map.cur_p.val)
			{
				pos.x = x * CUBE_SIZE;
				pos.y = y * CUBE_SIZE;
				set_x_pxls(
					&self->mlx.display.minimap.map,
					pos,
					CUBE_SIZE,
					MINIMAP_SPACE_RGB);
			}
		}
	}
}

bool	minimap_init(t_self *self)
{
	int	x;
	int	y;

	x = self->map.max * CUBE_SIZE;
	y = self->map.size * CUBE_SIZE;
	if (x * y < MINIMAP_X * MINIMAP_Y)
	{
		x = MINIMAP_X;
		y = MINIMAP_Y;
	}
	if (!image_init(
			&self->mlx,
			&self->mlx.display.minimap.map,
			x, y))
		return (false);
	if (!image_init(
			&self->mlx,
			&self->mlx.display.minimap.minimap,
			MINIMAP_X, MINIMAP_Y))
		return (false);
	image_reset(&self->mlx.display.minimap.map, MINIMAP_BG_RGB);
	map_draw(self);
	return (true);
}
