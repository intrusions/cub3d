/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:45:59 by pducos            #+#    #+#             */
/*   Updated: 2022/10/01 14:51:52 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	*mem_cpy(void *dst, const void *src, size_t n)
{
	uint8_t	*tmp;

	tmp = dst;
	while (n--)
		*(tmp++) = *(uint8_t *)src++;
	return (dst);
}
