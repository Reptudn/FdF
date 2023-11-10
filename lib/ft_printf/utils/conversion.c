/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:26:52 by jonask            #+#    #+#             */
/*   Updated: 2023/11/10 19:58:47 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "../ft_printf.h"

void	put_char(char c, int *writecount)
{
	if (write(1, &c, 1) == -1)
		*writecount = -1;
	else
		*writecount += 1;
}

void	put_string(char *str, int *writecount)
{
	int	i;

	i = 0;
	if (str == 0)
	{
		put_string("(null)", writecount);
		return ;
	}
	while (str[i] != 0 && *writecount != -1)
	{
		put_char(str[i], writecount);
		i++;
	}
}

void	put_number(int num, int *writecount)
{
	char	*str;

	str = ft_itoa1(num);
	if (!str)
	{
		free(str);
		*writecount = -1;
		return ;
	}
	put_string(str, writecount);
	free(str);
}

void	put_long(long num, int *writecount)
{
	char	*str;

	str = ltoa(num);
	if (!str)
	{
		free(str);
		*writecount = -1;
		return ;
	}
	put_string(str, writecount);
	free(str);
}

void	put_pointer(void *ptr, int *writecount)
{
	if (ptr == 0)
		put_string("0x0", writecount);
	else
		put_base((unsigned long) ptr, 16, 0, writecount);
}

// void	put_double(double num)
// {
// 	double	decimal;
// 	int		intpart;

// 	if (num < 0)
// 	{
// 		write(1, "-", 1);
// 		num = -num;
// 	}
// 	intpart = (int)num;
// 	decimal = num - intpart;
// 	while (intpart > 0)
// 	{
// 		put_char((intpart % 10) + '0');
// 		intpart /= 10;
// 	}
// 	put_char('.');
// 	while (decimal != 0.0)
// 	{
// 		decimal *= 10;
// 		put_char((int)decimal + '0');
// 		decimal -= (int)decimal;
// 	}
// }

// void	put_float(float num)
// {
// 	put_double((double)num);
// }
