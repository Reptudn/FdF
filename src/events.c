/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:12:31 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/20 15:22:34 by jkauker          ###   ########.fr       */
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

	ft_printf("Key Keycode: %d\n", keycode.key);
	vars = (t_vars *)param;
	if (keycode.key == 256)
	{
		vars->run = 0;
		exit(0);
	}
	else if (keycode.key == MLX_KEY_W)
		camera_move(vars->camera, (t_transform){(t_vector3){0, (5 * vars->draw_size), 0, "white"},
			(t_quaternion){0, 0, 0, 0}});
	else if (keycode.key == MLX_KEY_S)
		camera_move(vars->camera, (t_transform){(t_vector3){0, -(5 * vars->draw_size), 0, "white"},
			(t_quaternion){0, 0, 0, 0}});
	else if (keycode.key == MLX_KEY_D)
		camera_move(vars->camera, (t_transform){(t_vector3){-(5 * vars->draw_size), 0, 0, "white"},
			(t_quaternion){0, 0, 0, 0}});
	else if (keycode.key == MLX_KEY_A)
		camera_move(vars->camera, (t_transform){(t_vector3){(5 * vars->draw_size), 0, 0, "white"},
			(t_quaternion){0, 0, 0, 0}});
	else if (keycode.key == MLX_KEY_Q)
		vars->map->transform.rotation.w += 100;
	vars->update = 1;
}

void	event_onscroll(double xdelta, double ydelta, void *param)
{
	t_vars	*vars;
	double	zoom_factor;

	zoom_factor = 5.0;
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

	ft_printf("[printf] Mouse Keycode: %d\n", keycode.key);
	vars = (t_vars *)param;
	vars->update = 1;
}
