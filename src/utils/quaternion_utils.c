/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:50 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/27 11:49:21 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_quaternion	quaternion_add(t_quaternion quaternion1,
					t_quaternion quaternion2)
{
	t_quaternion	new;

	new.w = quaternion1.w + quaternion2.w;
	new.x = quaternion1.x + quaternion2.x;
	new.y = quaternion1.y + quaternion2.y;
	new.z = quaternion1.z + quaternion2.z;
	return (new);
}

double	quaternion_dotprod(t_quaternion quaternion1, t_quaternion quaternion2)
{
	return (quaternion1.w * quaternion2.w
		+ quaternion1.x * quaternion2.x
		+ quaternion1.y * quaternion2.y
		+ quaternion1.z * quaternion2.z);
}

double	quaternion_angle_between(t_quaternion quaternion1,
			t_quaternion quaternion2)
{
	return (2 * acos(fabs(quaternion_dotprod(quaternion1, quaternion2))));
}

t_quaternion	quaternion_new(int x, int y, int z, int w)
{
	return ((t_quaternion){x, y, z, w});
}

t_quaternion	angle_to_quaternion(float theta, t_vector3 axis)
{
	t_quaternion	q;
	float			sin_theta_over_two;

	sin_theta_over_two = sin(theta / 2);
	q.w = cos(theta / 2);
	q.x = axis.x * sin_theta_over_two;
	q.y = axis.y * sin_theta_over_two;
	q.z = axis.z * sin_theta_over_two;
	return (q);
}
