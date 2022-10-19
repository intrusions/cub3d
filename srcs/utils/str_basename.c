/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_basename.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:30:29 by pducos            #+#    #+#             */
/*   Updated: 2022/10/08 00:09:12 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*str_rchr(const char *s, int c)
{
	char	*loc;

	loc = 0;
	while (*s)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			loc = (char *)s;
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (loc);
}

char	*str_basename(char *str)
{
	char	*tmp;

	tmp = str_rchr(str, '/');
	if (tmp && tmp[1])
		return (tmp + 1);
	return (str);
}
