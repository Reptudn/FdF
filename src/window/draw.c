/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:08 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/05 08:59:31 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

typedef struct s_line
{
	t_vector2	start;
	t_vector2	end;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			i;
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
	line.i = -1;
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

void	draw_square(t_vector2 middle_point, int size,
	void *param, int color)
{
	int		x;
	int		y;
	t_vars	*vars;

	vars = (t_vars *)param;
	x = middle_point.x - size;
	while (x <= middle_point.x + size)
	{
		y = middle_point.y - size;
		while (y <= middle_point.y + size)
		{
			if ((x == middle_point.x - size || x == middle_point.x + size
					|| y == middle_point.y - size || y == middle_point.y + size)
				&& x >= 0 && x < vars->window_width && y >= 0
				&& y < vars->window_height)
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
void	draw_line(t_vector2 start, t_vector2 end, void *param, t_gradient color)
{
	int		e2;
	t_line	line;
	t_vars	*vars;

	vars = (t_vars *)param;
	line = initialize_line(start, end);
	while (1)
	{
		draw_dot((t_vector2){line.start.x, line.start.y},
			1, param, get_next_gradient_color(color.end, color.start,
				max(abs(line.dx), abs(line.dy)), &line.i));
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
