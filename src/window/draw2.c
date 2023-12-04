/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:33:00 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/04 13:46:21 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	draw_all_lines(t_vars *vars)
{
	int	x;
	int	y;
	int	start_color;

	x = -1;
	y = -1;
	while (++x < vars->map->size_x)
	{
		y = -1;
		while (++y < vars->map->size_y)
		{
			start_color = vars->map->points[y][x].color;
			if (x + 1 < vars->map->size_x)
				draw_line(vars->map->points[y][x].screen,
					vars->map->points[y][x + 1].screen, vars,
					(t_gradient){start_color,
					vars->map->points[y][x + 1].color});
			if (y + 1 < vars->map->size_y)
				draw_line(vars->map->points[y][x].screen,
					vars->map->points[y + 1][x].screen, vars,
					(t_gradient){start_color,
					vars->map->points[y + 1][x].color});
		}
	}
}
