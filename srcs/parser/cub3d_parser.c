/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:01:48 by pducos            #+#    #+#             */
/*   Updated: 2022/10/20 18:21:13 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "reader.h"
#include <stdio.h>
#include <stdlib.h>

static bool	validate_scene(t_self *self)
{
	if (!self->scene.wall.no.name)
		self->error |= E_INVALID_NO;
	if (!self->scene.wall.so.name)
		self->error |= E_INVALID_SO;
	if (!self->scene.wall.we.name)
		self->error |= E_INVALID_WE;
	if (!self->scene.wall.ea.name)
		self->error |= E_INVALID_EA;
	if (self->scene.ceil.r == -1)
		self->error |= E_INVALID_C;
	if (self->scene.floor.r == -1)
		self->error |= E_INVALID_F;
	return (!self->error);
}

static bool	parse_lines(const char *filename, t_self *self)
{
	unsigned char	*line;
	t_reader		*r;
	size_t			size;

	size = 0;
	r = reader_init(filename);
	if (!r)
		return (false);
	report_error("Loading scene...\n");
	self->filename = (char *)filename;
	while (reader(&line, r, "\n") != R_ERROR)
	{
		parse_line(line, self);
		free(line);
		if (++size > DESC_FILE_MAX)
		{
			self->error |= E_DESC_TOO_LARGE;
			break ;
		}
	}
	return (reader_destroy(r), true);
}

bool	cub3d_parser(t_self *self, char *file_name)
{
	if (!alloc((void *)&self->map.line, MAX_MAP_SIZE)
		|| !alloc((void *)&self->map.line_size, MAX_MAP_SIZE * sizeof(int))
		|| !parse_lines(file_name, self)
		|| !validate_scene(self))
		return (false);
	report_error("Loading map...\n");
	if (!self->map.size)
		self->error |= E_MAP_EMPTY;
	else
		parse_map(self);
	return (!self->error);
}
