/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:28:22 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/24 08:55:39 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	rotate_x(int *y, int *z, double alpha)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

static void	rotate_z(int *x, int *y, double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void	rotate(t_vector3 vector, t_vector3 rotation)
{
	rotate_x(&vector.y, &vector.z, rotation.x);
	rotate_y(&vector.x, &vector.z, rotation.y);
	rotate_z(&vector.x, &vector.y, rotation.z);
}

static void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_vector2 isometric_projection(t_vector3 input, t_vars *vars)
{
	t_vector3 copy;

	copy.x = input.x;
	copy.y = input.y;
	copy.z = input.z;
	rotate(copy, (t_vector3){vars->map->transform.rotation.x, vars->map->transform.rotation.y, vars->map->transform.rotation.z, 0});
	iso(&copy.x, &copy.y, copy.z);
	copy.x += vars->camera->transform.position.x;
	copy.y += vars->camera->transform.position.y;
	return ((t_vector2){copy.x, copy.y});
}