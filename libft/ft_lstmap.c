/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:45:09 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/06 18:39:07 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *list;
	t_list *begin;

	if (lst == NULL)
		return (NULL);
	list = ft_lstnew(f(lst->content));
	if (NULL == list)
		return (NULL);
	else
		begin = list;
	while (lst->next != NULL)
	{
		lst = lst->next;
		list = ft_lstnew(f(lst->content));
		if (NULL == list)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, list);
	}
	return (begin);
}
