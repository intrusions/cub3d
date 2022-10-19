/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:58:18 by pducos            #+#    #+#             */
/*   Updated: 2022/10/02 16:31:16 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

char	*str_to_uint(char *str, int *result)
{
	long		tmp;

	tmp = 0;
	if (*str == '+')
	{
		str++;
		if (!*str)
			return (str - 1);
	}
	while (*str >= '0' && *str <= '9')
	{
		tmp *= 10;
		tmp += *(str++) & 0xCF;
		if (tmp > INT_MAX)
			return (NULL);
	}
	*result = tmp;
	return (str);
}
