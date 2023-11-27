/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:17:38 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/27 11:49:58 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	debug_error(char *error_msg)
{
	ft_printf("[Err] %s\n", error_msg);
}

void	debug_log(char *log_msg)
{
	ft_printf("[Log] %s\n", log_msg);
}

void	debug_print_map(t_map map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map.size_x)
	{
		y = 0;
		while (y < map.size_y)
		{
			ft_printf("%d	", map.points[x][y].z);
			y++;
		}
		ft_printf("\n");
		x++;
	}
}

void	debug_draw_info(t_vars *vars)
{
	ft_printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_printf("Window Width: %d\n", vars->window_width);
	ft_printf("Window Height: %d\n", vars->window_height);
	ft_printf("Draw Size: %d\n", vars->draw_size);
	ft_printf("Map Name: %s\n", vars->map->map_name);
	ft_printf("Map Size X: %d\n", vars->map->size_x);
	ft_printf("Map Size Y: %d\n", vars->map->size_y);
	ft_printf("Map Position: %d, %d, %d\n", vars->map->transform.position.x,
		vars->map->transform.position.y, vars->map->transform.position.z);
	ft_printf("Map Rotation: %d, %d, %d\n", vars->map->transform.rotation.x,
		vars->map->transform.rotation.y, vars->map->transform.rotation.z);
}
