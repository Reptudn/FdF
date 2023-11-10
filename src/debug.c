/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:17:38 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/10 11:26:09 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	debug_error(char *error_msg)
{
	printf("[Err] %s\n", error_msg);
}

void	debug_log(char *log_msg)
{
	printf("[Log] %s\n", log_msg);
}
