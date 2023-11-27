/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:15 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/27 14:17:25 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_vector3	convert_to_vector3(int x, int y, int z)
{
	t_vector3	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

int	parse_line(t_vector3 **map, char *line, int count)
{
	char		**contents;
	int			len;
	int			i;

	i = -1;
	contents = ft_split(line, ' ');
	if (!contents)
		return (0);
	len = 0;
	while (contents[len])
		len++;
	map[count] = (t_vector3 *)ft_calloc((len), sizeof(t_vector3));
	if (!map[count])
		return (0);
	while (contents[++i])
	{
		if (ft_strchr(contents[i], ',') && ft_split(contents[i], ','))
			map[count][i] = (t_vector3){count, i, ft_atoi(contents[i]),
				hex_to_color(ft_split(contents[i], ',')[1])};
		else
			map[count][i] = (t_vector3){count, i, ft_atoi(contents[i]),
				hex_to_color("0xFFFFFF")};
	}
	return (len - 1);
}

t_vector3	**get_map(int fd, t_map *map_struct)
{
	t_vector3	**map;
	char		*line;

	map = (t_vector3 **)malloc(sizeof(t_vector3 **));
	if (!map)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	map_struct->size_y = 0;
	while (line != 0)
	{
		map_struct->size_x = parse_line(map, line, map_struct->size_y);
		if (map_struct->size_x <= 0)
			return (0);
		map_struct->size_y++;
		line = get_next_line(fd);
		if (!line)
			break ;
		map = (t_vector3 **)realloc(map,
				sizeof(t_vector3 *) * (map_struct->size_y + 1));
	}
	return (map);
}
