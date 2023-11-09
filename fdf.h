/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:13:45 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/09 13:11:47 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>

# include <OpenGL/gl3.h> //needed for mlx_int.h

// https://harm-smits.github.io/42docs/libs/minilibx/events.html

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

typedef enum e_events
{
	EVENT_KEY_PRESS = 2,
	EVENT_KEY_RELEASE = 3,
	EVENT_MOUSE_PRESS = 4,
	EVENT_MOUSE_RELEASE = 5,
	EVENT_MOUSE_MOVE = 6,
	EVENT_EXPOSE = 12,
	EVENT_CLOSE = 17
}				t_events;

typedef enum e_mousekeys
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2,
	MOUSE_MIDDLE = 3,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5
}				t_mousekeys;

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

typedef struct s_vars
{
	short	*run;
	short	*update;
}				t_vars;

t_vector3		**get_map(int fd);

// map
void			map_rotate(t_map *map, t_quaternion rot);
void			map_draw(t_map	*map, t_camera *cam);

// window
int				window_open(char *name, void *mlx, void *window);
void			window_close(void *mlx, void *window);
// void			window_resize(void *window, int width, int height);
void			window_clear(void *mlx, void *window);

// events
int				register_all_events(void *mlx, void *window, t_vars *vars);

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
