/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_self.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:34:00 by pducos            #+#    #+#             */
/*   Updated: 2022/10/20 18:21:13 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	destroy_self(t_self *self)
{
	size_t	i;

	i = 0;
	free(self->scene.wall.no.name);
	free(self->scene.wall.so.name);
	free(self->scene.wall.we.name);
	free(self->scene.wall.ea.name);
	free(self->map.line_size);
	while (i < self->map.size)
		free(self->map.line[i++]);
	free(self->map.line);
}
