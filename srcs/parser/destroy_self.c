/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_self.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:34:00 by pducos            #+#    #+#             */
/*   Updated: 2022/10/06 02:32:08 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	destroy_self(t_self *self)
{
	size_t	i;

	i = 0;
	free(self->scene.wall.no);
	free(self->scene.wall.so);
	free(self->scene.wall.we);
	free(self->scene.wall.ea);
	free(self->map.line_size);
	while (i < self->map.size)
		free(self->map.line[i++]);
	free(self->map.line);
}
