/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:08:15 by pducos            #+#    #+#             */
/*   Updated: 2022/10/26 16:15:27 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

static void	save_value(char **where, const char *val)
{
	if (*where)
		free(*where);
	*where = str_dup((char *)val);
}

static void	fill_for_known_key(char **split, t_self *self)
{
	const char	*key = split[0];
	const char	*val = split[1];

	if (split_elem_count(split) == 2)
	{
		if (!str_cmp(key, "NO"))
			save_value(&self->scene.wall.no.name, val);
		if (!str_cmp(key, "SO"))
			save_value(&self->scene.wall.so.name, val);
		if (!str_cmp(key, "WE"))
			save_value(&self->scene.wall.we.name, val);
		if (!str_cmp(key, "EA"))
			save_value(&self->scene.wall.ea.name, val);
		if (!str_cmp(key, "F"))
			parse_rgb(self, val, RGB_FLOOR_ID);
		if (!str_cmp(key, "C"))
			parse_rgb(self, val, RGB_CEIL_ID);
	}
}

static bool	got_all_keys(t_self *self)
{
	if (self->scene.wall.no.name
		&& self->scene.wall.so.name
		&& self->scene.wall.ea.name
		&& self->scene.wall.we.name
		&& self->scene.ceil.r != -1
		&& self->scene.floor.r != -1)
		return (true);
	return (false);
}

void	parse_line(unsigned char *line, t_self *self)
{
	char		**s;
	int			line_size;
	static int	i;

	if (i == 0 && !got_all_keys(self))
	{
		if (str_is_empty(line))
			return ;
		s = str_split((char *)line, " \t");
		if (s)
		{
			fill_for_known_key(s, self);
			free_2d(s);
		}
	}
	else
	{
		line_size = str_len((char *)line);
		if (line_size > self->map.max)
			self->map.max = line_size;
		self->map.line[i] = str_dup((char *)line);
		self->map.line_size[i] = line_size;
		self->map.size = ++i;
	}
}
