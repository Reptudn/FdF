/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:21:00 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/12 09:43:51 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
**	returns 1 if input is valid, 0 if not
*/
int	check_input(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Usage: ./fdf <filename>\n", 24);
		return (0);
	}
	if (ft_strlen(argv[1]) < 5)
	{
		write(1, "Invalid filetype! File must be of type .fdf\n", 45);
		return (0);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".fdf", 4) == 0)
		return (1);
	write(1, "Invalid filetype! File must be of type .fdf\n", 45);
	return (0);
}
