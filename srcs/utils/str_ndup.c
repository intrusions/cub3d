/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ndup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:30:51 by pducos            #+#    #+#             */
/*   Updated: 2022/10/02 17:31:13 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

char	*str_ndup(const char *str, size_t size)
{
	char	*new;

	new = malloc (size + 1);
	if (new == NULL)
		return (0);
	new[size] = 0x00;
	while (size--)
		new[size] = str[size];
	return (new);
}
