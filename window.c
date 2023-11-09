/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:15:05 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/09 10:59:22 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	window_open(char *name, void *mlx, void *window)
{
	window = mlx_new_window(mlx, WINDOW_DEFAULT_WIDTH,
			WINDOW_DEFAULT_HEIGHT, name);
	if (!window)
	{
		debug_error("Could not open window\n");
		return (0);
	}
	return (1);
}

void	window_close(void *mlx, void *window)
{
	mlx_destroy_window(mlx, window);
}

void	window_clear(void *mlx, void *window)
{
	mlx_clear_window(mlx, window);
}

// void	window_resize(void *window, int width, int height)
// {
// 	/*
// 	*	Resize window stuff
// 	*	Called when window has to be resized
// 	*	min size is defined in header
// 	*/
// }
