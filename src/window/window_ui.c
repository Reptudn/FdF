/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:17:29 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/05 10:19:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	window_ui_show_controls(t_vars *vars)
{
	mlx_put_string(vars->mlx, "Controls:", 10, 10);
	mlx_put_string(vars->mlx, "WASD to move", 10, 30);
	mlx_put_string(vars->mlx, "IJKL to rotate", 10, 50);
	mlx_put_string(vars->mlx, "ESC to exit", 10, 70);
	mlx_put_string(vars->mlx, "Scroll to zoom", 10, 90);
	mlx_put_string(vars->mlx, "R to reset", 10, 110);
}
