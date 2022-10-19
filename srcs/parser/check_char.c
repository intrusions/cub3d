/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:38:01 by pducos            #+#    #+#             */
/*   Updated: 2022/10/07 21:51:38 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_player(char c)
{
	if (c == 'N'
		|| c == 'S'
		|| c == 'W'
		|| c == 'E')
		return (true);
	return (false);
}

bool	char_ok(char c, t_self *self)
{
	if (is_player(c))
	{
		self->error |= E_PLAYER_NUM;
		return (false);
	}
	if (c != '0'
		&& c != '1'
		&& c != ' ')
	{
		self->error |= E_INVALID_CHAR;
		return (false);
	}
	return (true);
}

bool	check_adjacent(t_self *self, int x, int y)
{
	if (!char_ok(self->map.line[y][x + 1], self)
		|| !char_ok(self->map.line[y][x - 1], self)
		|| !char_ok(self->map.line[y + 1][x], self)
		|| !char_ok(self->map.line[y - 1][x], self))
		return (false);
	return (true);
}
