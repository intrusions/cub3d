/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:40:17 by pducos            #+#    #+#             */
/*   Updated: 2022/11/17 22:16:18 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdio.h>
#include <math.h>

static int	main_game(t_self *self)
{
	do_moving(self);
	minimap_update(self);
	image_display(
		&self->mlx,
		&self->mlx.display.minimap.minimap,
		5, 5);
	render_update(self);
	image_display(
		&self->mlx,
		&self->mlx.display.screen,
		MINIMAP_X + 10, 0);
	return (0);
}

static void	player_init(t_self *self)
{
	self->mlx.display.player.x = self->map.cur_p.pos.x;
	self->mlx.display.player.y = self->map.cur_p.pos.y;
	if (self->map.cur_p.val == 'N')
		self->mlx.display.player.a = 1.5 * M_PI;
	else if (self->map.cur_p.val == 'S')
		self->mlx.display.player.a = 0.5 * M_PI;
	else if (self->map.cur_p.val == 'E')
		self->mlx.display.player.a = 2 * M_PI;
	else if (self->map.cur_p.val == 'W')
		self->mlx.display.player.a = M_PI;
}

void	start_game(t_self *self)
{
	wrap_mlx_init(&self->mlx, WINDOW_X, WINDOW_Y, PROG_NAME);
	mlx_do_key_autorepeatoff(self->mlx.mlx);
	if (self->mlx.mlx
		&& minimap_init(self)
		&& render_init(self)
		&& menu_init(self)
		&& texture_load(self))
	{
		report_error("Starting game...\n");
		player_init(self);
		mlx_hook(self->mlx.win, 2, 1, handle_keypress, self);
		mlx_hook(self->mlx.win, 3, 2, handle_keyrelease, self);
		mlx_hook(self->mlx.win, 17, 0, quit_game, &self->mlx);
		image_reset(&self->mlx.display.menu, MENU_BG_RGB);
		image_display(
			&self->mlx,
			&self->mlx.display.menu,
			0, 0);
		mlx_loop_hook(self->mlx.mlx, main_game, self);
		mlx_loop(self->mlx.mlx);
	}
	else
		engine_errors(self);
	mlx_do_key_autorepeaton(self->mlx.mlx);
	mlx_destroy(self);
}
