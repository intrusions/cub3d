/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <jucheval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:54:29 by jucheval          #+#    #+#             */
/*   Updated: 2022/10/20 19:54:30 by jucheval         ###   ########.fr       */
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
	return (true);
}
