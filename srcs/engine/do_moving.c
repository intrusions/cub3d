/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moving.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:53:58 by jucheval          #+#    #+#             */
/*   Updated: 2022/11/11 20:28:20 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "math.h"

static void	__move(t_self *self, float x, float y)
{
	if (self->map.line
		[(int)(self->mlx.display.player.y)]
		[(int)(self->mlx.display.player.x + x)] != '1')
		self->mlx.display.player.x += x;
	if (self->map.line
		[(int)(self->mlx.display.player.y + y)]
		[(int)(self->mlx.display.player.x)] != '1')
		self->mlx.display.player.y += y;
}

void	do_moving(t_self *self)
{
	int	speed;

	speed = SPEED;
	if (self->keys.shift)
		speed = SPEED / 2;
	if (self->keys.left)
		self->mlx.display.player.a -= SENSITIVITY;
	if (self->keys.right)
		self->mlx.display.player.a += SENSITIVITY;
	if (self->keys.w)
		__move(self,
			cosf(self->mlx.display.player.a) / speed,
			sinf(self->mlx.display.player.a) / speed);
	if (self->keys.s)
		__move(self,
			-cosf(self->mlx.display.player.a) / speed,
			-sinf(self->mlx.display.player.a) / speed);
	if (self->keys.a)
		__move(self,
			cosf(self->mlx.display.player.a - 1.5708) / speed,
			sinf(self->mlx.display.player.a - 1.5708) / speed);
	if (self->keys.d)
		__move(self,
			cosf(self->mlx.display.player.a + 1.5708) / speed,
			sinf(self->mlx.display.player.a + 1.5708) / speed);
}
