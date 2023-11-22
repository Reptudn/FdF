/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3x3matrice_projection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:46:38 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/22 11:32:39 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <math.h>

t_3x3matrice rotate_z(double angle)
{
	t_3x3matrice matrice;

	matrice.matrice[0][0] = cos(angle);
	matrice.matrice[0][1] = -sin(angle);
	matrice.matrice[0][2] = 0;

	matrice.matrice[1][0] = sin(angle);
	matrice.matrice[1][1] = cos(angle);
	matrice.matrice[1][2] = 0;

	matrice.matrice[2][0] = 0;
	matrice.matrice[2][1] = 0;
	matrice.matrice[2][2] = 1;
	return (matrice);
}

t_3x3matrice rotate_y(double angle)
{
	t_3x3matrice matrice;

	matrice.matrice[0][0] = cos(angle);
	matrice.matrice[0][1] = 0;
	matrice.matrice[0][2] = sin(angle);

	matrice.matrice[1][0] = 0;
	matrice.matrice[1][1] = 1;
	matrice.matrice[1][2] = 0;

	matrice.matrice[2][0] = -sin(angle);
	matrice.matrice[2][1] = 0;
	matrice.matrice[2][2] = cos(angle);
	return (matrice);
}

t_3x3matrice rotate_x(double angle)
{
	t_3x3matrice matrice;

	matrice.matrice[0][0] = 1;
	matrice.matrice[0][1] = 0;
	matrice.matrice[0][2] = 0;

	matrice.matrice[1][0] = 0;
	matrice.matrice[1][1] = cos(angle);
	matrice.matrice[1][2] = -sin(angle);

	matrice.matrice[2][0] = 0;
	matrice.matrice[2][1] = sin(angle);
	matrice.matrice[2][2] = cos(angle);
	return (matrice);
}

t_3x3matrice	dot_product(t_3x3matrice one, t_3x3matrice second)
{
	t_3x3matrice result;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result.matrice[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                result.matrice[i][j] += one.matrice[i][k] * second.matrice[k][j];
            }
        }
    }

    return result;
}

t_3x3matrice	point_to_matrice3x3(t_vector3 pos)
{
	t_3x3matrice	projection;

	projection.matrice[0][0] = pos.x;
	projection.matrice[0][1] = 0;
	projection.matrice[0][2] = 0;
	projection.matrice[0][0] = 0;
	projection.matrice[1][1] = pos.y;
	projection.matrice[2][2] = 0;
	projection.matrice[0][0] = 0;
	projection.matrice[1][1] = 0;
	projection.matrice[2][2] = pos.z;
	return (projection);
}

t_vector2	to_screen(t_vector3 point, t_vars *vars)
{
	t_vector2		screen;
	t_3x3matrice	projection;
	int				scale;

	scale = 1;
	projection.matrice[0][0] = 1;
	projection.matrice[0][1] = 0;
	projection.matrice[0][2] = 0;
	projection.matrice[0][0] = 0;
	projection.matrice[1][1] = 1;
	projection.matrice[2][2] = 0;
	projection.matrice[0][0] = 0;
	projection.matrice[1][1] = 0;
	projection.matrice[2][2] = 1;
	projection = dot_product(projection, point_to_matrice3x3(point));
	projection = dot_product(projection, rotate_x(5));
	projection = dot_product(projection, rotate_y(5));
	projection = dot_product(projection, rotate_z(5));
	screen.x = (int)(projection.matrice[0][0] * scale) + (vars->window_height / 2) / 10 + 100;
	screen.y = (int)(projection.matrice[1][0] * scale) + (vars->window_width / 2) / 10 + 100;
	printf("x: %d, y: %d\n", screen.x, screen.y);
	return (screen);
}