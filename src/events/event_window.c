/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:12:31 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/07 09:24:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	event_onresize(int x, int y, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	vars->update = 1;
	vars->window_width = x;
	vars->window_height = y;
	mlx_resize_image(vars->image, x, y);
}

/*
** This is being called once the window closes
*/
void	event_onclose(void *param)
{
	t_vars	*vars;
	int		x;

	x = -1;
	vars = (t_vars *)param;
	write(1, "\nClosing window...\n", 20);
	while (++x < vars->map->size_y)
		free(vars->map->points[x]);
	free(vars->map->points);
	free(vars->map);
	mlx_terminate(vars->mlx);
	write(1, "Window closed.\n", 15);
	exit(0);
}

/*
** This is being called once something failes during intitialization
*/
void	event_onfail(void *param, int rows)
{
	t_vars	*vars;
	int		x;

	x = -1;
	vars = (t_vars *)param;
	while (++x < rows)
		free(vars->map->points[x]);
	free(vars->map->points);
	free(vars->map);
	mlx_terminate(vars->mlx);
	write(1, "Woops! Something failed to initialize. Closing window\n", 55);
	exit(0);
}
