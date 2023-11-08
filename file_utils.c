#include "fdf.h"

t_vector3	convert_to_vector3(int x, int y, int z)
{
	t_vector3	vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vector3	**get_map(int fd)
{
	t_vector3	**map;
	int			x;
	int			y;

	x = 0;
	y = 0;
	/*
	read file line by line and realloc the **map
	map[x][y] and the value whats in that is z
	*/
	close(fd);
	return (map);
}