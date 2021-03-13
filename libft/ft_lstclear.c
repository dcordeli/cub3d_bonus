/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:55:21 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/06 18:31:54 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *pre;
	t_list *list;

	pre = *lst;
	list = *lst;
	while (list != NULL)
	{
		del(pre->content);
		list = list->next;
		pre->next = NULL;
		free(pre);
		pre = list;
	}
	*lst = NULL;
}
