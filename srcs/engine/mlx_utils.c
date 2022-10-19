/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:40:38 by pducos            #+#    #+#             */
/*   Updated: 2022/10/16 10:33:03 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdlib.h>

static inline void	set_pxl(t_img *img, int x, int y, int color)
{
	*(img->data + (y * img->width) + x) = color;
}

void	set_x_pxls(t_img *img, int x, int y, int n, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= n
		&& y + i < img->height)
	{
		j = 0;
		while (j <= n
			&& x + j < img->width)
		{
			set_pxl(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	image_display(t_gui *mlx, t_img *img, int x, int y)
{
	mlx_put_image_to_window(
		mlx->mlx,
		mlx->win,
		img->img,
		x,
		y);
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
