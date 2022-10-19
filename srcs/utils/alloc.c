/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:22:14 by pducos            #+#    #+#             */
/*   Updated: 2022/10/04 19:55:05 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

bool	alloc(uint8_t **ptr, size_t size)
{
	uint8_t	*s;

	*ptr = malloc(size);
	if (!*ptr)
		return (false);
	s = *ptr;
	while (size--)
		*(s++) = 0x00;
	return (true);
}
