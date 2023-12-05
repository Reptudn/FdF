/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:01 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/05 09:02:25 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	camera_move(t_camera *cam, t_transform transform)
{
	cam->transform.position = vector_add(cam->transform.position,
			transform.position);
}

t_camera	camera_create(t_vector3 position, t_quaternion rotation,
				double zoom)
{
	t_camera	cam;

	cam.transform.position = position;
	cam.transform.rotation = rotation;
	cam.zoom = zoom;
	cam.near = 0.1;
	cam.far = 1000;
	return (cam);
}
