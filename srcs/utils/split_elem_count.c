/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_elem_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:11:56 by pducos            #+#    #+#             */
/*   Updated: 2022/10/02 16:26:19 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	split_elem_count(char **split)
{
	size_t	n_elem;

	n_elem = 0;
	while (*split)
	{
		split++;
		n_elem++;
	}
	return (n_elem);
}
