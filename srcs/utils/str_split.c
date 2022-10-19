/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:07:15 by pducos            #+#    #+#             */
/*   Updated: 2022/10/08 00:13:25 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>
#include <stdlib.h>

static int	is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (true);
		sep++;
	}
	return (false);
}

static size_t	count_words(char const *s, char *sep)
{
	size_t	wrds;

	wrds = 0;
	while (*s)
	{
		while (*s && is_sep(*s, sep))
			s++;
		if (*s)
			wrds++;
		while (*s && !is_sep(*s, sep))
			s++;
	}
	return (wrds);
}

char	**str_split(char const *s, char *sep)
{
	char	**split;
	size_t	wrd;
	size_t	size;

	size = count_words(s, sep);
	split = (char **)malloc (sizeof(char *) * (size + 1));
	if (split == NULL)
		return (NULL);
	while (*s && is_sep(*s, sep))
		s++;
	while (*s)
	{
		wrd = 0;
		while (s[wrd] && (!is_sep(s[wrd], sep)))
			wrd++;
		if (wrd)
		{
			*(split++) = str_ndup(s, wrd);
			s += wrd;
		}
		else
			s++;
	}
	*split = NULL;
	return (split - size);
}
