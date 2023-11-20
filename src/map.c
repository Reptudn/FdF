/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:34 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/20 11:38:46 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	map_rotate(t_map *map, t_quaternion rot)
{
	map->transform.rotation = quaternion_add(map->transform.rotation,
			rot);
}

void	map_draw(void *param)
{
	int			x;
	int			y;
	t_vector2	last_point;
	t_vars		*vars;

	x = 0;
	y = 0;
	vars = (t_vars *)param;
	vars->image = mlx_new_image(vars->mlx, vars->window_width,
			vars->window_height);
	debug_log("Map draw started");
	while (x < vars->map->size_x)
	{
		y = 0;
		while (y < vars->map->size_y)
		{
			write(1, "x", 1);
			last_point = get_screen_coordinates((t_transform){(t_vector3){x,
					y, vars->map->points[y][x].z, 0},
					(t_quaternion){0, 0, 0, 0}}, vars->camera);
			draw_dot(last_point, 10, param, 155);
			y++;
		}
		x++;
	}
	mlx_image_to_window(vars->mlx, vars->image, 0, 0);
	debug_log("Map draw ended");
}
