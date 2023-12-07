/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:13:33 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/07 09:34:13 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"
#include <stdio.h>
#include <unistd.h>

void	event_onscroll(double xdelta, double ydelta, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if ((xdelta < 0 || ydelta < 0) && vars->camera->zoom - 0.05 >= 0.1)
		vars->camera->zoom -= 0.05;
	else if ((xdelta > 0 || ydelta > 0) && vars->camera->zoom + 0.05 <= 1.1)
		vars->camera->zoom += 0.05;
	if (vars->camera->zoom == 0)
		vars->camera->zoom = 0.1;
	vars->update = 1;
}

void	event_onmouse(mlx_key_data_t keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode.key == MOUSE_LEFT)
		vars->mouse.button = 1;
	else if (keycode.key == MOUSE_RIGHT)
		vars->mouse.button = 2;
	else if (keycode.key == MOUSE_MIDDLE)
		vars->mouse.button = 3;
	else
		vars->mouse.button = 0;
}

void	event_oncursor_move(double x, double y, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	vars->mouse.prev_x = vars->mouse.x;
	vars->mouse.prev_y = vars->mouse.y;
	vars->mouse.x = x;
	vars->mouse.y = y;
	if (vars->mouse.button == 1)
	{
		vars->map->transform.rotation.y += (y - vars->mouse.prev_y) * 0.01;
		vars->map->transform.rotation.x += (x - vars->mouse.prev_x) * 0.01;
		vars->update = 1;
	}
}
