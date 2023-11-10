/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_to_2d_conversion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:33:41 by jonask            #+#    #+#             */
/*   Updated: 2023/11/10 10:12:16 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	point_to_matrice(t_transform transform, t_matrice *matrice)
{
	matrice->matrice[0][3] = transform.position.x;
	matrice->matrice[1][3] = transform.position.y;
	matrice->matrice[2][3] = transform.position.z;

	matrice->matrice[0][0] = 1.0f - 2.0f * (pow(transform.rotation.y, 2) + pow(transform.rotation.z, 2));
	matrice->matrice[0][1] = 2.0f * ((transform.rotation.x * transform.rotation.y) - (transform.rotation.w * transform.rotation.z));
	matrice->matrice[0][2] = 2.0f * ((transform.rotation.x * transform.rotation.z) + (transform.rotation.w * transform.rotation.y));

	matrice->matrice[1][0] = 2.0f * ((transform.rotation.x * transform.rotation.y) + (transform.rotation.w * transform.rotation.z));
	matrice->matrice[1][1] = 1.0f - 2.0f * (pow(transform.rotation.x, 2) + pow(transform.rotation.z, 2));
	matrice->matrice[1][2] = 2.0f * ((transform.rotation.x * transform.rotation.y) - (transform.rotation.w * transform.rotation.x));

	matrice->matrice[2][0] = 2.0f * ((transform.rotation.x * transform.rotation.z) - (transform.rotation.w * transform.rotation.y));
	matrice->matrice[2][1] = 2.0f * ((transform.rotation.y * transform.rotation.z) + (transform.rotation.w * transform.rotation.x));
	matrice->matrice[2][2] = 1.0f - 2.0f * (pow(transform.rotation.x, 2) + pow(transform.rotation.y, 2));

	matrice->matrice[3][0] = 0.0f;
	matrice->matrice[3][1] = 0.0f;
	matrice->matrice[3][2] = 0.0f;
	matrice->matrice[3][3] = 1.0f;
}

t_vector2	get_screen_coordinates(t_transform transform)
{
	t_vector2	coordinates;
	t_matrice	matrice;

	point_to_matrice(transform, &matrice);

	

	return (coordinates);
}

