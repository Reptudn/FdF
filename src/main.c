/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:13:54 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/11 13:53:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdlib.h>

/*
**	This function is only here because if norm lol
*/
void	close_file(int fd, t_map *map)
{
	if (map->points == 0)
		free(map);
	get_next_line(-1);
	close(fd);
	write(1, "\nMap read complete without errors.\n", 36);
}

t_map	*create_map(char *map_name, int fd, t_vars *vars)
{
	t_map	*map;

	if (fd == -1)
	{
		write(1, "Could not open file!\n", 21);
		exit(1);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		exit(1);
	map->map_name = map_name;
	map->points = get_map(fd, map);
	close_file(fd, map);
	if (map->points == 0)
	{
		free(map->map_name);
		free(map);
		exit(1);
	}
	map->transform.position = (t_vector3){0, 0, 0, 0, (t_vector2){0, 0}};
	map->transform.rotation = (t_quaternion){0, 0, 0, 0};
	vars->map = map;
	return (map);
}

void	gameloop(void *param)
{
	t_vars		*vars;

	vars = (t_vars *)param;
	if (vars->update == 0 || vars->run == 0)
		return ;
	if (vars->map->size_x == 1 && vars->map->size_y == 1)
	{
		draw_one(vars);
		return ;
	}
	mlx_delete_image(vars->mlx, vars->image);
	if (vars->projection == PROJECTION_PERSPECTIVE)
		map_draw(param);
	else if (vars->projection == PROJECTION_FLAT)
		map_draw_flat(vars);
	else
		map_draw_isometric(param);
	draw_all_lines(vars);
	window_ui_show_controls(vars);
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
	vars->draw_size = 3;
	vars->projection = PROJECTION_ISOMETRIC;
	vars->mouse.button = 0;
	vars->mouse.x = 0;
	vars->mouse.y = 0;
	vars->mouse.prev_x = 0;
	vars->mouse.prev_y = 0;
	center(vars);
	map_draw_isometric(param);
	draw_all_lines(vars);
	window_ui_show_controls(vars);
	mlx_key_hook(vars->mlx, event_onkey, param);
	mlx_close_hook(vars->mlx, event_onclose, param);
	mlx_resize_hook(vars->mlx, event_onresize, param);
	mlx_loop_hook(vars->mlx, gameloop, param);
	mlx_scroll_hook(vars->mlx, event_onscroll, param);
	mlx_cursor_hook(vars->mlx, event_oncursor_move, param);
	mlx_loop(vars->mlx);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_map		*map;
	t_camera	camera;

	if (check_input(argc, argv) == 0)
		return (RUN_ERROR);
	vars.mlx = mlx_init(WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT,
			ft_strjoin("FdF by jkauker | Map: ", argv[1]), true);
	if (!vars.mlx)
	{
		debug_error("Could not initialize mlx!");
		return (RUN_ERROR);
	}
	map = create_map(argv[1], open(argv[1], O_RDONLY), &vars);
	camera = camera_create((t_vector3){20, 10, 0, 0, (t_vector2){0, 0}},
			(t_quaternion){0, 0, 0, 0}, 0.3);
	vars.map = map;
	vars.camera = &camera;
	vars.draw_line = 0;
	register_hooks(&vars);
	mlx_terminate(vars.mlx);
	return (RUN_SUCCESS);
}
