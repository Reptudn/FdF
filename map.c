#include "fdf.h"

void	rotate_map(t_map *map, t_quaternion rot)
{
	/*
	rotate map stuff
	*/
	map->transform.rotation = quaternion_add(map->transform.rotation, rot);
}

void	draw_map(t_map	*map, t_camera *cam)
{
	/*
	draw map stuff
	*/
}