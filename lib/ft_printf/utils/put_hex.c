/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:12:41 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/10 14:10:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	put_hex(long long num, int capital, int prefix, int *writecount)
{
	if (prefix == 1)
	{
		if (num == 0)
			put_string("0x0", writecount);
		else
			put_base(num, 16, capital, writecount);
	}
	else
	{
		if (num == 0)
			put_string("0", writecount);
		else
			put_base_hex(num, 16, capital, writecount);
	}
}
