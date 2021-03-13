/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:59:37 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/06 18:23:03 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

t_list		*ft_lstdelnote(t_list *begin, t_list *tmp, void (*del)(void *))
{
	t_list *pre;

	pre = begin;
	if (begin == tmp)
		begin = begin->next;
	else
	{
		while (pre->next != tmp)
			pre = pre->next;
		pre->next = tmp->next;
	}
	ft_lstdelone(tmp, del);
	return (begin);
}
