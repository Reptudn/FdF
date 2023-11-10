/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:38:12 by jonask            #+#    #+#             */
/*   Updated: 2023/10/10 12:46:52 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	move(unsigned char *dest, unsigned char *src, size_t n)
{
	size_t	i;

	if (src < dest && src + n > dest)
	{
		while (n > 0)
		{
			n--;
			dest[n] = src[n];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (dest == src)
		return (dest);
	move (temp_dest, temp_src, n);
	return (dest);
}
