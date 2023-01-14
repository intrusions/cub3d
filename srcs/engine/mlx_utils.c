/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:40:38 by pducos            #+#    #+#             */
/*   Updated: 2023/01/07 21:39:54 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdlib.h>

void	image_display(t_gui *mlx, t_img *img, int x, int y)
{
	mlx_put_image_to_window(
		mlx->mlx,
		mlx->win,
		img->img,
		x,
		y);
}

void	mlx_destroy_texture(t_self *self)
{
	if (self->scene.wall.no.image.img)
		mlx_destroy_image(
			self->mlx.mlx,
			self->scene.wall.no.image.img);
	if (self->scene.wall.we.image.img)
		mlx_destroy_image(
			self->mlx.mlx,
			self->scene.wall.we.image.img);
	if (self->scene.wall.ea.image.img)
		mlx_destroy_image(
			self->mlx.mlx,
			self->scene.wall.ea.image.img);
	if (self->scene.wall.so.image.img)
		mlx_destroy_image(
			self->mlx.mlx,
			self->scene.wall.so.image.img);
}

void	mlx_destroy(t_self *self)
{
	if (self->mlx.display.minimap.map.img)
		mlx_destroy_image(
			self->mlx.mlx,
			self->mlx.display.minimap.map.img);
	if (self->mlx.display.minimap.minimap.img)
		mlx_destroy_image(
			self->mlx.mlx,
			self->mlx.display.minimap.minimap.img);
	if (self->mlx.display.screen.img)
		mlx_destroy_image(
			self->mlx.mlx,
			self->mlx.display.screen.img);
	if (self->mlx.display.menu.img)
		mlx_destroy_image(
			self->mlx.mlx,
			self->mlx.display.menu.img);
	mlx_destroy_texture(self);
	mlx_destroy_window(self->mlx.mlx, self->mlx.win);
	mlx_destroy_display(self->mlx.mlx);
	free(self->mlx.mlx);
	self->mlx.mlx = NULL;
	self->mlx.win = NULL;
}

void	image_reset(t_img *img, int value)
{
	uint32_t	*ptr;
	size_t		size;

	ptr = (uint32_t *)img->data;
	size = img->width * img->height;
	while (size--)
		*ptr++ = value;
}

void	wrap_mlx_init(t_gui *mlx, int x, int y, char *title)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		mlx->error |= E_MLX_INIT;
	mlx->win = mlx_new_window(mlx->mlx, x, y, title);
	if (!mlx->win)
		mlx->error |= E_MLX_WIN;
}
