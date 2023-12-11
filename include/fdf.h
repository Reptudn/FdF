/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:13:45 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/11 16:56:39 by jkauker          ###   ########.fr       */
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

typedef enum e_projection
{
	PROJECTION_ISOMETRIC = 0,
	PROJECTION_PERSPECTIVE = 1,
	PROJECTION_FLAT = 2
}				t_projection;

typedef struct s_vector2
{
	int	x;
	int	y;
}				t_vector2;

typedef struct s_vector3
{
	int			x;
	int			y;
	int			z;
	int			color;
	t_vector2	screen;
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

typedef struct s_matrice
{
	int				matrice[4][4];
}				t_matrice;

typedef struct s_3x3matrice
{
	int				matrice[3][3];
}				t_3x3matrice;

typedef struct s_gradient
{
	int				start;
	int				end;
}				t_gradient;

typedef struct s_camera
{
	t_transform		transform;
	float			near;
	float			far;
	double			zoom;
}				t_camera;

typedef struct s_map
{
	char			*map_name;
	int				size_x;
	int				size_y;
	t_transform		transform;
	t_vector3		**points;
}				t_map;

typedef struct s_mouse
{
	double				x;
	double				y;
	double				prev_x;
	double				prev_y;
	int					button;
}				t_mouse;

typedef struct s_vars
{
	short			run;
	short			update;
	void			*mlx;
	mlx_image_t		*image;
	int				window_width;
	int				window_height;
	t_map			*map;
	t_camera		*camera;
	int				draw_size;
	int				draw_line;
	t_projection	projection;
	t_mouse			mouse;
}				t_vars;

t_vector3		**get_map(int fd, t_map *map_struct);

// map
void			map_move(t_vector3 position, t_map *map);
void			center(t_vars *vars);
void			reset_tranform(t_vars *vars);
void			map_draw_flat(t_vars *vars);
void			map_rotate(double rotation, t_vector3 axis, t_map *map);

// events
void			event_onresize(int x, int y, void *param);
void			event_onkey(mlx_key_data_t keycode, void *param);
void			event_onmouse(mlx_key_data_t keycode, void *param);
void			event_onscroll(double xdelta, double ydelta, void *param);
void			event_onclose(void *param);
void			event_onfail(void *param, int rows);
void			event_oncursor_move(double x, double y, void *param);

// vector to 2d conversion
t_vector2		get_screen_coordinates(t_transform transform, t_map *map);

t_vector2		to_screen(t_vector3 point, t_vars *vars);

// camera
void			camera_move(t_camera *cam, t_transform transform);
t_camera		camera_create(t_vector3 position, t_quaternion rotation,
					double zoom);

// color utils
int				hex_to_color(char *str);
int				get_r(int rgba);
int				get_g(int rgba);
int				get_b(int rgba);
int				get_a(int rgba);
int				get_rgba(int r, int g, int b, int a);
int				color_difference(int color1, int color2);
int				get_next_gradient_color(int start, int end, int steps, int *i);

// draw
void			draw_line_to_neighbours(t_vars *vars, t_vector2 curr_point,
					int x, int y);
void			draw_dot(t_vector2 middle_point,
					int radius, void *param, int color);
void			draw_square(t_vector2 middle_point, int size,
					void *param, int color);
void			draw_line(t_vector2 start, t_vector2 end, void *param,
					t_gradient color);
void			draw_all_lines(t_vars *vars);

// math
t_vector3		vector_add(t_vector3 vec1, t_vector3 vec2);
t_vector3		vector_substract(t_vector3 vec1, t_vector3 vec2);
double			vector_distance(t_vector3 vec1, t_vector3 vec2);
double			vector_length(t_vector3 vec);
t_vector3		vector_new(int x, int y, int z, int color);
t_vector3		vector_rotate(t_vector3 vec, t_quaternion rot);
t_quaternion	quaternion_add(t_quaternion quaternion1,
					t_quaternion quaternion2);
double			quaternion_dotprod(t_quaternion quaternion1,
					t_quaternion quaternion2);
double			quaternion_angle_between(t_quaternion quaternion1,
					t_quaternion quaternion2);
t_quaternion	quaternion_new(int x, int y, int z, int w);
t_quaternion	angle_to_quaternion(float theta, t_vector3 axis);
t_matrice		matrice_multiply(t_matrice matrice1, t_matrice matrice2);
int				max(int a, int b);
int				absolute(int a);

// ui
void			window_ui_show_controls(t_vars *vars);

// debug
void			debug_error(char *error_msg);
void			debug_log(char *log_msg);
void			debug_print_map(t_map map);
void			debug_draw_info(t_vars *vars);

// projection
t_vector2		isometric_projection(t_vector3 input, t_vars *vars);
void			map_draw_isometric(t_vars *vars);
void			map_draw(t_vars *vars);

// utils
void			*ft_realloc(void *ptr, size_t size);
void			coords_apply_offset(t_vector2 *point, t_vector3 *base,
					t_vars *vars);
void			coords_apply_flat_offset(t_vars *vars, t_vector2 *point);
int				check_input(int argc, char **argv);

void			draw_one(t_vars *vars);
void			ft_exit(int exitcode);

#endif
