/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:40:34 by pducos            #+#    #+#             */
/*   Updated: 2022/10/19 19:13:15 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	guides_draw(t_display *display)
{
	int	i;

	i = 0;
	while (i < MINIMAP_Y)
	{
		set_x_pxls(
			&display->minimap.minimap,
			display->minimap.loc.x,
			i,
			1,
			MINIMAP_GUIDES_RGB);
		i++;
	}
	i = 0;
	while (i < MINIMAP_X)
	{
		set_x_pxls(
			&display->minimap.minimap,
			i,
			display->minimap.loc.y,
			1,
			MINIMAP_GUIDES_RGB);
		i++;
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
	display->minimap.loc.x = display->player.x * CUBE_SIZE  - x;
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
