/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name_and_get_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 03:05:57 by jucheval          #+#    #+#             */
/*   Updated: 2022/08/05 03:10:30 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	p_count_line_in_file(char *argv, t_parsing_errors *errors)
{
	char	*str;
	int		fd;
	size_t	count;

	count = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (errors->incorrect_fd = 1, 0);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}

char    **p_get_file(char *file, t_parsing_errors *errors)
{
	char	**map;
	size_t	size;
	size_t	i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (errors->incorrect_fd = 1, NULL);
	size = p_count_line_in_file(file, errors);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i <= size)
		map[i++] = get_next_line(fd);
	close(fd);
	return (map);
}

int	p_parse_name(char *str, t_parsing_errors *errors)
{
	size_t	i;
	size_t	j;
	char	*extension;

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
		if ((!str[i] && !extension[j]) && (i > 4))
			return (0);
		i++;
	}
	return (errors->map_name = 1, 1);
}
