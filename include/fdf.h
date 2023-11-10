/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:13:45 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/10 16:23:16 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib//ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"

// # include <OpenGL/gl3.h> //needed for mlx_int.h

// https://harm-smits.github.io/42docs/libs/minilibx/events.html

// # ifdef __linux__
// #  include "./sources/minilibx_linux/mlx.h"
// # elif __APPLE__
// #  include "./sources/minilibx_macos/mlx.h"
// # else
// #  include "./sources/minilibx/mlx.h"
// # endif

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

typedef struct s_vector2
{
	int	x;
	int	y;
}				t_vector2;

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

typedef struct s_matrice
{
	int				matrice[4][4];
}				t_matrice;

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
	short		run;
	short		update;
	void		*mlx;
	mlx_image_t	*image;
	int			window_width;
	int			window_height;
	t_map		*map;
	t_camera	*camera;
}				t_vars;

t_vector3		**get_map(int fd, t_vars *vars);

// map
void			map_rotate(t_map *map, t_quaternion rot);
void			map_draw(void *param);

// events
void			event_onresize(int x, int y, void *param);
void			event_onkey(mlx_key_data_t keycode, void *param);
void			event_onmouse(mlx_key_data_t keycode, void *param);

// vector to 2d conversion
t_vector2		get_screen_coordinates(t_transform transform, t_camera *camera);

// camera
void			camera_move(t_camera *cam, t_transform transform);
t_camera		camera_create(t_vector3 position, t_quaternion rotation,
					double fov);

// color utils
// int				get_rgba(int r, int g, int b, int a);
int				get_r(int rgba);
int				get_g(int rgba);
int				get_b(int rgba);
int				get_a(int rgba);

// draw
void			draw_line(t_vector2 start, t_vector2 end,
					void *param, int color);
void			draw_dot(t_vector2 middle_point,
					int radius, void *param, int color);

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
void			debug_print_map(t_map map);

#endif
