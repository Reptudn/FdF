/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:42:38 by jonask            #+#    #+#             */
/*   Updated: 2023/10/17 09:47:32 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_item;
	t_list	*pog;
	t_list	*i;
	void	*f_ed_content;

	pog = 0;
	i = lst;
	if (!lst || !f || !del)
		return (0);
	while (i != 0)
	{
		f_ed_content = f(i->content);
		new_item = ft_lstnew(f_ed_content);
		if (new_item == 0)
		{
			ft_lstdelone(new_item, del);
			del(f_ed_content);
			ft_lstclear(&lst, del);
			return (0);
		}
		ft_lstadd_back(&pog, new_item);
		i = i->next;
	}
	ft_lstadd_back(&pog, 0);
	return (pog);
}
