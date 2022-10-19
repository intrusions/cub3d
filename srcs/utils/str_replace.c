/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:45:44 by jucheval          #+#    #+#             */
/*   Updated: 2022/10/06 02:40:12 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	str_replace(char *str, char to_replace, char by)
{
	if (!str)
		return ;
	while (*str)
	{
		if (*str == to_replace)
			*str = by;
		str++;
	}
}
