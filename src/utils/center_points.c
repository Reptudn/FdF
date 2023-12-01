/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:38:44 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/01 13:17:07 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	center(t_vars *vars)
{
	int		x;
	int		y;
	int		delta_x;
	int		delta_y;

	x = -1;
	delta_x = vars->map->size_x / 2;
	delta_y = vars->map->size_y / 2;
	while (++x < vars->map->size_x)
	{
		y = -1;
		while (++y < vars->map->size_y)
		{
			vars->map->points[y][x].x -= delta_x;
			vars->map->points[y][x].y -= delta_y;
		}
	}
}

void	reset_tranform(t_vars *vars)
{
	t_map	*map;

	map = vars->map;
	map->transform.position = (t_vector3){0, 0, 0, 0};
	map->transform.rotation = (t_quaternion){0, 0, 0, 0};
	vars->update = 1;
	write(1, "Transform reset\n", 17);
}