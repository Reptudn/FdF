/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:12:31 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/09 13:14:30 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "sources/minilibx_macos/mlx.h"

int	event_register(void *mlx, int event, int (*func)(), void *param)
{
	return (mlx_hook(mlx, event, 0, func, param));
}

int	event_onkey(int keycode, short *run, short *update)
{
	printf("[printf] Keycode: %d\n", keycode);
	if (keycode == 53)
		*run = 0;
	*update = 0;
	return (0);
}

int	event_onmouse(int keycode, short *run, short *update)
{
	debug_log("Mouse pressed");
	printf("[printf] Keycode %d\n", keycode);
	*run = 1;
	*update = 0;
	return (0);
}

int	register_all_events(void *mlx, void *window, t_vars *vars)
{
	if (!mlx_mouse_hook(window, event_onmouse, vars))
	{
		debug_error("Could not register key events\n");
		return (0);
	}
	debug_log("Key events registered");
	if (!mlx_key_hook(mlx, event_onkey, vars))
	{
		debug_error("Could not register mouse events\n");
		return (0);
	}
	debug_log("Mouse events registered");
	mlx_loop(mlx);
	return (1);
}
