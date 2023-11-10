/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:09 by jonask            #+#    #+#             */
/*   Updated: 2023/11/10 19:46:42 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/specifiers.h"
#include "ft_printf.h"
#include <limits.h>

int	handle_percent(const char *str, int *i, int *writecount)
{
	if (str[*i + 1] != 0 && str[*i + 1] == '%' && str[*i] == '%')
	{
		put_char('%', writecount);
		*i += 2;
		return (1);
	}
	return (0);
}

int	handle_specifier(const char *str, int *i, int *writecount, va_list *keys)
{
	int	specifier_index;

	specifier_index = is_specifier(str[*i], str[*i + 1]);
	if (str[*i + 1] != 0 && specifier_index > 0)
	{
		*i += 2;
		print_argument(keys, specifier_index, writecount);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		keys;
	int			i;
	int			argcount;
	int			writecount;

	argcount = 0;
	writecount = 0;
	va_start(keys, str);
	i = 0;
	while (str[i] != 0)
	{
		if (writecount == -1 || argcount > count_args(str))
			return (-1);
		if (handle_percent(str, &i, &writecount) == 1)
			continue ;
		else if (handle_specifier(str, &i, &writecount, &keys) == 1)
		{
			argcount++;
			continue ;
		}
		if (str[i] != 0)
			put_char(str[i++], &writecount);
	}
	va_end(keys);
	return (writecount);
}

// int	main(void)
// {
// 	printf("\n%d", ft_printf("%x", LONG_MAX));
// 	printf("\n-------------\n");
// 	printf("\n%d", printf("%x", LONG_MAX));
// }
