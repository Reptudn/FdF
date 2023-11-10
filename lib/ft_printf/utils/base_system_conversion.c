/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_system_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:02 by jonask            #+#    #+#             */
/*   Updated: 2023/11/10 19:59:11 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>
#include <unistd.h>

void	*ft_memset1(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	write_base(char base_buff[], int len, int *writecount)
{
	int	i;

	i = len;
	put_string("0x", writecount);
	while (i < 21 && *writecount != -1)
	{
		if (base_buff[i] == 'u')
		{
			i++;
			continue ;
		}
		if (write(1, &base_buff[i], 1) == -1)
			*writecount = -1;
		else
			*writecount += 1;
		i++;
	}
}

void	write_base_hex(char base_buff[], int len, int *writecount)
{
	int	i;

	i = len;
	while (i < 21 && *writecount != -1)
	{
		if (base_buff[i] == 'u')
		{
			i++;
			continue ;
		}
		if (write(1, &base_buff[i], 1) == -1)
			*writecount = -1;
		else
			*writecount += 1;
		i++;
	}
}

void	put_base(unsigned long num, int base, int capital, int *writecount)
{
	char		c;
	long long	n;
	char		buff[21];
	int			i;

	i = 20;
	ft_memset1(buff, 'u', 21);
	while (num > 0 && *writecount != -1)
	{
		n = (num % base);
		if (n < 10)
			c = n + '0';
		else
		{
			if (capital)
				c = n - 10 + 'A';
			else
				c = n - 10 + 'a';
		}
		buff[i--] = c;
		num /= base;
	}
	write_base(buff, i, writecount);
}

void	put_base_hex(long long num, int base, int capital, int *writecount)
{
	char		c;
	long long	n;
	char		buff[21];
	int			i;

	i = 20;
	if (num < 0)
		num = -num;
	ft_memset1(buff, 'u', 21);
	while (num > 0 && *writecount != -1)
	{
		n = (num % base);
		if (n < 10)
			c = n + '0';
		else
		{
			if (capital)
				c = n - 10 + 'A';
			else
				c = n - 10 + 'a';
		}
		buff[i--] = c;
		num /= base;
	}
	write_base_hex(buff, i, writecount);
}
