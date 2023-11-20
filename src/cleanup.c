/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:56:15 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/20 12:00:25 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	clean_program(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	free(vars->map->points);
	free(vars->map);
	free(vars->camera);
	free(vars);
	exit(0);
}