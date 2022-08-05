/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:58:05 by jucheval          #+#    #+#             */
/*   Updated: 2022/08/05 02:01:28 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	p_parse_name(char *str, t_parsing_errors *errors)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	extension = ".cub";
	while (str[i])
	{
		j = 0;
		while (str[i] == extension[j] && extension[j] && str[i])
		{
			i++;
			j++;
		}
		if (!str[i] && !extension[j])
			return (0);
		i++;
	}
	return (errors->map_name = 1, 1);
}


int	p_start_parsing(char *str, t_parsing_errors *errors)
{
	int	count_errors;

	count_errors = 0;
	count_errors += p_parse_name(str, errors);

	return (count_errors == 0);
}