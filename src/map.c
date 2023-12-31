/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:34 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/07 09:18:14 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	map_move(t_vector3 position, t_map *map)
{
	map->transform.position = vector_add(map->transform.position, position);
}

void	map_rotate(double rotation, t_vector3 axis, t_map *map)
{
	t_quaternion	rotation_quaternion;

	rotation_quaternion = angle_to_quaternion(rotation, axis);
	map->transform.rotation = quaternion_add(map->transform.rotation,
			rotation_quaternion);
}

/*
**	Perspective Projection
*/
void	map_draw(t_vars *vars)
{
	int					x;
	int					y;
	t_vector2			last_point;

	x = -1;
	mlx_delete_image(vars->mlx, vars->image);
	vars->image = mlx_new_image(vars->mlx, vars->window_width,
			vars->window_height);
	while (++x < vars->map->size_x)
	{
		y = -1;
		while (++y < vars->map->size_y)
		{
			last_point = get_screen_coordinates((t_transform){(t_vector3){x,
					y, vars->map->points[y][x].z, 0, (t_vector2){0, 0}},
					(t_quaternion){0, 0, 0, 0}}, vars->map);
			last_point.x *= vars->camera->zoom;
			last_point.y *= vars->camera->zoom;
			coords_apply_offset(&last_point, &vars->map->points[y][x], vars);
			vars->map->points[y][x].screen = last_point;
		}
	}
	mlx_image_to_window(vars->mlx, vars->image, 0, 0);
}

/*
**	Isometric Projection
*/
void	map_draw_isometric(t_vars *vars)
{
	int					x;
	int					y;
	t_vector2			last_point;

	x = -1;
	mlx_delete_image(vars->mlx, vars->image);
	vars->image = mlx_new_image(vars->mlx, vars->window_width,
			vars->window_height);
	while (++x < vars->map->size_x)
	{
		y = -1;
		while (++y < vars->map->size_y)
		{
			last_point = isometric_projection(vars->map->points[y][x], vars);
			last_point.x += -vars->map->transform.position.x
				+ vars->window_width / 2;
			last_point.y += -vars->map->transform.position.y
				+ vars->window_height / 2;
			last_point.x *= vars->camera->zoom;
			last_point.y *= vars->camera->zoom;
			vars->map->points[y][x].screen = last_point;
		}
	}
	mlx_image_to_window(vars->mlx, vars->image, 0, 0);
}

/*
**	Flat Projection
*/
void	map_draw_flat(t_vars *vars)
{
	int			x;
	int			y;
	t_vector2	last_point;

	x = 0;
	mlx_delete_image(vars->mlx, vars->image);
	vars->image = mlx_new_image(vars->mlx, vars->window_width,
			vars->window_height);
	while (x < vars->map->size_x)
	{
		y = -1;
		while (++y < vars->map->size_y && vars->map)
		{
			last_point = (t_vector2){x * vars->window_width
				/ vars->map->size_x * 0.8, y
				* vars->window_height / vars->map->size_y * 0.8};
			coords_apply_flat_offset(vars, &last_point);
			vars->map->points[y][x].screen = last_point;
		}
		x++;
	}
	mlx_image_to_window(vars->mlx, vars->image, 0, 0);
}
