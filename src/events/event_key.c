/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:12:52 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/24 14:38:08 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	rotation(mlx_key_data_t keycode, t_vars *vars)
{
	// if (keycode.key == MLX_KEY_I)
	// 	camera_move(vars->camera, (t_transform){(t_vector3){0, 50, 0, 0},
	// 		(t_quaternion){0, 0, 0, 0}});
	// if (keycode.key == MLX_KEY_K)
	// 	camera_move(vars->camera, (t_transform){(t_vector3){0,  -50, 0, 0},
	// 		(t_quaternion){0, 0, 0, 0}});
	// if (keycode.key == MLX_KEY_J)
	// 	camera_move(vars->camera, (t_transform){(t_vector3){-50, 0, 0, 0},
	// 		(t_quaternion){0, 0, 0, 0}});
	// if (keycode.key == MLX_KEY_L)
	// 	camera_move(vars->camera, (t_transform){(t_vector3){50, 0, 0, 0},
	// 		(t_quaternion){0, 0, 0, 0}});
	if (keycode.key == MLX_KEY_I)
		map_rotate(200, (t_vector3){100, 0, 0, 0}, vars->map);
	if (keycode.key == MLX_KEY_K)
		map_rotate(-200, (t_vector3){100, 0, 0, 0}, vars->map);
	if (keycode.key == MLX_KEY_J)
		map_rotate(200, (t_vector3){0, 100, 0, 0}, vars->map);
	if (keycode.key == MLX_KEY_L)
		map_rotate(-200, (t_vector3){0, 100, 0, 0}, vars->map);
	if (keycode.key == MLX_KEY_I || keycode.key == MLX_KEY_K
		|| keycode.key == MLX_KEY_J || keycode.key == MLX_KEY_L)
		vars->update = 1;
}

void	movement(mlx_key_data_t keycode, t_vars *vars)
{
	if (keycode.key == MLX_KEY_W)
		map_move((t_vector3){0, 50, 0 , 0}, vars->map);
	if (keycode.key == MLX_KEY_S)
		map_move((t_vector3){0, -50, 0 , 0}, vars->map);
	if (keycode.key == MLX_KEY_A)
		map_move((t_vector3){50, 0, 0 , 0}, vars->map);
	if (keycode.key == MLX_KEY_D)
		map_move((t_vector3){-50, 0, 0 , 0}, vars->map);
	if (keycode.key == MLX_KEY_W || keycode.key == MLX_KEY_S
		|| keycode.key == MLX_KEY_A || keycode.key == MLX_KEY_D)
		vars->update = 1;
}

void	utilities(mlx_key_data_t keycode, t_vars *vars)
{
		if (keycode.key == MLX_KEY_R)
		{
			vars->camera->transform = (t_transform){(t_vector3){200, 300, 0, 0},
				(t_quaternion){0, 0, 0, 0}};
			vars->update = 1;
		}
		if (keycode.key == MLX_KEY_Q)
		{
			camera_move(vars->camera, (t_transform){(t_vector3){0, 0, 0, 0},
				(t_quaternion){0, 10, 0, 10}});
			vars->update = 1;
		}
		if (keycode.key == MLX_KEY_E)
		{
			camera_move(vars->camera, (t_transform){(t_vector3){0, 0, 0, 0},
				(t_quaternion){0, -10, 0, -10}});
			vars->update = 1;
		}
		if (keycode.key == MLX_KEY_SPACE && keycode.action == MLX_PRESS)
		{
			vars->draw_line = !vars->draw_line;
			vars->update = 1;
		}
}

void	perspective(mlx_key_data_t keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode.key == MLX_KEY_1)
	{
		vars->projection = PROJECTION_PERSPECTIVE;
		vars->update = 1;
	}
	if (keycode.key == MLX_KEY_2)
	{
		vars->projection = PROJECTION_ISOMETRIC;
		vars->update = 1;
	}
	if (keycode.key == MLX_KEY_3)
	{
		vars->projection = PROJECTION_FLAT;
		vars->update = 1;
	}
}

void	event_onkey(mlx_key_data_t keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode.key == 256)
	{
		vars->run = 0;
		event_onclose(param);
		return ;
	}
	movement(keycode, vars);
	utilities(keycode, vars);
	rotation(keycode, vars);
	perspective(keycode, param);
}