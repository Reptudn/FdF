/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:34 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/24 09:54:19 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	map_move(t_vector3 position, t_map *map)
{
	map->transform.position = vector_add(map->transform.position, position);
}

void	map_draw(void *param)
{
	int					x;
	int					y;
	t_vector2			last_point;
	t_vars				*vars;

	x = 0;
	y = 0;
	vars = (t_vars *)param;
	vars->image = mlx_new_image(vars->mlx, vars->window_width,
			vars->window_height);
	while (x < vars->map->size_x)
	{
		y = -1;
		while (++y < vars->map->size_y)
		{
			last_point = get_screen_coordinates((t_transform){(t_vector3){x,
					y, vars->map->points[y][x].z, 0},
					(t_quaternion){0, 0, 0, 0}}, vars->camera);
			last_point.x += (vars->window_width / 2) + x * 2 + vars->map->transform.position.x;
			last_point.y += (vars->window_height / 2) + y * 2  + vars->map->transform.position.y;
			if (last_point.x >= -100 && last_point.x < vars->window_width + 100
					&& last_point.y >= -100 && last_point.y < vars->window_height + 100)
			{
				if (vars->draw_line == 1)
					draw_line_to_neighbours(vars, last_point, x, y);
				draw_dot(last_point, vars->draw_size, param, vars->map->points[y][x].color);
			}
		}
		x++;
	}
	mlx_image_to_window(vars->mlx, vars->image, 0, 0);
}

void	map_draw_isometric(void *param)
{
	int					x;
	int					y;
	t_vector2			last_point;
	t_vars				*vars;

	x = 0;
	y = 0;
	vars = (t_vars *)param;
	vars->image = mlx_new_image(vars->mlx, vars->window_width,
			vars->window_height);
	while (x < vars->map->size_x)
	{
		y = -1;
		while (++y < vars->map->size_y)
		{
			last_point = isometric_projection(vars->map->points[y][x], vars);
			draw_dot(last_point, 3, param, vars->map->points[y][x].color);
		}
		x++;
	}
	mlx_image_to_window(vars->mlx, vars->image, 0, 0);
}

void	map_draw_flat(t_vars *vars)
{
	int					x;
	int					y;

	x = 0;
	vars->image = mlx_new_image(vars->mlx, vars->window_width,
			vars->window_height);
	while (x < vars->map->size_x)
	{
		y = -1;
		while (++y < vars->map->size_y)
		{
			draw_dot((t_vector2){x, y}, 3, &vars, vars->map->points[y][x].color);
			printf("x: %d, y: %d\n", x, y);
		}
		x++;
	}
}
