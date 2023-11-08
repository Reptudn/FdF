#include "fdf.h"
#include <fcntl.h>

t_map	create_map(char *map_name, int fd)
{
	t_map	map;

	map = malloc(sizeof(t_map));
	map.map_name = map_name;
	map.points = get_map(fd);
	map.origin = (t_vector3){0, 0, 0};
	map.rotation = (t_quaternion){0, 0, 0, 0};
	return (map);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_camera	cam;
	short		run;
	short		update;

	run = 1;
	update = 0;
	if (argc != 2)
	{
		printf("No file given and / or wrong file format not ending with -.fdf\n");
		return (1);
	}
	map = create_map(argv[1], open(argv[1], O_RDONLY));
	if (!map)
	{
		printf("Error creating map\n");
		return (1);
	}
	open_window(argv[1], WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT);
	draw_map(&map);
	while(run == 1)
	{
		if (update == 0)
			continue ;
		rotate_map(&map, 0); // calcualte new quaternion
		move_camera(&cam, 0); //calculate new transform
		draw_map(&map);
	}
	free(map);
	close_window();
	return (0);
}
