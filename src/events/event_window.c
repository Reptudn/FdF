/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:12:31 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/11 16:57:13 by jkauker          ###   ########.fr       */
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
** system("leaks fdf"); proof
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
	mlx_delete_image(vars->mlx, vars->image);
	mlx_terminate(vars->mlx);
	ft_exit(0);
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
	ft_exit(0);
}

void	ft_exit(int exitcode)
{
	system("leaks fdf");
	exit(exitcode);
}
