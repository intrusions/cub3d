/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:00:39 by jucheval          #+#    #+#             */
/*   Updated: 2022/11/11 20:27:14 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	texture_not_found_error(char *filename, int error)
{
	if (error & E_NO_404)
		report_error("\t%s: %s\n", filename, "Engine: NO texture not found");
	if (error & E_SO_404)
		report_error("\t%s: %s\n", filename, "Engine: SO texture not found");
	if (error & E_EA_404)
		report_error("\t%s: %s\n", filename, "Engine: EA texture not found");
	if (error & E_WE_404)
		report_error("\t%s: %s\n", filename, "Engine: WE texture not found");
}

void	engine_errors(t_self *self)
{
	if (self->error)
		report_error("Error\n");
	if (self->error
		& (E_NO_404
			| E_SO_404
			| E_EA_404
			| E_WE_404))
		texture_not_found_error(str_basename(self->filename), self->error);
}
