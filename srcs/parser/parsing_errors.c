/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:35:18 by pducos            #+#    #+#             */
/*   Updated: 2022/10/07 21:51:38 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	texture_error(char *filename, int error)
{
	if (error & E_INVALID_NO)
		report_error("\t%s: %s\n", filename, "Invalid texture: NO");
	if (error & E_INVALID_SO)
		report_error("\t%s: %s\n", filename, "Invalid texture: SO");
	if (error & E_INVALID_WE)
		report_error("\t%s: %s\n", filename, "Invalid texture: WE");
	if (error & E_INVALID_EA)
		report_error("\t%s: %s\n", filename, "Invalid texture: EA");
}

static void	rgb_error(char *filename, int error)
{
	if (error & E_INVALID_C)
		report_error("\t%s: %s\n", filename, "Invalid RGB: C");
	if (error & E_INVALID_F)
		report_error("\t%s: %s\n", filename, "Invalid RGB: F");
	if (error & E_RGB_FIELD_C)
		report_error("\t%s: %s\n", filename, "Incorrect field: C");
	if (error & E_RGB_FIELD_F)
		report_error("\t%s: %s\n", filename, "Incorrect field: F");
}

static void	map_error(char *filename, int error)
{
	if (error & E_INVALID_CHAR)
		report_error("\t%s: %s\n", filename, "Map: invalid character");
	if (error & E_MAP_TOO_LARGE)
		report_error("\t%s: %s\n", filename, "Map: is too large");
	if (error & E_MAP_EMPTY)
		report_error("\t%s: %s\n", filename, "Map: is empty");
	if (error & E_OPEN_MAP)
		report_error("\t%s: %s\n", filename, "Map: is open");
	if (error & E_PLAYER_NUM)
		report_error("\t%s: %s\n", filename, "Map: too many players");
	if (error & E_NO_PLAYERS)
		report_error("\t%s: %s\n", filename, "Map: missing player");
}

void	parsing_errors(t_self *self)
{
	if (self->error)
		report_error("Error\n");
	if (self->error
		& (E_INVALID_NO
			| E_INVALID_SO
			| E_INVALID_WE
			| E_INVALID_EA))
		texture_error(str_basename(self->filename), self->error);
	if (self->error
		& (E_INVALID_C
			| E_INVALID_F
			| E_RGB_FIELD_C
			| E_RGB_FIELD_F))
		rgb_error(str_basename(self->filename), self->error);
	if (self->error
		& (E_INVALID_CHAR
			| E_MAP_TOO_LARGE
			| E_MAP_EMPTY
			| E_PLAYER_NUM
			| E_OPEN_MAP
			| E_NO_PLAYERS))
		map_error(str_basename(self->filename), self->error);
}
