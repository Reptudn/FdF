/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:24:58 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/09 11:55:14 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector3	vector_rotate(t_vector3 vec, t_quaternion rot)
{
	t_vector3	new;
	double		x;
	double		y;
	double		z;

	x = vec.x;
	y = vec.y;
	z = vec.z;
	new.x = (1 - 2 * pow(rot.y, 2) - 2 * pow(rot.z, 2)) * x
		+ (2 * rot.x * rot.y - 2 * rot.z * rot.w) * y
		+ (2 * rot.x * rot.z + 2 * rot.y * rot.w) * z;
	new.y = (2 * rot.x * rot.y + 2 * rot.z * rot.w) * x
		+ (1 - 2 * pow(rot.x, 2) - 2 * pow(rot.z, 2)) * y
		+ (2 * rot.y * rot.z - 2 * rot.x * rot.w) * z;
	new.z = (2 * rot.x * rot.z - 2 * rot.y * rot.w) * x
		+ (2 * rot.y * rot.z + 2 * rot.x * rot.w) * y
		+ (1 - 2 * pow(rot.x, 2) - 2 * pow(rot.y, 2)) * z;
	return (new);
}
