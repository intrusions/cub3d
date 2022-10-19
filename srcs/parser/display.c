/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 01:00:17 by pducos            #+#    #+#             */
/*   Updated: 2022/10/07 20:01:53 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	display_map(char **map, size_t map_size)
{
	while (map_size-- + 1)
	{
		if (*map && **map)
			printf("'%s'\n", *map);
		map++;
	}
}

void	display_parsed(t_self *self)
{
	printf("\n\tNO = '%s'\n", self->scene.wall.no);
	printf("\tSO = '%s'\n", self->scene.wall.so);
	printf("\tWE = '%s'\n", self->scene.wall.we);
	printf("\tEA = '%s'\n\n", self->scene.wall.ea);
	printf("\tC  = %3d, %3d, %3d\n", self->scene.ceil.r,
		self->scene.ceil.g,
		self->scene.ceil.b);
	printf("\tF  = %3d, %3d, %3d\n\n", self->scene.floor.r,
		self->scene.floor.g,
		self->scene.floor.b);
}
