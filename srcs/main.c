/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:53:22 by pducos            #+#    #+#             */
/*   Updated: 2022/11/11 20:24:24 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <stdio.h>

static void	usage_error(char *exec_name)
{
	report_error("%s: Usage error\n", exec_name);
	report_error("Usage: %s <cub_file>\n", exec_name);
}

static bool	is_cub_file(const char *filename)
{
	size_t	len;

	len = str_len(filename);
	if (len < 4
		|| str_cmp(".cub", filename + len - 4))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_self	self;
	bool	parsing_only;

	parsing_only = false;
	if (ac == 3
		&& !str_cmp(av[1], "--parsing-only")
		&& av++)
		parsing_only = true;
	else if (ac != 2 || !is_cub_file(av[1]))
		return (usage_error(av[0]), EXIT_FAILURE);
	mem_set(&self, 0x00, sizeof(t_self));
	mem_set(&self.scene.ceil, -1, sizeof(t_rgb) * 2);
	if (!cub3d_parser(&self, av[1]))
		return (parsing_errors(&self),
			destroy_self(&self),
			report_error("Quitting...\n"), EXIT_FAILURE);
	if (parsing_only)
		return (destroy_self(&self), EXIT_SUCCESS);
	start_game(&self);
	if (self.mlx.error)
		return (mlx_errors(self.mlx.error),
			report_error("Quitting...\n"),
			destroy_self(&self), EXIT_FAILURE);
	return (report_error("Quitting...\n"),
		destroy_self(&self), EXIT_SUCCESS);
}
