/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:36:09 by jonask            #+#    #+#             */
/*   Updated: 2023/11/10 19:55:57 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		total_len;
	char	*joined;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = malloc(total_len * sizeof(char));
	if (!joined)
		return (0);
	ft_strlcpy(joined, s1, total_len);
	ft_strlcat(joined, s2, total_len);
	return (joined);
}
