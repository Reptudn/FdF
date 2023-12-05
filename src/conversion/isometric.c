/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:28:22 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/05 09:27:10 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void	iso(int *x, int *y, int z, t_vars *vars)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	previous_x *= vars->window_width / 2;
	previous_y *= vars->window_height / 2;
	previous_x *= vars->camera->zoom;
	previous_y *= vars->camera->zoom;
	previous_x += vars->window_width / 2;
	previous_y += vars->window_height / 2;
	*x = (previous_x - previous_y) * cos(0.54321);
	*y = -z + (previous_x + previous_y) * sin(0.54321);
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
	iso(&copy.x, &copy.y, copy.z, vars);
	return ((t_vector2){copy.x, copy.y});
}
