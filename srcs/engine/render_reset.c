/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:40:34 by pducos            #+#    #+#             */
/*   Updated: 2022/10/16 10:47:03 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	__memset(int32_t *m, int32_t c, size_t size)
{
	while (size--)
		*(m++) = c;
}

void	render_reset(t_img *img, t_rgb *ceil, t_rgb *floor)
{
	__memset(
		img->data,
		ceil->r << 16
		| ceil->g << 8
		| ceil->b,
		(img->height * img->width) >> 1);
	__memset(
		img->data + (img->height * img->width >> 1),
		floor->r << 16
		| floor->g << 8
		| floor->b,
		(img->height * img->width) >> 1);
}

