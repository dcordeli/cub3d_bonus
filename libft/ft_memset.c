/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:55:33 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/01 11:00:51 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*k;
	unsigned char	j;

	i = 0;
	j = (unsigned char)c;
	k = (unsigned char *)s;
	if (s == NULL)
		return (s);
	while (i < n)
	{
		k[i] = j;
		i++;
	}
	return (s);
}
