/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:28:22 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/07 11:01:34 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	rotate_x(int *y, int *z, double angle)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(angle) + *z * sin(angle);
	*z = -previous_y * sin(angle) + *z * cos(angle);
}

void	rotate_y(int *x, int *z, double angle)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(angle) + *z * sin(angle);
	*z = -previous_x * sin(angle) + *z * cos(angle);
}

void	rotate_z(int *x, int *y, double angle)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(angle) - previous_y * sin(angle);
	*y = previous_x * sin(angle) + previous_y * cos(angle);
}

/*
**	*x = (previous_x - previous_y) * cos(0.54321);
**	*y = -z + (previous_x + previous_y) * sin(0.54321);
*/
void	point_to_iso(int *x, int *y, int z, t_vars *vars)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	previous_x *= vars->window_width / 5;
	previous_y *= vars->window_height / 5;
	previous_x *= vars->camera->zoom;
	previous_y *= vars->camera->zoom;
	previous_x += vars->window_width / 5;
	previous_y += vars->window_height / 5;
	*x = (previous_x - previous_y);
	*y = -z + (previous_x + previous_y) / 2;
}

t_vector2	isometric_projection(t_vector3 input, t_vars *vars)
{
	t_vector3	copy;

	copy.x = input.x;
	copy.y = input.y;
	copy.z = input.z;
	rotate_x(&copy.y, &copy.z, vars->map->transform.rotation.x);
	rotate_y(&copy.x, &copy.z, vars->map->transform.rotation.y);
	rotate_z(&copy.x, &copy.y, vars->map->transform.rotation.z);
	point_to_iso(&copy.x, &copy.y, copy.z, vars);
	return ((t_vector2){copy.x, copy.y});
}
