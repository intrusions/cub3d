/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:20:54 by pducos            #+#    #+#             */
/*   Updated: 2023/01/09 18:11:38 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define FOV        1.15192

static void	cross_draw(t_self *self, t_display *display)
{
	int		i;
	int		color;
	t_intxy	pos;

	color = 0xffffff;
	if (self->keys.space)
		color = 0xff0000;
	i = -1;
	while (++i < 30)
	{
		pos.x = RENDER_X / 2;
		pos.y = RENDER_Y / 2 - 14 + i;
		if (i < 5 || i > 24)
			set_x_pxls(&display->screen,
				pos, 2, color);
	}
	i = -1;
	while (++i < 30)
	{
		pos.x = RENDER_X / 2 - 14 + i;
		pos.y = RENDER_Y / 2;
		if (i < 5 || i > 24)
			set_x_pxls(&display->screen,
				pos, 2, color);
	}
}

void	drawline(t_img *screen, t_img *texture, t_ray *r, int i)
{
	int		*ptr;
	size_t	len;
	int		*tex_ptr;

	len = r->line_len;
	tex_ptr = texture->data + (size_t)(r->wall_x * (float)texture->width);
	ptr = screen->data + ((int)RENDER_Y - len) / 2 * RENDER_X + i;
	while (len--)
	{
		if (ptr < screen->data + RENDER_X * RENDER_Y && ptr >= screen->data)
			*ptr = *(tex_ptr + texture->width * (int)(((float)len / \
				(float)r->line_len) * (float)texture->height));
		ptr += screen->width;
	}
}

static void	raycast(t_self *self)
{
	t_ray	r;
	int		i;

	r.current_angle = self->mlx.display.player.a - (FOV / 2);
	r.pos.x = self->mlx.display.player.x;
	r.pos.y = self->mlx.display.player.y;
	i = 0;
	while (i < RENDER_X)
	{
		compute_initial_values(&r);
		init_ray(&r);
		while (self->map.line[r.map.y][r.map.x] != '1')
			perform_dda(&r);
		determine_line_length(&r, self);
		draw_line_from_texture(&r, self, i);
		i++;
	}
}

void	render_update(t_self *self)
{
	render_reset(
		&self->mlx.display.screen,
		&self->scene.ceil,
		&self->scene.floor);
	raycast(self);
	cross_draw(self, &self->mlx.display);
}
