/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:15:10 by jgotz             #+#    #+#             */
/*   Updated: 2023/11/10 16:07:01 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_strchr2(const char *str, int c);

void	ft_bzero2(void *s, size_t n);
void	*ft_calloc2(size_t count, size_t size);

size_t	ft_strlen2(const char *str);

#endif
