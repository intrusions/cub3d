/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:40:47 by pducos            #+#    #+#             */
/*   Updated: 2022/10/19 18:28:37 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>

static void	__move(t_self *self, float x, float y)
{
	if (self->map.line
		[(int)(self->mlx.display.player.y + y)]
		[(int)(self->mlx.display.player.x + x)] != '1')
	{
		self->mlx.display.player.x += x;
		self->mlx.display.player.y += y;
	}
}

int	handle_key(long k, t_self *self)
{
	if (k == KEY_ESC)
		quit_game(&self->mlx);
	else if (k == KEY_LEFT)
		self->mlx.display.player.a -= (M_PI * 2) / 128;
	else if (k == KEY_RIGHT)
		self->mlx.display.player.a += (M_PI * 2) / 128;
	else if (k == KEY_DOWN)
		__move(
			self,
			-cos(self->mlx.display.player.a) / CUBE_SIZE, // CAH SOH TOA
			-sin(self->mlx.display.player.a) / CUBE_SIZE);
	else if (k == KEY_UP)
		__move(
			self,
			cos(self->mlx.display.player.a) / CUBE_SIZE,
			sin(self->mlx.display.player.a) / CUBE_SIZE);
	return (0);
}
