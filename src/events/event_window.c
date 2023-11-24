/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:12:31 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/24 09:16:51 by jkauker          ###   ########.fr       */
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
}

void	event_onclose(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	free(vars->map->points);
	free(vars->map);
	free(vars->camera);
	free(vars);
	exit(0);
}
