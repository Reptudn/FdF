/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:58:37 by jonask            #+#    #+#             */
/*   Updated: 2023/11/10 19:52:25 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

void	*ft_calloc(size_t nmenb, size_t size)
{
	int		*pog;
	size_t	total;

	if (size != 0 && nmenb > SSIZE_MAX / size)
		return (0);
	total = nmenb * size;
	pog = malloc(total);
	if (!pog)
		return (0);
	ft_memset(pog, 0, total);
	return (pog);
}
