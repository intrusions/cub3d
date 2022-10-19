/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:36:40 by pducos            #+#    #+#             */
/*   Updated: 2022/10/08 00:14:59 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	str_is_empty(unsigned char *str)
{
	while (*str)
	{
		if (*str != ' '
			|| *str != '\n'
			|| *str != '\t')
			return (false);
		str++;
	}
	return (true);
}
