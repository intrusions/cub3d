/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:40:30 by pducos            #+#    #+#             */
/*   Updated: 2022/10/16 10:27:29 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdbool.h>

bool	render_init(t_self *self)
{
	if (!image_init(&self->mlx,
			&self->mlx.display.screen,
			RENDER_X,
			RENDER_Y))
		return (false);
	return (true);
}
