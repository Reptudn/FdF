/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:01:21 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/10 20:03:30 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_strlen1(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup1(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc((ft_strlen1(s) + 1) * sizeof(char));
	if (!dup)
		return (0);
	while (s[i] != 0)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

long	get_digits(long n)
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

void	put_nb_in_str(long n, long digits, char *str)
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

char	*ft_itoa1(int n)
{
	char	*str;
	int		digits;
	long	_n;

	_n = n;
	if (n == 0)
		return (ft_strdup1("0"));
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
