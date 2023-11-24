/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:38:44 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/24 09:40:34 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

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
			vars->map->points[y][x].x -= vars->map->size_x / 2;
			vars->map->points[y][x].y -= vars->map->size_y / 2;
			y++;
		}
		x++;
	}
}