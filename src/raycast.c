/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:19:49 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/10 11:26:27 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	is_visible_to_camera(t_camera *cam, t_vector3 *point)
{
	t_vector3	relative;
	t_vector3	rotated;
	double		angle;

	relative = vector_substract(*point, cam->transform.position);
	rotated = vector_rotate(relative, cam->transform.rotation);
	angle = quaternion_angle_between(cam->transform.rotation,
			quaternion_new(0, 0, 0, 1));
	if (rotated.z > 0 && angle < M_PI / 2)
		return (1);
	else if (rotated.z < 0 && angle > M_PI / 2)
		return (1);
	return (0);
}
