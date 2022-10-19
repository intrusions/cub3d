/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:30:51 by pducos            #+#    #+#             */
/*   Updated: 2022/10/08 00:09:47 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <stddef.h>

char	*str_dup(const char *str)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(str_len(str) + 1);
	if (new == NULL)
		return (NULL);
	while (*str)
		new[i++] = *str++;
	new[i] = 0x00;
	return (new);
}
