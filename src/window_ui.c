/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:17:29 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/21 12:13:09 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	window_ui_show_controls(t_vars *vars)
{
	mlx_put_string(vars->mlx, "Controls:", 10, 10);
	mlx_put_string(vars->mlx, "WASD to move", 10, 30);
	mlx_put_string(vars->mlx, "Q to rotate", 10, 50);
	mlx_put_string(vars->mlx, "ESC to exit", 10, 70);
	mlx_put_string(vars->mlx, "Scroll to zoom", 10, 90);
	mlx_put_string(vars->mlx, "R to reset", 10, 110);
}

void	update_camera_info(t_vars *vars)
{
	mlx_put_string(vars->mlx, "Camera:", 10, 150);
	mlx_put_string(vars->mlx, "Position:", 10, 170);
	mlx_put_string(vars->mlx, "x:", 130, 170);
	mlx_put_string(vars->mlx, ft_itoa(vars->camera->transform.position.x), 150, 170);
	mlx_put_string(vars->mlx, "y:", 230, 170);
	mlx_put_string(vars->mlx, ft_itoa(vars->camera->transform.position.y), 250, 170);
	mlx_put_string(vars->mlx, "z:", 330, 170);
	mlx_put_string(vars->mlx, ft_itoa(vars->camera->transform.position.y), 350, 170);
	// mlx_put_string(vars->mlx, "Rotation:", 10, 190);
}

void	update_window_ui(t_vars *vars)
{
	window_ui_show_controls(vars);
	update_camera_info(vars);
}