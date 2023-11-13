/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:13:54 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/13 14:38:08 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	create_map(char *map_name, int fd, t_vars *vars)
{
	t_map	map;

	if (fd == -1)
	{
		debug_error("Could not open file");
		exit(1);
	}
	map.map_name = map_name;
	map.points = get_map(fd, vars);
	write(1, "b\n", 2);
	map.transform.position = (t_vector3){0, 0, 0};
	map.transform.rotation = (t_quaternion){0, 0, 0, 0};
	if (map.points == 0)
	{
		debug_error("Could not create map");
		exit(1);
	}
	return (map);
}

void	register_hooks(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	mlx_key_hook(vars->mlx, event_onkey, param);
	// mlx_mouse_hook(vars->mlx, event_onmouse, param);
	mlx_resize_hook(vars->mlx, event_onresize, param);
	mlx_loop(vars->mlx);
}

void	gameloop(void *param)
{
	short		run;
	short		update;
	t_vars		*vars;

	run = 1;
	update = 0;
	vars = (t_vars *)param;
	vars->window_height = WINDOW_DEFAULT_HEIGHT;
	vars->window_width = WINDOW_DEFAULT_WIDTH;
	map_draw(vars);
	while (run == 1)
	{
		if (update == 0)
			continue ;
		map_rotate(vars->map, (t_quaternion){0, 0, 0, 0});
		camera_move(vars->camera, (t_transform){(t_vector3){0, 0, 0},
			(t_quaternion){0, 0, 0, 0}});
		map_draw(vars);
		vars->update = 0;
	}
	debug_log("Gameloop ended");
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_map		map;
	t_camera	camera;

	if (argc != 2)
	{
		debug_error("No file given");
		return (RUN_ERROR);
	}
	vars.mlx = mlx_init(WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT,
			"FdF by jkauker", true);
	if (!vars.mlx)
	{
		debug_error("Could not initialize mlx");
		return (RUN_ERROR);
	}
	map = create_map(argv[1], open(argv[1], O_RDONLY), &vars);
	camera = camera_create((t_vector3){0, 0, 0},
			(t_quaternion){0, 0, 0, 0}, CAMERA_DEFAULT_FOV);
	vars.map = &map;
	vars.camera = &camera;
	gameloop(&vars);
	mlx_terminate(vars.mlx);
	return (RUN_SUCCESS);
}
