/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:01 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/09 09:46:21 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	camera_move(t_camera *cam, t_transform transform)
{
	cam->transform.position = vector_add(cam->transform.position,
			transform.position);
}

t_camera	camera_create(t_vector3 position, t_quaternion rotation,
				double fov)
{
	t_camera	cam;

	cam.transform.position = position;
	cam.transform.rotation = rotation;
	cam.fov = fov;
	return (cam);
}
