/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:15 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/13 10:15:29 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_vector3	convert_to_vector3(int x, int y, int z)
{
	t_vector3	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

int	count_words(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (str[i] != ' ')
		{
			count++;
			while (str[i] != ' ' && str[i] != 0)
				i++;
		}
		else
			i++;
	}
	return (count);
}

t_vector3	**get_map(int fd, t_vars *vars)
{
	t_vector3	**map;
	char		**contents;
	char		*line;
	int			x;
	int			y;

	x = 0;
	map = (t_vector3 **)malloc(sizeof(t_vector3 *));
	if (!map)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line != 0)
	{
		contents = ft_split(line, ' ');
		if (!contents)
		{
			free(map);
			return (0);
		}
		map[x] = (t_vector3 *)malloc(sizeof(t_vector3)
				* (count_words(line) + 1));
		if (!map[x])
		{
			free(contents);
			free(map);
			return (0);
		}
		map[count_words(line)] = 0;
		y = 0;
		printf("Map: ");
		while (contents[y] != 0)
		{
			if (ft_strchr(contents[y], ','))
				map[x][y] = convert_to_vector3(x, y,
						ft_atoi(ft_split(contents[y], ',')[0]));
			else
				map[x][y] = convert_to_vector3(x, y, ft_atoi(contents[y]));
			printf("%d	", map[x][y].z);
			y++;
		}
		printf("\n");
		free(contents);
		map = (t_vector3 **)realloc(map,
				sizeof(t_vector3 *) * (x + 2));
		if (!map)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		map[y + 1] = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		x++;
	}
	vars->map->size_y = y;
	vars->map->size_x = x;
	debug_print_map(*vars->map);
	return (map);
}
