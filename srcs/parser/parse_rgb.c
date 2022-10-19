/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:04:15 by pducos            #+#    #+#             */
/*   Updated: 2022/10/07 21:51:38 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	validate_rgb(t_self *self)
{
	if (self->scene.ceil.r > 255
		|| self->scene.ceil.g > 255
		|| self->scene.ceil.b > 255
		|| self->scene.floor.r > 255
		|| self->scene.floor.g > 255
		|| self->scene.floor.b > 255)
		return (false);
	return (true);
}

static t_rgb	*get_rgb_by_type(t_self *self, int type)
{
	if (type == RGB_CEIL_ID)
		return (&self->scene.ceil);
	return (&self->scene.floor);
}

static bool	is_correct_field(t_self *self, const char *str, int type)
{
	if (str_count_char(str, ',') != 2)
	{
		if (type == RGB_CEIL_ID)
			self->error |= E_RGB_FIELD_C;
		else if (type == RGB_FLOOR_ID)
			self->error |= E_RGB_FIELD_F;
		return (false);
	}
	return (true);
}

bool	parse_rgb(t_self *self, const char *str, int type)
{
	char		**s;
	const char	*r[3];
	t_rgb		*rgb;

	rgb = get_rgb_by_type(self, type);
	if (!is_correct_field(self, str, type))
		return (false);
	s = str_split(str, ",");
	if (split_elem_count(s) == 3)
	{
		r[0] = str_to_uint(s[0], &rgb->r);
		r[1] = str_to_uint(s[1], &rgb->g);
		r[2] = str_to_uint(s[2], &rgb->b);
		if ((r[0] && !*r[0]) && (r[1] && !*r[1])
			&& (r[2] && !*r[2]) && validate_rgb(self))
			return (free_2d(s), true);
	}
	rgb->r = -1;
	rgb->g = -1;
	rgb->b = -1;
	return (free_2d(s), false);
}
