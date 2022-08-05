/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:58:05 by jucheval          #+#    #+#             */
/*   Updated: 2022/08/05 05:26:33 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	p_start_parsing(char *str, t_parsing_errors *errors)
{
	int	count_errors;

	count_errors = 0;
	count_errors += p_parse_name(str, errors);
	errors->data->file = p_get_file(str, errors);
	if (!errors->data->file)
		return (0);
	// p_find_path_img(errors);
	// print_file(errors->data->file);
	return (count_errors == 0);
}