/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:54:37 by jucheval          #+#    #+#             */
/*   Updated: 2022/11/18 19:39:49 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	guides_draw(t_display *display)
{
	int		i;
	t_intxy	pos;

	i = -1;
	while (++i < MINIMAP_Y)
	{
		pos.x = display->minimap.loc.x;
		pos.y = i;
		set_x_pxls(
			&display->minimap.minimap,
			pos,
			3,
			MINIMAP_GUIDES_RGB);
	}
	i = -1;
	while (++i < MINIMAP_X)
	{
		pos.x = i;
		pos.y = display->minimap.loc.y;
		set_x_pxls(
			&display->minimap.minimap,
			pos,
			3,
			MINIMAP_GUIDES_RGB);
	}
}

static void	update_display(t_display *display)
{
	int	*dst;
	int	*src;
	int	size;
	int	x;
	int	y;

	src = display->minimap.map.data;
	dst = display->minimap.minimap.data;
	x = display->player.x * CUBE_SIZE - (MINIMAP_X >> 1);
	y = display->player.y * CUBE_SIZE - (MINIMAP_Y >> 1);
	x = clamp(x, 0, display->minimap.map.width - MINIMAP_X);
	y = clamp(y, 0, display->minimap.map.height - MINIMAP_Y);
	display->minimap.loc.x = display->player.x * CUBE_SIZE - x;
	display->minimap.loc.y = display->player.y * CUBE_SIZE - y;
	src += y * display->minimap.map.width + x;
	size = MINIMAP_Y;
	while (size--)
	{
		mem_cpy(dst, src, MINIMAP_X << 2);
		src += display->minimap.map.width;
		dst += MINIMAP_X;
	}
}

void	minimap_update(t_self *self)
{
	image_reset(&self->mlx.display.minimap.minimap, 0);
	update_display(&self->mlx.display);
	guides_draw(&self->mlx.display);
}
