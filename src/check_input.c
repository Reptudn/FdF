/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:21:00 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/07 09:07:35 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
**	returns 1 if input is valid, 0 if not
*/
int	check_input(int argc, char **argv)
{
	char	*file_name;

	if (argc != 2)
	{
		write(1, "Usage: ./fdf <filename>\n", 24);
		return (0);
	}
	file_name = ft_substr(argv[1], ft_strlen(argv[1]) - 4, ft_strlen(argv[1]));
	if (!file_name)
		return (0);
	if (ft_strncmp(file_name, ".fdf", 4) == 0)
	{
		free(file_name);
		return (1);
	}
	write(1, "Invalid filetype! File must be of type .fdf\n", 45);
	free(file_name);
	return (0);
}
