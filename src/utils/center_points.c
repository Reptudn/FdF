/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:38:44 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/24 10:43:13 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"
#include <stdio.h>

void	center(t_vars *vars)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < vars->map->size_x)
	{
		y = 0;
		while (y < vars->map->size_y)
		{
			printf("Before x: %d, y: %d\n", vars->map->points[y][x].x, vars->map->points[y][x].y);
			vars->map->points[y][x].x -= vars->map->size_x / 2;
			vars->map->points[y][x].y -= vars->map->size_y / 2;
			printf("After x: %d, y: %d\n", vars->map->points[y][x].x, vars->map->points[y][x].y);
			y++;
		}
		x++;
	}
}