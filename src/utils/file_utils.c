/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:15 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/07 08:58:31 by jkauker          ###   ########.fr       */
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

int	splitter(t_vector3 **map, char **contents, int i, int count)
{
	char	**split;

	if (ft_strchr(contents[i], ','))
	{
		split = ft_split(contents[i], ',');
		if (!split)
			return (0);
		map[count][i] = (t_vector3){count, i, ft_atoi(contents[i]),
			hex_to_color(split[1]), (t_vector2){0, 0}};
	}
	else
		map[count][i] = (t_vector3){count, i, ft_atoi(contents[i]),
			hex_to_color("0xFFFFFF"), (t_vector2){0, 0}};
	return (1);
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
		if (!splitter(map, contents, i, count))
			return (0);
		free(contents[i]);
	}
	free(contents);
	write(1, ".", 1);
	return (len);
}

t_vector3	**get_map(int fd, t_map *map_struct)
{
	t_vector3	**map;
	char		*line;

	write(1, "Reading map", 12);
	map = (t_vector3 **)malloc(sizeof(t_vector3 **));
	if (!map)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	map_struct->size_y = 0;
	while (line != 0 && map != 0)
	{
		map_struct->size_x = parse_line(map, line, map_struct->size_y);
		if (map_struct->size_x <= 0)
			event_onfail(map_struct, map_struct->size_y);
		map_struct->size_y++;
		free(line);
		line = get_next_line(fd);
		if (!line || line[0] == '\n')
			break ;
		map = (t_vector3 **)ft_realloc(map,
				sizeof(t_vector3 *) * (map_struct->size_y + 1));
	}
	return (map);
}
