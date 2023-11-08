#ifndef FDF_H
# define FDF_H

#include <math.h>

#include <stdio.h>
#include <stdlib.h>

#define WINDOW_MIN_WIDTH		640
#define WINDOW_MAX_WIDTH		-1
#define WINDOW_MIN_HEIGHT		480
#define WINDOW_MAX_HEIGHT		-1
#define WINDOW_DEFAULT_WIDTH	1080
#define WINDOW_DEFAULT_HEIGHT	720

typedef struct	s_vector3
{
	int	x;
	int	y;
	int	z;
}				t_vector3;

typedef struct	s_quaternion
{
	int	x;
	int	y;
	int	z;
	int	w;
}				t_quaternion;

typedef struct	s_transform
{
	s_vector3		position;
	s_quaternion	rotation;
}				t_transform;

typedef struct	s_line
{
	t_vector3	start;
	t_vector3	end;
}				t_line;

typedef	struct	s_camera
{
	t_transform		transform;
	double			fov;
}				t_camera;

typedef struct	s_map
{
	char			*map_name;
	int				size_x;
	int				size_y;
	t_transform		transform;
	s_vector3		**points;
}				t_map;

t_vector3	**get_map(int fd);

// map
void	move_camera(t_camera *cam, t_vector3 pos, t_quaternion rot);
void	rotate_map(t_map *map, t_quaternion rot);
void	draw_map(t_map	*map);

// window
void	open_window(char *name, int width, int height);
void	close_window();

#endif