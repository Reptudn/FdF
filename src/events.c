/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:12:31 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/10 12:36:40 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	event_onresize(int x, int y, void *param)
{
	printf("[printf] Resize to x: %d\ty: %d \n", x, y);
	printf("[printf] Params %p\n", param);
}

void	event_onkey(mlx_key_data_t keycode, void *param)
{
	printf("[printf] Key Keycode: %d\n", keycode.key);
	printf("[printf] Params %p\n", param);
}

void	event_onmouse(mlx_key_data_t keycode, void *param)
{
	printf("[printf] Mouse Keycode: %d\n", keycode.key);
	printf("[printf] Params %p\n", param);
}

