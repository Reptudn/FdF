/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:22:40 by jonask            #+#    #+#             */
/*   Updated: 2023/10/13 13:27:09 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = lst[0];
	if (lst == 0 || new == 0)
		return ;
	if (lst[0] == 0)
	{
		lst[0] = new;
		return ;
	}
	else
	{
		while (last->next != 0)
			last = last->next;
		last->next = new;
	}
}
