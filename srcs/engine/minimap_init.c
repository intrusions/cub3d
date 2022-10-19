/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:40:30 by pducos            #+#    #+#             */
/*   Updated: 2022/10/15 14:32:10 by pducos           ###   ########.fr       */
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

	y = 0;
	while (self->map.line[y])
	{
		x = 0;
		while (self->map.line[y][x])
		{
			if (self->map.line[y][x] == ' '
				|| self->map.line[y][x] == self->map.cur_p.val)
				set_x_pxls(
					&self->mlx.display.minimap.map,
					x * CUBE_SIZE,
					y * CUBE_SIZE,
					CUBE_SIZE,
					MINIMAP_SPACE_RGB);
			x++;
		}
		y++;
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
