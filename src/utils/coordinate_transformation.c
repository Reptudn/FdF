/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_transformation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:11:19 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/04 10:28:51 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	coords_apply_offset(t_vector2 *point, t_vector3 *base, t_vars *vars)
{
	point->x += vars->window_width / 2 + base->x
		+ vars->map->transform.position.x;
	point->y += vars->window_height / 2 + base->y
		+ vars->map->transform.position.y;
}
