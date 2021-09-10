/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elman <elman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:16:31 by elmas             #+#    #+#             */
/*   Updated: 2021/07/15 17:57:23 by elman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*new_el;

	if (!lst)
		return (NULL);
	begin = ft_lstnew(f(lst -> content));
	if (begin == NULL)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new_el = begin;
	lst = lst -> next;
	while (lst)
	{
		new_el -> next = ft_lstnew(f(lst -> content));
		if (new_el -> next == NULL)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		new_el = new_el -> next;
		lst = lst -> next;
	}	
	return (begin);
}
