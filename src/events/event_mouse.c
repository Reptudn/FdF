/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:13:33 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/24 09:14:41 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	event_onscroll(double xdelta, double ydelta, void *param)
{
	t_vars	*vars;
	double	zoom_factor;

	zoom_factor = 1.5;
	vars = (t_vars *)param;
	if (ydelta < 0)
	{
		if (vars->camera->transform.position.x - zoom_factor < 0)
			return ;
		camera_move(vars->camera, (t_transform){(t_vector3){0, 0, -zoom_factor, 0},
			(t_quaternion){0, 0, 0, 0}});
		// map_move((t_vector3){0, 0, zoom_factor , 0}, vars->map);
		// vars->draw_size += 0.1;
	}
	else if (ydelta > 0)
	{
		camera_move(vars->camera, (t_transform){(t_vector3){0, 0, zoom_factor, 0},
			(t_quaternion){0, 0, 0, 0}});
		// map_move((t_vector3){0, 0, -zoom_factor , 0}, vars->map);
		// vars->draw_size -= 0.1;
	}
	if (xdelta > 0)
	{
		camera_move(vars->camera, (t_transform){(t_vector3){-zoom_factor, 0, 0, 0},
			(t_quaternion){0, 0, 0, 0}});
	}
	else if (xdelta < 0)
	{
		camera_move(vars->camera, (t_transform){(t_vector3){zoom_factor, 0, 0, 0},
			(t_quaternion){0, 0, 0, 0}});
	}
	vars->update = 1;
}

void	event_onmouse(mlx_key_data_t keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	printf("Mouse Keycode: %d\n", keycode.key);
	if (keycode.key == MOUSE_LEFT)
	{
		vars->map->transform.rotation.x += 10;
	}
	vars->update = 1;
}