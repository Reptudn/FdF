/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 06:31:56 by jonask            #+#    #+#             */
/*   Updated: 2023/10/09 06:40:28 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*pog;

	pog = malloc(sizeof(t_list));
	if (!pog)
		return (0);
	pog->content = content;
	pog->next = NULL;
	return (pog);
}
