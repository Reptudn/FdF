/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:12:52 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/07 11:05:37 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	rotation(mlx_key_data_t keycode, t_vars *vars)
{
	if (keycode.key == MLX_KEY_I)
		map_rotate(100, (t_vector3){25, 0, 0, 0,
			(t_vector2){0, 0}}, vars->map);
	if (keycode.key == MLX_KEY_K)
		map_rotate(-100, (t_vector3){25, 0, 0, 0,
			(t_vector2){0, 0}}, vars->map);
	if (keycode.key == MLX_KEY_J)
		map_rotate(100, (t_vector3){0, 25, 0, 0,
			(t_vector2){0, 0}}, vars->map);
	if (keycode.key == MLX_KEY_L)
		map_rotate(-100, (t_vector3){0, 25, 0, 0,
			(t_vector2){0, 0}}, vars->map);
	if (keycode.key == MLX_KEY_U)
		map_rotate(100, (t_vector3){0, 0, 25, 0,
			(t_vector2){0, 0}}, vars->map);
	if (keycode.key == MLX_KEY_O)
		map_rotate(-100, (t_vector3){0, 0, 25, 0,
			(t_vector2){0, 0}}, vars->map);
	if (keycode.key == MLX_KEY_I || keycode.key == MLX_KEY_K
		|| keycode.key == MLX_KEY_J || keycode.key == MLX_KEY_L
		|| keycode.key == MLX_KEY_U || keycode.key == MLX_KEY_O)
		vars->update = 1;
}

void	movement(mlx_key_data_t keycode, t_vars *vars)
{
	if (keycode.key == MLX_KEY_W)
		map_move((t_vector3){0, 100, 0, 0,
			(t_vector2){0, 0}}, vars->map);
	if (keycode.key == MLX_KEY_S)
		map_move((t_vector3){0, -100, 0, 0,
			(t_vector2){0, 0}}, vars->map);
	if (keycode.key == MLX_KEY_A)
		map_move((t_vector3){100, 0, 0, 0,
			(t_vector2){0, 0}}, vars->map);
	if (keycode.key == MLX_KEY_D)
		map_move((t_vector3){-100, 0, 0, 0,
			(t_vector2){0, 0}}, vars->map);
	if (keycode.key == MLX_KEY_W || keycode.key == MLX_KEY_S
		|| keycode.key == MLX_KEY_A || keycode.key == MLX_KEY_D)
		vars->update = 1;
}

void	utilities(mlx_key_data_t keycode, t_vars *vars)
{
	if (keycode.key == MLX_KEY_R)
	{
		vars->camera->transform = (t_transform){(t_vector3){200, 300, 0,
			0, (t_vector2){0, 0}},
			(t_quaternion){0, 0, 0, 0}};
		vars->map->transform = (t_transform){(t_vector3){0, 0, 0,
			0, (t_vector2){0, 0}},
			(t_quaternion){0, 0, 0, 0}};
		vars->camera->zoom = 0.3;
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
		reset_tranform(vars);
		vars->update = 1;
	}
	if (keycode.key == MLX_KEY_2)
	{
		vars->projection = PROJECTION_ISOMETRIC;
		reset_tranform(vars);
		vars->update = 1;
	}
	if (keycode.key == MLX_KEY_3)
	{
		vars->projection = PROJECTION_FLAT;
		reset_tranform(vars);
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
