/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:34 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/09 09:17:06 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_map(t_map *map, t_quaternion rot)
{
	/*
	rotate map stuff
	*/
	map->transform.rotation = quaternion_add(map->transform.rotation, rot);
}

void	draw_map(t_map	*map, t_camera *cam)
{
	/*
	draw map stuff
	*/
}
