/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:13:54 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/24 09:51:31 by jkauker          ###   ########.fr       */
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
	map.points = get_map(fd, &map);
	if (map.points == 0)
	{
		debug_error("Could not create map");
		exit(1);
	}
	map.transform.position = (t_vector3){0, 0, 0, 0};
	map.transform.rotation = (t_quaternion){0, 0, 0, 0};
	vars->map = &map;
	return (map);
}

void	gameloop(void *param)
{
	t_vars		*vars;

	vars = (t_vars *)param;
	
	if (vars->update == 0 || vars->run == 0)
			return ;
	mlx_delete_image(vars->mlx, vars->image);
	if (vars->projection == PROJECTION_PERSPECTIVE)
		map_draw(param);
	else if (vars->projection == PROJECTION_FLAT)
		map_draw_flat(vars);
	else
		map_draw_isometric(param);
	update_window_ui(vars);
	debug_draw_info(vars);
	vars->update = 0;
}

void	register_hooks(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	vars->run = 1;
	vars->update = 0;
	vars->window_height = WINDOW_DEFAULT_HEIGHT;
	vars->window_width = WINDOW_DEFAULT_WIDTH;
	vars->draw_size = 5;
	vars->projection = PROJECTION_PERSPECTIVE;
	center(vars);
	map_draw(param);
	update_window_ui(vars);
	mlx_key_hook(vars->mlx, event_onkey, param);
	mlx_close_hook(vars->mlx, event_onclose, param);
	mlx_resize_hook(vars->mlx, event_onresize, param);
	mlx_loop_hook(vars->mlx, gameloop, param);
	mlx_scroll_hook(vars->mlx, event_onscroll, param);
	mlx_loop(vars->mlx);
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
			ft_strjoin("FdF by jkauker | Map: ", argv[1]), true);
	if (!vars.mlx)
	{
		debug_error("Could not initialize mlx");
		return (RUN_ERROR);
	}
	map = create_map(argv[1], open(argv[1], O_RDONLY), &vars);
	camera = camera_create((t_vector3){200, 300, 0, 0},
			(t_quaternion){0, 0, 0, 0}, CAMERA_DEFAULT_FOV);
	vars.map = &map;
	vars.camera = &camera;
	vars.draw_line = 0;
	register_hooks(&vars);
	mlx_terminate(vars.mlx);
	return (RUN_SUCCESS);
}
