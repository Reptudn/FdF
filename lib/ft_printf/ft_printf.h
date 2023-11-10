/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:17 by jonask            #+#    #+#             */
/*   Updated: 2023/11/10 19:46:16 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include <sys/_types/_va_list.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <sys/types.h>

//helper.c
int			is_specifier(char identifier, char type);
void		print_argument(va_list *to_print, int type, int	*writecount);
int			count_args(const char *str);
long long	reverse_num(unsigned long long num);

//conversion.c
void		put_string(char *str, int *writecount);
void		put_char(char c, int *writecount);
void		put_number(int num, int *writecount);
void		put_long(long num, int *writecount);
void		put_double(double num, int *writecount);
void		put_float(float num, int *writecount);
void		put_pointer(void *ptr, int *writecount);

// libft stuff
char		*ft_itoa1(int n);
char		*ltoa(long n);
char		*ft_strdup1(const char *s);
long		get_digits(long n);
void		put_nb_in_str(long n, long digits, char *str);

//base_system_conversion.c
void		put_base(unsigned long num, int base,
				int capital, int *writecount);

void		put_base_hex(long long num, int base, int capital, int *writecount);

void		put_hex(long long num, int capital, int prefix, int *writecount);

int			ft_printf(const char *str, ...);

#endif