/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:12:31 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/10 14:03:20 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	event_onresize(int x, int y, void *param)
{
	t_vars	*vars;

	ft_printf("[printf] Resize to x: %d\ty: %d \n", x, y);
	vars = (t_vars *)param;
	vars->update = 1;
	vars->window_width = x;
	vars->window_height = y;
}

void	event_onkey(mlx_key_data_t keycode, void *param)
{
	t_vars	*vars;

	ft_printf("[printf] Key Keycode: %d\n", keycode.key);
	vars = (t_vars *)param;
	if (keycode.key == 53)
		vars->run = 0;
	else if (keycode.key == MLX_KEY_W)
		camera_move(vars->camera, (t_transform){(t_vector3){0, 1, 0},
			(t_quaternion){0, 0, 0, 0}});
	else if (keycode.key == MLX_KEY_S)
		camera_move(vars->camera, (t_transform){(t_vector3){0, -1, 0},
			(t_quaternion){0, 0, 0, 0}});
	vars->update = 1;
}

void	event_onmouse(mlx_key_data_t keycode, void *param)
{
	t_vars	*vars;

	ft_printf("[printf] Mouse Keycode: %d\n", keycode.key);
	vars = (t_vars *)param;

}

