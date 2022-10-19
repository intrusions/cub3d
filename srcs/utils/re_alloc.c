/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:17:28 by pducos            #+#    #+#             */
/*   Updated: 2022/10/01 15:07:31 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

bool	re_alloc(void **buf, size_t *cap, size_t len, size_t new_cap)
{
	void	*new_buf;

	if (!alloc(&new_buf, new_cap))
		return (false);
	mem_cpy(new_buf, *buf, len);
	free(*buf);
	*buf = new_buf;
	*cap = new_cap;
	return (true);
}
