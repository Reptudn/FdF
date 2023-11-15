/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:58 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/15 11:51:01 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_vector3	vector_add(t_vector3 vec1, t_vector3 vec2)
{
	t_vector3	new;

	new.x = vec1.x + vec2.x;
	new.y = vec1.y + vec2.y;
	new.z = vec1.z + vec2.z;
	return (new);
}

t_vector3	vector_substract(t_vector3 vec1, t_vector3 vec2)
{
	t_vector3	new;

	new.x = vec1.x - vec2.x;
	new.y = vec1.y - vec2.y;
	new.z = vec1.z - vec2.z;
	return (new);
}

double	vector_distance(t_vector3 vec1, t_vector3 vec2)
{
	int	diff_x;
	int	diff_y;

	diff_x = vec1.x - vec2.x;
	diff_y = vec1.y - vec2.y;
	return (sqrt(pow(diff_y, 2) + pow(diff_x, 2)));
}

double	vector_length(t_vector3 vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
}

t_vector3	vector_new(int x, int y, int z, char *color)
{
	return ((t_vector3){x, y, z, color});
}
