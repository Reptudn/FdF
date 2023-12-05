/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:54:22 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/05 08:58:11 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	color_difference(int color1, int color2)
{
	if (color1 > color2)
		return (get_rgba(get_r(color1) - get_r(color2),
				get_g(color1) - get_g(color2),
				get_b(color1) - get_b(color2), 255));
	return (get_rgba(get_r(color2) - get_r(color1),
			get_g(color2) - get_g(color1),
			get_b(color2) - get_b(color1), 255));
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	absolute(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	get_next_gradient_color(int start, int end, int steps, int *i)
{
	int		r;
	int		g;
	int		b;
	int		a;
	int		gradient;

	if (steps == 0 || start == end)
		return (start);
	gradient = color_difference(start, end);
	r = get_r(start) + (get_r(gradient) * (*i) / steps);
	g = get_g(start) + (get_g(gradient) * (*i) / steps);
	b = get_b(start) + (get_b(gradient) * (*i) / steps);
	a = get_a(start) + (get_a(gradient) * (*i) / steps);
	*i += 1;
	return (get_rgba(r, g, b, a));
}
