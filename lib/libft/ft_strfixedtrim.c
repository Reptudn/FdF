/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfixedtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:23:41 by jonask            #+#    #+#             */
/*   Updated: 2023/10/09 14:16:18 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

static int	substrcmp(const char *s1, const char *s2, int start_index)
{
	int	i;

	i = 0;
	while (s1[start_index + i] != 0 && s2[i] != 0)
	{
		if (s1[start_index + i] != s2[i])
			return (0);
		i++;
	}
	return (i);
}

char	*ft_strfixedtrim(const char *s1, const char *set)
{
	int		i;
	char	*str;
	int		size;
	int		t;

	size = 0;
	if (s1 == 0)
		return (0);
	t = substrcmp(s1, set, 0);
	size = getlen(s1) - (t + substrcmp(s1, set, getlen(s1) - getlen(set)));
	str = malloc(size * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	str[size] = 0;
	while (size > 0)
	{
		str[i] = s1[i + t];
		i++;
		size--;
	}
	return (str);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	argc++;
	printf("%s\n", ft_strtrim(argv[1], argv[2]));
}
*/