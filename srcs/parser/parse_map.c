/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:18:06 by pducos            #+#    #+#             */
/*   Updated: 2022/10/14 22:12:16 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	reset_map(t_self *self)
{
	size_t	i;

	i = 0;
	while (i < self->map.size)
	{
		str_replace(self->map.line[i], ' ', '0');
		i++;
	}
}

static size_t	get_players(t_self *self, t_player *p)
{
	size_t	x;
	size_t	y;
	size_t	n;

	n = 0;
	y = 0;
	while (self->map.line[y])
	{
		x = 0;
		while (self->map.line[y][x])
		{
			if (is_player(self->map.line[y][x]))
			{
				p[n].pos.x = x;
				p[n].pos.y = y;
				p[n].val = self->map.line[y][x];
				n++;
			}
			x++;
		}
		y++;
	}
	if (n == 0)
		self->error |= E_NO_PLAYERS;
	return (n);
}

static void	check_map(t_self *self, int x, int y)
{
	if (!x || !y
		|| (size_t)y > self->map.size
		|| !self->map.line[y][x + 1]
		|| x >= self->map.line_size[y - 1]
		|| x >= self->map.line_size[y + 1])
	{
		self->error |= E_OPEN_MAP;
		return ;
	}
	if (!check_adjacent(self, x, y))
		return ;
	self->map.line[y][x] = ' ';
	if (self->map.line[y][x + 1] == '0')
		check_map(self, x + 1, y);
	if (self->map.line[y][x - 1] == '0')
		check_map(self, x - 1, y);
	if (self->map.line[y + 1][x] == '0')
		check_map(self, x, y + 1);
	if (self->map.line[y - 1][x] == '0')
		check_map(self, x, y - 1);
}

void	parse_map(t_self *self)
{
	size_t		i;
	size_t		n_players;
	t_player	p[10];

	n_players = get_players(self, p);
	if (self->error & E_NO_PLAYERS)
		return ;
	i = 0;
	while (n_players--)
	{
		self->map.cur_p = p[i];
		reset_map(self);
		check_map(self, p[i].pos.x, p[i].pos.y);
		self->map.line \
			[(int)self->map.cur_p.pos.y] \
			[(int)self->map.cur_p.pos.x] \
			= self->map.cur_p.val;
		if (self->error == 0)
			return ;
		if (n_players)
			self->error &= \
				~(E_OPEN_MAP | E_INVALID_CHAR | E_PLAYER_NUM);
		i++;
	}
}
