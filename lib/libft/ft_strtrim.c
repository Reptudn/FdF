/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:16:43 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/10 19:57:20 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start_index;
	size_t	end_index;
	char	*trimmed;
	int		i;
	size_t	len;

	start_index = 0;
	end_index = 0;
	i = 0;
	while (isinset(set, s1[i++]))
		start_index++;
	end_index = ft_strlen(s1);
	while (end_index > start_index && isinset(set, s1[end_index - 1]))
		end_index--;
	len = end_index - start_index;
	trimmed = malloc(sizeof(char) * (len + 1));
	if (!trimmed)
		return (0);
	i = 0;
	while (start_index < end_index)
		trimmed[i++] = s1[start_index++];
	trimmed[i] = 0;
	return (trimmed);
}

// int main()
// {
//     printf("%s\n", ft_strtrim(" lorem ipsum dolor sit amet", " "));

//     return 0;
// }
