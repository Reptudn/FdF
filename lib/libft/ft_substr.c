/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:14:09 by jonask            #+#    #+#             */
/*   Updated: 2023/10/17 13:29:07 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	makesub(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != 0 && (i + 1 < size))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if (start >= ft_strlen(s) || (start == 0 && len == 0))
		return (ft_strdup(""));
	if (start == 0 && len >= ft_strlen(s))
		return (ft_strdup(s));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	makesub(sub, s + start, len + 1);
	sub[len + 1] = 0;
	return (sub);
}
