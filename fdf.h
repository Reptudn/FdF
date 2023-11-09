/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:13:45 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/09 10:34:09 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>

# include <OpenGL/gl3.h> //needed for mlx_int.h

# ifdef __linux__
#  include "./sources/minilibx_linux/mlx.h"
// #  include "./sources/minilibx_linux/mlx_int.h"
# elif __APPLE__
#  include "./sources/minilibx_macos/mlx.h"
// #  include "./sources/minilibx_macos/mlx_int.h"
# else
#  include "./sources/minilibx/mlx.h"
// #  include "./sources/minilibx/mlx_int.h"
# endif

# include <stdio.h>
# include <stdlib.h>

# define WINDOW_MIN_WIDTH		640
# define WINDOW_MAX_WIDTH		-1
# define WINDOW_MIN_HEIGHT		480
# define WINDOW_MAX_HEIGHT		-1
# define WINDOW_DEFAULT_WIDTH	1080
# define WINDOW_DEFAULT_HEIGHT	720

# define CAMERA_DEFAULT_FOV		60

# define RUN_SUCCESS			0
# define RUN_ERROR				-1

typedef struct s_vector3
{
	int	x;
	int	y;
	int	z;
}				t_vector3;

typedef struct s_quaternion
{
	int	x;
	int	y;
	int	z;
	int	w;
}				t_quaternion;

typedef struct s_transform
{
	t_vector3		position;
	t_quaternion	rotation;
}				t_transform;

typedef struct s_line
{
	t_vector3	start;
	t_vector3	end;
}				t_line;

typedef struct s_camera
{
	t_transform		transform;
	double			fov;
}				t_camera;

typedef struct s_map
{
	char			*map_name;
	int				size_x;
	int				size_y;
	t_transform		transform;
	t_vector3		**points;
}				t_map;

t_vector3		**get_map(int fd);

// map
void			map_rotate(t_map *map, t_quaternion rot);
void			map_draw(t_map	*map, t_camera *cam);

// window
int				window_open(char *name, void *mlx, void *window);
void			window_close(void *window);
void			window_resize(void *window, int width, int height);

// events
short			event_triggered(void *mlx, short *run);
int				register_all_events(void *mlx);

// camera
void			camera_move(t_camera *cam, t_transform transform);
t_camera		camera_create(t_vector3 position, t_quaternion rotation,
					double fov);

// draw
void			draw_line(t_line line);

// math
t_vector3		vector_add(t_vector3 vec1, t_vector3 vec2);
t_vector3		vector_substract(t_vector3 vec1, t_vector3 vec2);
double			vector_distance(t_vector3 vec1, t_vector3 vec2);
double			vector_length(t_vector3 vec);
t_vector3		vector_new(int x, int y, int z);
t_vector3		vector_rotate(t_vector3 vec, t_quaternion rot);
t_quaternion	quaternion_add(t_quaternion quaternion1,
					t_quaternion quaternion2);
double			quaternion_dotprod(t_quaternion quaternion1,
					t_quaternion quaternion2);
double			quaternion_angle_between(t_quaternion quaternion1,
					t_quaternion quaternion2);
t_quaternion	quaternion_new(int x, int y, int z, int w);

// raycast
int				is_visible_to_camera(t_camera *cam, t_vector3 *point);

// debug
void			debug_error(char *error_msg);
void			debug_log(char *log_msg);

#endif
