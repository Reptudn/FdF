/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:15:26 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/11 13:50:24 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	draw_one(t_vars *vars)
{
	mlx_new_image(vars->mlx, vars->window_width, vars->window_height);
	mlx_put_pixel(vars->image, vars->window_width / 2,
		vars->window_height / 2, vars->map->points[0][0].color);
	mlx_image_to_window(vars->mlx, vars->image, vars->window_width,
		vars->window_height);
}
