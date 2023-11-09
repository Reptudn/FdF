/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:34 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/09 09:48:58 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_rotate(t_map *map, t_quaternion rot)
{
	map->transform.rotation = quaternion_add(map->transform.rotation,
			rot);
}

void	map_draw(t_map	*map, t_camera *cam)
{
	int			x;
	int			y;
	int			z;
	t_vector3	point;

	x = 0;
	y = 0;
	z = 0;
	while (x < map->size_x)
	{
		y = 0;
		while (y < map->size_y)
		{
			point = vector_new(x, y, map->points[y][x].z);
			if (is_visible_to_camera(cam, &point))
				debug_log("Draw a a line from here to all surrounding points");
			y++;
		}
		x++;
	}
}
