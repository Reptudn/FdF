/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:17:38 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/10 16:23:03 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	debug_error(char *error_msg)
{
	ft_printf("[Err] %s\n", error_msg);
}

void	debug_log(char *log_msg)
{
	ft_printf("[Log] %s\n", log_msg);
}

void	debug_print_map(t_map map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map.size_x)
	{
		y = 0;
		while (y < map.size_y)
		{
			ft_printf("%d ", map.points[x][y].z);
			y++;
		}
		ft_printf("\n");
		x++;
	}
}
