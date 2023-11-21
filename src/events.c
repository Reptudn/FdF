/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:12:31 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/21 13:04:19 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	event_onresize(int x, int y, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	vars->update = 1;
	vars->window_width = x;
	vars->window_height = y;
}

void	event_onkey(mlx_key_data_t keycode, void *param)
{
	t_vars	*vars;

	ft_printf("Key Keycode: %d\n", keycode.key);
	vars = (t_vars *)param;
	if (keycode.key == 256)
	{
		vars->run = 0;
		exit(0);
	}
	else if (keycode.key == MLX_KEY_W)
		camera_move(vars->camera, (t_transform){(t_vector3){0, 50, 0, "white"},
			(t_quaternion){0, 0, 0, 0}});
	else if (keycode.key == MLX_KEY_S)
		camera_move(vars->camera, (t_transform){(t_vector3){0,  -50, 0, "white"},
			(t_quaternion){0, 0, 0, 0}});
	else if (keycode.key == MLX_KEY_D)
		camera_move(vars->camera, (t_transform){(t_vector3){-50, 0, 0, "white"},
			(t_quaternion){0, 0, 0, 0}});
	else if (keycode.key == MLX_KEY_A)
		camera_move(vars->camera, (t_transform){(t_vector3){50, 0, 0, "white"},
			(t_quaternion){0, 0, 0, 0}});
	else if (keycode.key == MLX_KEY_R)
		vars->camera->transform = (t_transform){(t_vector3){200, 300, 0, "white"},
			(t_quaternion){0, 0, 0, 0}};
	else if (keycode.key == MLX_KEY_Q)
		camera_move(vars->camera, (t_transform){(t_vector3){0, 0, 0, "white"},
			(t_quaternion){0, 10, 0, 10}});
	else if (keycode.key == MLX_KEY_E)
		camera_move(vars->camera, (t_transform){(t_vector3){0, 0, 0, "white"},
			(t_quaternion){0, -10, 0, -10}});
	vars->update = 1;
}

void	event_onscroll(double xdelta, double ydelta, void *param)
{
	t_vars	*vars;
	double	zoom_factor;

	zoom_factor = 1.5;
	vars = (t_vars *)param;
	vars->update = 1;
	if (ydelta > 0)
	{
		camera_move(vars->camera, (t_transform){(t_vector3){0, 0, zoom_factor, "white"},
			(t_quaternion){0, 0, 0, 0}});
	}
	else if (ydelta < 0)
	{
		camera_move(vars->camera, (t_transform){(t_vector3){0, 0, -zoom_factor, "white"},
			(t_quaternion){0, 0, 0, 0}});
	}
	xdelta++;
}

void	event_onmouse(mlx_key_data_t keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	printf("Mouse Keycode: %d\n", keycode.key);
	vars->update = 1;
}
