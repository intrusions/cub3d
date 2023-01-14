/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <jucheval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:54:18 by jucheval          #+#    #+#             */
/*   Updated: 2022/10/20 19:54:20 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

bool	image_init(t_gui *mlx, t_img *img, int x, int y)
{
	int	bpp;
	int	size_line;
	int	endian;

	img->img = mlx_new_image(mlx->mlx, x, y);
	if (img->img)
	{
		img->width = x;
		img->height = y;
		img->data = (int *)mlx_get_data_addr(
				img->img,
				&bpp,
				&size_line,
				&endian);
		if (bpp == 32 && endian == 0)
			return (true);
	}
	mlx->error |= E_IMG_INIT;
	return (false);
}
