/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:26:11 by jucheval          #+#    #+#             */
/*   Updated: 2023/01/07 21:03:46 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

static bool	texture_init(void *mlx, t_img *image, char *name)
{
	int	bpp;
	int	size_line;
	int	endian;

	image->img = mlx_xpm_file_to_image(
			mlx,
			name,
			&image->width,
			&image->height);
	if (image->img)
	{
		image->data = (int *)mlx_get_data_addr(
				image->img,
				&bpp,
				&size_line,
				&endian);
		if (bpp == 32 && endian == 0)
			return (true);
	}
	return (false);
}

bool	texture_load(t_self *self)
{
	if (!texture_init(self->mlx.mlx,
			&self->scene.wall.no.image,
			self->scene.wall.no.name))
		self->error |= E_NO_404;
	if (!texture_init(self->mlx.mlx,
			&self->scene.wall.so.image,
			self->scene.wall.so.name))
		self->error |= E_SO_404;
	if (!texture_init(self->mlx.mlx,
			&self->scene.wall.ea.image,
			self->scene.wall.ea.name))
		self->error |= E_EA_404;
	if (!texture_init(self->mlx.mlx,
			&self->scene.wall.we.image,
			self->scene.wall.we.name))
		self->error |= E_WE_404;
	if (self->error)
		return (false);
	return (true);
}
