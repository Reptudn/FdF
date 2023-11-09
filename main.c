/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:13:54 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/09 09:50:05 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	create_map(char *map_name, int fd)
{
	t_map	map;

	map.map_name = map_name;
	map.points = get_map(fd);
	map.transform.position = (t_vector3){0, 0, 0};
	map.transform.rotation = (t_quaternion){0, 0, 0, 0};
	return (map);
}

int	gameloop(t_map *map, t_camera *cam)
{
	short		run;
	short		update;

	run = 1;
	update = 0;
	map_draw(map, cam);
	while (run == 1)
	{
		if (update == 0)
			continue ;
		map_rotate(map, (t_quaternion){0, 0, 0, 0});
		camera_move(cam, (t_transform){(t_vector3){0, 0, 0},
			(t_quaternion){0, 0, 0, 0}});
		map_draw(map, cam);
		update = 0;
	}
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_camera	cam;

	if (argc != 2)
	{
		printf("No file given\n");
		return (1);
	}
	map = create_map(argv[1], open(argv[1], O_RDONLY));
	cam = camera_create((t_vector3){0, 0, 0},
			(t_quaternion){0, 0, 0, 0}, CAMERA_DEFAULT_FOV);
	open_window(argv[1], WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT);
	gameloop(&map, &cam);
	close_window();
	return (0);
}
