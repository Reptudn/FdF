/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:34 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/21 13:22:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void map_rotate(t_map *map, double angle)
{
    t_vector2 center = {map->size_x / 2, map->size_y / 2};

    // Translate to origin
    for (int i = 0; i < map->size_x; i++)
    {
        for (int j = 0; j < map->size_y; j++)
        {
            map->points[i][j].x -= center.x;
            map->points[i][j].y -= center.y;
        }
    }

    // Rotate
    for (int i = 0; i < map->size_x; i++)
    {
        for (int j = 0; j < map->size_y; j++)
        {
            double x = map->points[i][j].x * cos(angle) - map->points[i][j].y * sin(angle);
            double y = map->points[i][j].x * sin(angle) + map->points[i][j].y * cos(angle);
            map->points[i][j].x = x;
            map->points[i][j].y = y;
        }
    }

    // Translate back
    for (int i = 0; i < map->size_x; i++)
    {
        for (int j = 0; j < map->size_y; j++)
        {
            map->points[i][j].x += center.x;
            map->points[i][j].y += center.y;
        }
    }
}

void	map_draw(void *param)
{
	int					x;
	int					y;
	t_vector2			last_point;
	t_vars				*vars;
	// mlx_image_t			*image_tmp;

	x = 0;
	y = 0;
	vars = (t_vars *)param;
	vars->image = mlx_new_image(vars->mlx, vars->window_width,
			vars->window_height);
	// image_tmp = mlx_new_image(vars->mlx, vars->window_width,
	// 		vars->window_height);
	// ft_memset(image_tmp->pixels, 5, vars->image->width * vars->image->height * sizeof(int32_t));
	// mlx_image_to_window(vars->mlx, image_tmp, 0, 0);
	// mlx_delete_image(vars->mlx, image_tmp);
	// debug_log("Map draw started");
	// printf("Map size: %d x %d\n", vars->map->size_x, vars->map->size_y);
	while (x < vars->map->size_x)
	{
		y = 0;
		while (y < vars->map->size_y)
		{
			// printf("x: %d\ty: %d\n", x, y);
			last_point = get_screen_coordinates((t_transform){(t_vector3){x,
					y, vars->map->points[y][x].z, 0},
					(t_quaternion){0, 0, 0, 0}}, vars->camera);
			last_point.x += (vars->window_width / 4) + x * 10;
			last_point.y += (vars->window_height / 4) + y * 7;
			// if (last_point.x < vars->window_width && last_point.y < vars->window_height && last_point.x > 0 && last_point.y > 0)
			// {
			// 	draw_dot(last_point, vars->draw_size, param, get_rgba(255, 0, 0, 255));
			// 	if (x >= 1 && y >= 1)
			// 		draw_line(last_last_point, last_point, param, get_rgba(0, 255, 0, 255));
			// }
			// draw_line_to_neighbours(vars, last_point);
			draw_dot(last_point, 3, param, get_rgba(255, 0, 0, 255));
			y++;
		}
		x++;
	}
	mlx_image_to_window(vars->mlx, vars->image, 0, 0);
	// debug_log("Map draw ended");
}
