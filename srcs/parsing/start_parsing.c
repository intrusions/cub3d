/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:58:05 by jucheval          #+#    #+#             */
/*   Updated: 2022/08/05 03:18:26 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_file(char **file)
{
	for (int i = 0; file[i]; i++)
		printf("%s", file[i]);
}

int	p_start_parsing(char *str, t_parsing_errors *errors)
{
	int	count_errors;

	count_errors = 0;
	count_errors += p_parse_name(str, errors);
	errors->data->file = p_get_file(str, errors);
	if (!errors->data->file)
		return (0);
	// print_file(errors->data->file);

	return (count_errors == 0);
}