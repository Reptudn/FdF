/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:39:55 by jonask            #+#    #+#             */
/*   Updated: 2023/11/10 19:53:17 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_count(const char *s, char splitter)
{
	int	count;
	int	words;

	words = 0;
	count = 0;
	while (s[count] != 0)
	{
		while (s[count] == splitter)
			count++;
		if (s[count] != 0 && s[count] != splitter)
			words++;
		while (s[count] != splitter && s[count] != 0)
			count++;
	}
	return (words);
}

static int	the_split(int c, const char *s, char **strs, int i)
{
	int		word_count;
	int		max;

	max = i;
	word_count = 0;
	i = 0;
	while (*s && !(*s == c && *(s + 1) == 0) && word_count < max)
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] != c && s[i] != 0)
			i++;
		strs[word_count] = ft_substr(s, 0, i);
		if (!strs[word_count])
		{
			while (word_count > 0)
				free(strs[--word_count]);
			free(strs);
			return (0);
		}
		word_count++;
		s += i;
	}
	return (1);
}

static int	edgecase(const char *s, char c, char ***strs)
{
	if (!s || s[0] == 0)
	{
		*strs = malloc(1 * sizeof(char *));
		if (!*strs)
			return (0);
		(*strs)[0] = 0;
		return (1);
	}
	if (!c)
	{
		*strs = malloc(2 * sizeof(char *));
		if (!*strs)
			return (0);
		(*strs)[0] = ft_strdup(s);
		if (!(*strs)[0])
		{
			free(*strs);
			return (0);
		}
		(*strs)[1] = 0;
		return (1);
	}
	return (-1);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		edge;

	strs = 0;
	edge = edgecase(s, c, &strs);
	if (edge == 1)
		return (strs);
	if (edge == 0)
		return (0);
	strs = malloc((get_word_count(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (0);
	strs[get_word_count(s, c)] = 0;
	if (!the_split(c, s, strs, get_word_count(s, c)))
		return (0);
	return (strs);
}

// int	main(void)
// {
// 	char **strs = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
// 	for (int i = 0; strs[i] != 0; i++)
// 	{
// 		printf("%s\n", strs[i]);
// 	}
// 	return (0);
// }
