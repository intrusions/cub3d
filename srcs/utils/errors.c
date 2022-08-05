/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:24:59 by jucheval          #+#    #+#             */
/*   Updated: 2022/08/05 03:08:09 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	u_print_errors(t_parsing_errors *errors)
{
	printf("Errors\n");
	if (errors->map_name)
		printf("File name of the map are not endend by a \".cub\"\n");
	if (errors->incorrect_fd)
		printf("Incorrect file descriptor\n");
}
