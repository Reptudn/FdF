/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:01:21 by jkauker           #+#    #+#             */
/*   Updated: 2023/10/17 13:27:28 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	get_digits(long n)
{
	long	digits;

	digits = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	put_nb_in_str(long n, long digits, char *str)
{
	str[digits] = 0;
	digits--;
	while (n > 0)
	{
		str[digits] = (n % 10) + '0';
		digits--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	long	_n;

	_n = n;
	if (n == 0)
		return (ft_strdup("0"));
	digits = get_digits(_n);
	if (_n < 1)
	{
		digits += 1;
		str = malloc((digits + 1) * sizeof(char));
		if (!str)
			return (0);
		str[0] = '-';
		_n = -_n;
	}
	else
	{
		str = malloc((digits + 1) * sizeof(char));
		if (!str)
			return (0);
	}
	put_nb_in_str(_n, digits, str);
	return (str);
}
