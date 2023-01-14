/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyrelease.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <jucheval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:54:12 by jucheval          #+#    #+#             */
/*   Updated: 2022/10/20 19:54:14 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>

int	handle_keyrelease(long k, t_self *self)
{
	if (k == KEY_LEFT)
		self->keys.left = false;
	else if (k == KEY_RIGHT)
		self->keys.right = false;
	else if (k == KEY_W)
		self->keys.w = false;
	else if (k == KEY_A)
		self->keys.a = false;
	else if (k == KEY_S)
		self->keys.s = false;
	else if (k == KEY_D)
		self->keys.d = false;
	else if (k == 65505)
		self->keys.shift = false;
	else if (k == 32)
		self->keys.space = false;
	return (0);
}
