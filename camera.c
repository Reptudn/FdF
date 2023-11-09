#include "fdf.h"

void	move_camera(t_camera *cam, t_transform transform)
{
	cam->transform.position = vector_add(cam->transform.position, transform.position)
}