/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:12:31 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/09 10:54:54 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "sources/minilibx/mlx.h"

int	event_register(void *mlx, int event, int (*func)(), void *param)
{
	return (mlx_hook(mlx, event, 0, func, param));
}

int	event_onkey(void)
{
	return (0);
}

int	event_onmouse(void)
{
	return (0);
}

int	register_all_events(void *mlx)
{
	if (!event_register(mlx, 1, event_onkey, NULL))
	{
		debug_error("Could not register key events\n");
		return (0);
	}
	debug_log("Key events registered");
	if (!event_register(mlx, 2, event_onmouse, NULL))
	{
		debug_error("Could not register mouse events\n");
		return (0);
	}
	debug_log("Mouse events registered");
	return (1);
}

int	event_loop(void *mlx, void *window, short *run, short *update)
{
	if (mlx_key_hook(window, event_onkey, NULL))
		*update = 1;
	if (mlx_mouse_hook(window, event_onmouse, NULL))
		*update = 1;
	*run = 1;
	mlx_loop(mlx);
	return (1);
}



