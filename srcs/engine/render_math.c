/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:57:10 by jucheval          #+#    #+#             */
/*   Updated: 2023/01/09 18:10:12 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define HORIZONTAL       0
#define VERTICAL         1
#define FOV        1.15192

void	compute_initial_values(t_ray *r)
{
	r->current_angle += FOV / RENDER_X;
	r->dir.x = cosf(r->current_angle);
	r->dir.y = sinf(r->current_angle);
	r->delta.x = fabs(1 / r->dir.x);
	r->delta.y = fabs(1 / r->dir.y);
	r->map.x = (int)r->pos.x;
	r->map.y = (int)r->pos.y;
}

void	init_ray(t_ray *r)
{
	if (r->dir.x < 0)
	{
		r->step.x = -1;
		r->len.x = (r->pos.x - r->map.x) * r->delta.x;
	}
	else
	{
		r->step.x = 1;
		r->len.x = (r->map.x + 1.0 - r->pos.x) * r->delta.x;
	}
	if (r->dir.y < 0)
	{
		r->step.y = -1;
		r->len.y = (r->pos.y - r->map.y) * r->delta.y;
	}
	else
	{
		r->step.y = 1;
		r->len.y = (r->map.y + 1.0 - r->pos.y) * r->delta.y;
	}
}

void	perform_dda(t_ray *r)
{
	if (r->len.x < r->len.y)
	{
		r->len.x += r->delta.x;
		r->map.x += r->step.x;
		r->side = HORIZONTAL;
	}
	else
	{
		r->len.y += r->delta.y;
		r->map.y += r->step.y;
		r->side = VERTICAL;
	}
}

void	determine_line_length(t_ray *r, t_self *self)
{
	if (r->side == HORIZONTAL)
		r->line_len = RENDER_Y / (r->len.x - r->delta.x) / \
			cosf(r->current_angle - self->mlx.display.player.a);
	else
		r->line_len = RENDER_Y / (r->len.y - r->delta.y) / \
			cosf(r->current_angle - self->mlx.display.player.a);
	if (r->side == HORIZONTAL)
		r->wall_x = r->pos.y + (r->len.x - r->delta.x) * r->dir.y;
	else
		r->wall_x = r->pos.x + (r->len.y - r->delta.y) * r->dir.x;
	r->wall_x -= floorf(r->wall_x);
}

void	draw_line_from_texture(t_ray *r, t_self *self, int i)
{
	if (r->side == HORIZONTAL)
	{
		if (r->dir.x > 0)
			drawline(&self->mlx.display.screen, &self->scene.wall.so.image, \
				r, i);
		else
			drawline(&self->mlx.display.screen, &self->scene.wall.ea.image, \
				r, i);
	}
	else if (r->side == VERTICAL)
	{
		if (r->dir.y > 0)
			drawline(&self->mlx.display.screen, &self->scene.wall.no.image, \
				r, i);
		else
			drawline(&self->mlx.display.screen, &self->scene.wall.we.image, \
			r, i);
	}
}
