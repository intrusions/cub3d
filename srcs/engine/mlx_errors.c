/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:40:43 by pducos            #+#    #+#             */
/*   Updated: 2022/10/13 14:13:48 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mlx_error(int error)
{
	if (error & E_MLX_INIT)
		report_error("\tMlx: %s\n", "mlx_init(): failed");
	if (error & E_MLX_WIN)
		report_error("\tMlx: %s\n", "mlx_new_window(): failed");
	if (error & E_IMG_INIT)
		report_error("\tMlx: %s\n", "Incorrect image format");
}

void	mlx_errors(int error)
{
	if (error)
		report_error("Error\n");
	mlx_error(error);
}
