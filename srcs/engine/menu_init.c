/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:40:30 by pducos            #+#    #+#             */
/*   Updated: 2022/10/19 21:59:46 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdbool.h>

bool	menu_init(t_self *self)
{
	if (!image_init(&self->mlx,
			&self->mlx.display.menu,
			MINIMAP_X + 10,
			WINDOW_Y))
		return (false);
	
	if (!image_init(&self->mlx,
			&self->mlx.display.menu,
			MINIMAP_X + 10,
			WINDOW_Y))
		return (false);
	return (true);
}
