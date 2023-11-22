/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:18:22 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/22 09:45:46 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_single_value(char last, char first)
{
	int		value;

	value = 0;
	if (last >= '0' && last <= '9')
		value += (last - '0') * 16;
	else if (last >= 'a' && last <= 'f')
		value += (last - 'a' + 10) * 16;
	else if (last >= 'A' && last <= 'F')
		value += (last - 'A' + 10) * 16;
	if (first >= '0' && first <= '9')
		value += (first - '0');
	else if (first >= 'a' && first <= 'f')
		value += (first - 'a' + 10);
	else if (first >= 'A' && first <= 'F')
		value += (first - 'A' + 10);
	return (value);
}

int	hex_to_color(char *str)
{
	int		r;
	int		g;
	int		b;
	// int		a;

	// write(1, "begin\n", 6);
	// printf("Color: %s\n", str);
	// write(1, "end\n", 4);
	if (str[0] == '0' && str[1] == 'x')
		str += 2;
	r = get_single_value(str[0], str[1]);
	g = get_single_value(str[2], str[3]);
	b = get_single_value(str[4], str[5]);
	// if (str[6] != 0 && str[7] != 0)
	// 	a = get_single_value(str[6], str[7]);
	// else
	// 	a = 255;
	return (get_rgba(r, g, b, 255));
}