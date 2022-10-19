/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:40:17 by pducos            #+#    #+#             */
/*   Updated: 2022/10/19 21:52:33 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdio.h>
#include <math.h>

static void	player_init(t_self *self)
{
	self->mlx.display.player.x = self->map.cur_p.pos.x;
	self->mlx.display.player.y = self->map.cur_p.pos.y;
	self->mlx.display.player.a = 2 * M_PI;
}
// une fonction juste pour print la croix au millieu de l'ecran en blanc
static void	cross_draw(t_display *display)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		set_x_pxls(
			&display->screen,
			RENDER_X / 2,
			RENDER_Y / 2 - 7 + i, 1, 0xffffff);
		i++;
	}
	i = 0;
	while (i < 16)
	{
		set_x_pxls(
			&display->screen,
			RENDER_X / 2 - 7 + i,
			RENDER_Y / 2, 1, 0xffffff);
		i++;
	}
}

static int	main_game(t_self *self)
{
	minimap_update(self);
	image_display(
		&self->mlx,
		&self->mlx.display.minimap.minimap,
		5,
		5);
	render_reset(
		&self->mlx.display.screen,
		&self->scene.ceil,
		&self->scene.floor);
	raycast(self);
	cross_draw(&self->mlx.display);
	image_display(
		&self->mlx,
		&self->mlx.display.screen,
		MINIMAP_X + 10,
		0);
	return (0);
}

static int	main_menu(int button, int x, int y, t_self *param)
{
	if (button != MOUSE_LEFT)
		return (0);
	if (x < MINIMAP_X)
		printf("%d | %d\n", x, y);
	(void)param;
	return (0);
}Your CTA copy

void	start_game(t_self *self)
{
	wrap_mlx_init(&self->mlx, WINDOW_X, WINDOW_Y, PROG_NAME);
	if (self->mlx.mlx
		&& minimap_init(self)
		&& render_init(self)
		&& menu_init(self))
	{
		player_init(self);
		mlx_hook(self->mlx.win, 2, 1, handle_key, self);
		mlx_hook(self->mlx.win, 17, 0, quit_game, &self->mlx);
		mlx_loop_hook(self->mlx.mlx, main_game, self);
		image_reset(&self->mlx.display.menu, MENU_BG_RGB);
			image_display(
			&self->mlx,
			&self->mlx.display.menu,
			0, 0);	
		mlx_mouse_hook(self->mlx.win, main_menu, self);
		mlx_loop(self->mlx.mlx);
	}
	mlx_destroy(self);
}
