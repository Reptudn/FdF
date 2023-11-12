/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:15 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/12 18:55:25 by jonask           ###   ########.fr       */
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
		y = 0;
		while (contents[y] != 0)
		{
			if (ft_strchr(contents[y], ','))
				map[x][y] = convert_to_vector3(x, y,
						ft_atoi(ft_split(contents[y], ',')[0]));
			else
				map[x][y] = convert_to_vector3(x, y, ft_atoi(contents[y]));
			y++;
		}
		// vars->map->size_y = y; //segv
		free(contents);
		map = (t_vector3 **)realloc(map,
				sizeof(t_vector3 *) * (x + 2));
		map[y + 1] = 0;
		line = get_next_line(fd);
		write(1, "a\n", 2);
		x++;
	}
	vars->map->size_x = x;
	return (map);
}

// t_vector3	**get_map(int fd, t_vars *vars)
// {
// 	t_vector3	**map;
// 	char		*line;
// 	char		**line_content;
// 	int			lines;
// 	int			words;

// 	write(1, "Creating Map\n", 14);
// 	map = (t_vector3 **)malloc(sizeof(t_vector3 *));
// 	if (!map)
// 		return (0);
// 	line = get_next_line(fd);
// 	lines = 0;
// 	words = 0;
// 	while (line)
// 	{
// 		write(1, &lines, 1);
// 		line_content = ft_split(line, ' ');
// 		if (!line_content)
// 		{
// 			free(map);
// 			return (0);
// 		}
// 		map = realloc(map, sizeof(t_vector3 *) * (lines + 1));
// 		if (!map)
// 		{
// 			free(line_content);
// 			free(map);
// 			return (0);
// 		}
// 		map[lines] = malloc(sizeof(t_vector3) * (count_words(line) + 1));
// 		while (line_content[words])
// 		{
// 			if (ft_strchr(line_content[words], ','))
// 				map[lines][words] = convert_to_vector3(lines, words,
// 						ft_atoi(ft_split(line_content[words], ',')[0]));
// 			else
// 				map[lines][words] = convert_to_vector3(lines, words,
// 						ft_atoi(line_content[words]));
// 			words++;
// 		}
// 		lines++;
// 	}
// 	vars->map->size_x = lines;
// 	vars->map->size_y = words;
// 	write(1, "Map created\n", 12);
// 	return (map);
// }
