/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <jucheval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:54:06 by jucheval          #+#    #+#             */
/*   Updated: 2022/10/20 19:54:08 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>

int	handle_keypress(long k, t_self *self)
{
	if (k == KEY_ESC)
		quit_game(&self->mlx);
	else if (k == KEY_LEFT)
		self->keys.left = true;
	else if (k == KEY_RIGHT)
		self->keys.right = true;
	else if (k == KEY_W)
		self->keys.w = true;
	else if (k == KEY_A)
		self->keys.a = true;
	else if (k == KEY_S)
		self->keys.s = true;
	else if (k == KEY_D)
		self->keys.d = true;
	else if (k == 65505)
		self->keys.shift = true;
	else if (k == 32)
		self->keys.space = true;
	return (0);
}
