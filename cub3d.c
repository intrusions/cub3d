/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:57:32 by jucheval          #+#    #+#             */
/*   Updated: 2022/08/05 03:08:28 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	u_initialise_struct(t_parsing_errors *errors, t_global_data *data)
{
	errors->data = data;
	errors->map_name = 0;
	errors->incorrect_fd = 0;
}

int	main(int ac, char **av)
{
	t_parsing_errors	errors;
	t_global_data		data;

	u_initialise_struct(&errors, &data);
	if (ac > 1)
	{
		if (p_start_parsing(av[1], &errors))
			printf("play_games");
		else
			u_print_errors(&errors);
	}
	else
		printf("The path of map is not present in arguments\n");
}