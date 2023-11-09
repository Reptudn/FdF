/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:13:54 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/09 13:12:01 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "sources/minilibx_macos/mlx.h"

t_map	create_map(char *map_name, int fd)
{
	t_map	map;

	map.map_name = map_name;
	map.points = get_map(fd);
	map.transform.position = (t_vector3){0, 0, 0};
	map.transform.rotation = (t_quaternion){0, 0, 0, 0};
	return (map);
}

void	gameloop(t_map *map, t_camera *cam, void *mlx, void *window)
{
	short		run;
	short		update;

	run = 1;
	update = 0;
	if (!register_all_events(mlx, window, &(t_vars){&run, &update}))
	{
		debug_error("Could not register events\n");
		return ;
	}
	debug_error("Gameloop started and events registered\n");
	map_draw(map, cam);
	while (run == 1)
	{
		if (update == 0)
			continue ;
		map_rotate(map, (t_quaternion){0, 0, 0, 0});
		camera_move(cam, (t_transform){(t_vector3){0, 0, 0},
			(t_quaternion){0, 0, 0, 0}});
		window_clear(mlx, window);
		map_draw(map, cam);
		update = 0;
	}
	debug_log("Gameloop ended");
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_camera	cam;
	void		*mlx;
	void		*window;

	if (argc != 2)
	{
		debug_error("No file given\n");
		return (RUN_ERROR);
	}
	mlx = mlx_init();
	if (!mlx)
	{
		debug_error("Could not initialize mlx\n");
		return (RUN_ERROR);
	}
	map = create_map(argv[1], open(argv[1], O_RDONLY));
	cam = camera_create((t_vector3){0, 0, 0},
			(t_quaternion){0, 0, 0, 0}, CAMERA_DEFAULT_FOV);
	window = 0;
	if (!window_open("FdF by jkauker", mlx, window))
		return (RUN_ERROR);
	gameloop(&map, &cam, mlx, window);
	window_close(mlx, window);
	return (RUN_SUCCESS);
}
