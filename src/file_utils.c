/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:15 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/22 09:51:22 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdlib.h>

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

// int	get_line_content(t_vars *vars, int x, int fd)
// {
// 	int		y;
// 	char	*line;
// 	char	**line_content;

// 	y = 0;
// 	line = get_next_line(fd);
// 	if (!line)
// 		return (0);
// 	line_content = ft_split(line, ' ');
// 	if (!line_content)
// 		return (0);
// 	while (line_content[y])
// 	{
// 		if (ft_strchr(line_content[y], ','))
// 		{
// 			vars->map->points[x][y] = convert_to_vector3(x, y,
// 					ft_atoi(ft_split(line_content[y], ',')[0]));
// 			vars->map->points[x][y].color = ft_split(line_content[y], ',')[1];
// 		}
// 		else
// 		{
// 			vars->map->points[x][y] = convert_to_vector3(x, y,
// 					ft_atoi(line_content[y]));
// 			vars->map->points[x][y].color = "white";
// 		}
// 		y++;
// 	}
// 	return (1);
// }

t_vector3	**get_map(int fd, t_map *map_struct)
{
	t_vector3	**map;
	char		**contents;
	t_vector3	**tmp;
	char		*line;
	int			x;
	int			y;

	x = 0;
	map = (t_vector3 **)malloc(sizeof(t_vector3 **));
	if (!map)
		return (0);
	line = get_next_line(fd);
	if (!line)
	{
		// free(map);
		return (0);
	}
	while (line != 0)
	{
		if (*line == '\n' || *line == '\0')
		{
			// free(line);
			break ;
		}
		contents = ft_split(line, ' ');
		if (!contents)
		{
			// free(line);
			// free(map);
			return (0);
		}
		map[x] = (t_vector3 *)malloc(sizeof(t_vector3)
				* (count_words(line) + 1));
		if (!map[x])
		{
			// free(contents);
			// while(--x)
			// 	free(map[x]);
			// free(map);
			// free(line);
			return (0);
		}
		y = 0;
		while (contents[y] != 0)
		{
			if (ft_strchr(contents[y], ','))
			{
				char **value_color = ft_split(contents[y], ',');
				if (!value_color)
				{
					free(contents);
					while(--x)
						free(map[x]);
					free(map);
					free(line);
					return (0);
				}
				map[x][y] = convert_to_vector3(x, y,
						ft_atoi(value_color[0]));
				map[x][y].color = hex_to_color(value_color[1]);
			}
			else
			{
				map[x][y] = convert_to_vector3(x, y, ft_atoi(contents[y]));
				map[x][y].color = hex_to_color("0xFFFFFF");
			}
			y++;
		}
		map_struct->size_x = count_words(line);
		// free(contents);
		// free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = (t_vector3 **)realloc(map,
				sizeof(t_vector3 *) * (x + 2));
		// free(map);
		map = tmp;
		// free(tmp);
		map[y + 1] = 0;
		x++;
	}
	map_struct->size_y = x;
	return (map);
}
