#ifndef FDF_H
# define FDF_H

#include <math.h>
#include <fcntl.h>

#ifdef __linux__
# include "./sources/minilibx_linux/mlx.h"
# include "./sources/minilibx_linux/mlx_int.h"
#elif __APPLE
# include "./sources/minilibx_macos/mlx.h"
# include "./sources/minilibx_macos/mlx_int.h"
#else
# include "./sources/minilibx/mlx.h"
# include "./sources/minilibx/mlx_int.h"
#endif

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

t_vector3		**get_map(int fd);

// map
void			rotate_map(t_map *map, t_quaternion rot);
void			draw_map(t_map	*map);

// window
void			open_window(char *name, int width, int height);
void			close_window();

// camera
void			move_camera(t_camera cam, t_transform transform);

// math
t_vector3		vector_add(t_vector3 vec1, t_vector3 vec2);
t_vector3		vector_substract(t_vector3 vec1, t_vector3 vec2);
double			vector_distance(t_vector3 vec1, t_vector3 vec2);
double			vector_length(t_vector3 vec);
t_vector3		vector_new(int x, int y, int z);
t_quaternion	quaternion_add(t_quaternion quaternion1, t_quaternion quaternion2);
double			quaternion_dotprod(t_quaternion quaternion1, t_quaternion quaternion2);
double			quaternion_angle_between(t_quaternion quaternion1, t_quaternion quaternion2);
t_quaternion	quaternion_new(int x, int y, int z, int w);

#endif