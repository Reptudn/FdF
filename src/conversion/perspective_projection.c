/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective_projection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:33:41 by jonask            #+#    #+#             */
/*   Updated: 2023/11/24 14:19:28 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/*
**	The point_to_matrice function is used to convert
**	the quaternion rotation and position into a 4x4
**	transformation matrix. This matrix represents the
**	3D transformation of the point in space.
**	-> PERSPECTIVE PROJECTION
*/

void	point_to_matrice(t_transform transform, t_matrice *matrice)
{
	matrice->matrice[0][3] = transform.position.x;
	matrice->matrice[1][3] = transform.position.y;
	matrice->matrice[2][3] = transform.position.z;
	matrice->matrice[0][0] = 1.0f - 2.0f
		* (pow(transform.rotation.y, 2) + pow(transform.rotation.z, 2));
	matrice->matrice[0][1] = 2.0f
		* ((transform.rotation.x * transform.rotation.y)
			- (transform.rotation.w * transform.rotation.z));
	matrice->matrice[0][2] = 2.0f
		* ((transform.rotation.x * transform.rotation.z)
			+ (transform.rotation.w * transform.rotation.y));
	matrice->matrice[1][0] = 2.0f
		* ((transform.rotation.x * transform.rotation.y)
			+ (transform.rotation.w * transform.rotation.z));
	matrice->matrice[1][1] = 1.0f - 2.0f
		* (pow(transform.rotation.x, 2) + pow(transform.rotation.z, 2));
	matrice->matrice[1][2] = 2.0f
		* ((transform.rotation.x * transform.rotation.y)
			- (transform.rotation.w * transform.rotation.x));
	matrice->matrice[2][0] = 2.0f
		* ((transform.rotation.x * transform.rotation.z)
			- (transform.rotation.w * transform.rotation.y));
	matrice->matrice[2][1] = 2.0f
		* ((transform.rotation.y * transform.rotation.z)
			+ (transform.rotation.w * transform.rotation.x));
	matrice->matrice[2][2] = 1.0f - 2.0f
		* (pow(transform.rotation.x, 2) + pow(transform.rotation.y, 2));
	matrice->matrice[3][0] = 0.0f;
	matrice->matrice[3][1] = 0.0f;
	matrice->matrice[3][2] = 0.0f;
	matrice->matrice[3][3] = 1.0f;
}

t_matrice	matrice_multiply(t_matrice matrice1, t_matrice matrice2)
{
	t_matrice	matrice;
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			matrice.matrice[i][j] = 0.0f;
			while (k < 4)
			{
				matrice.matrice[i][j] += matrice1.matrice[i][k]
					* matrice2.matrice[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (matrice);
}

/*
**	The get_screen_coordinates function then multiplies
**	this transformation matrix with the position of the
**	point to get the transformed coordinates. This is done
**	separately for the x and y coordinates.
*/

t_vector2	get_screen_coordinates(t_transform transform, t_map *map)
{
	t_vector2	coordinates;
	t_matrice	matrice;
	t_matrice	projection;
	float		perspective;

	projection = (t_matrice){0};
	matrice = (t_matrice){0};
	transform.position.z *= -1;
	point_to_matrice(transform, &matrice);
	point_to_matrice(map->transform, &projection);
	matrice = matrice_multiply(matrice, projection);
	coordinates.x = matrice.matrice[0][0] * transform.position.x
		+ matrice.matrice[0][1] * transform.position.y
		+ matrice.matrice[0][2] * transform.position.z + matrice.matrice[0][3];
	coordinates.y = matrice.matrice[1][0] * transform.position.x
		+ matrice.matrice[1][1] * transform.position.y
		+ matrice.matrice[1][2] * transform.position.z
		+ matrice.matrice[1][3];
	perspective = matrice.matrice[2][0] * transform.position.x
		+ matrice.matrice[2][1] * transform.position.y
		+ matrice.matrice[2][2] * transform.position.z
		+ matrice.matrice[2][3];
	if (perspective != 0)
	{
		coordinates.x /= perspective;
		coordinates.y /= perspective;
	} else {
		coordinates.x = -1;
		coordinates.y = -1;
	}
	//printf("Coordinates: %d, %d\n", coordinates.x, coordinates.y);
	return (coordinates);
}
