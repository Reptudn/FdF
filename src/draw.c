/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:08 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/22 13:39:03 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

typedef struct s_line
{
	t_vector2	start;
	t_vector2	end;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
}				t_line;

t_line	initialize_line(t_vector2 start, t_vector2 end)
{
	t_line	line;

	line.start = start;
	line.end = end;
	line.dx = abs(end.x - start.x);
	line.dy = abs(end.y - start.y);
	if (start.x < end.x)
		line.sx = 1;
	else
		line.sx = -1;
	if (start.y < end.y)
		line.sy = 1;
	else
		line.sy = -1;
	if (line.dx > line.dy)
		line.err = line.dx / 2;
	else
		line.err = -line.dy / 2;
	return (line);
}

/*
**	This function is used to draw a dot at a given point.
**	It uses the circle equation to determine if a point is inside the circle.
**	https://en.wikipedia.org/wiki/Circle#Equations
*/
void	draw_dot(t_vector2 middle_point, int radius,
	void *param, int color)
{
	int		x;
	int		y;
	t_vars	*vars;
	int		dist;

	if (radius < 0)
		radius = -radius;
	if (radius == 0)
		radius = 1;
	vars = (t_vars *)param;
	x = middle_point.x - radius;
	while (x < middle_point.x + radius)
	{
		y = middle_point.y - radius;
		while (y < middle_point.y + radius)
		{
			dist = (x - middle_point.x) * (x - middle_point.x)
				+ (y - middle_point.y) * (y - middle_point.y);
			if (dist <= radius * radius && x >= 0
				&& x < vars->window_width && y >= 0 && y < vars->window_height)
				mlx_put_pixel(vars->image, x, y, color);
			y++;
		}
		x++;
	}
}

/*
** This function is used to draw a line between two points.
** It uses the Bresenham's line algorithm.
** https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
*/

void	draw_line(t_vector2 start, t_vector2 end, void *param, int color)
{
	int		e2;
	t_line	line;
	t_vars	*vars;

	vars = (t_vars *)param;
	line = initialize_line(start, end);
	while (1)
	{
		draw_dot((t_vector2){line.start.x, line.start.y}, 1, param, color);
		if (line.start.x == line.end.x && line.start.y == line.end.y)
			break ;
		e2 = line.err;
		if (e2 > -line.dx)
		{
			line.err -= line.dy;
			line.start.x += line.sx;
		}
		if (e2 < line.dy)
		{
			line.err += line.dx;
			line.start.y += line.sy;
		}
	}
}

void	draw_line_to_neighbours(t_vars *vars, t_vector2 curr_point, int x, int y)
{
	int	xs;
	int	ys;

	xs = (vars->window_width / 2) + x * 10 + vars->map->transform.position.x;
	ys = (vars->window_height / 2) + y * 10  + vars->map->transform.position.y;
	if (x - 1 >= 0)
		draw_line(curr_point, get_screen_coordinates((t_transform){(t_vector3){vars->map->points[y][x - 1].x,
					vars->map->points[y][x - 1].y, vars->map->points[y][x - 1].z, 0},
					(t_quaternion){0, 0, 0, 0}}, vars->camera),
					vars, get_rgba(0, 255, 0, 255));
	if (x + 1 < vars->map->size_x)
		draw_line(curr_point, get_screen_coordinates((t_transform){(t_vector3){vars->map->points[y][x + 1].x,
					vars->map->points[y][x + 1].y, vars->map->points[y][x + 1].z, 0},
					(t_quaternion){0, 0, 0, 0}}, vars->camera),
					vars, get_rgba(0, 255, 0, 255));
	if (y - 1 >= 0)
		draw_line(curr_point, get_screen_coordinates((t_transform){(t_vector3){vars->map->points[y - 1][x].x,
					vars->map->points[y - 1][x].y, vars->map->points[y - 1][x].z, 0},
					(t_quaternion){0, 0, 0, 0}}, vars->camera),
					vars, get_rgba(0, 255, 0, 255));
	if (y + 1 < vars->map->size_y)
		draw_line(curr_point, get_screen_coordinates((t_transform){(t_vector3){vars->map->points[y + 1][x].x,
					vars->map->points[y + 1][x].y, vars->map->points[y + 1][x].z, 0},
					(t_quaternion){0, 0, 0, 0}}, vars->camera),
					vars, get_rgba(0, 255, 0, 255));
}
