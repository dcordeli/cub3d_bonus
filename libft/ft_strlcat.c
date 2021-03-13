/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:12:36 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/08 20:52:40 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l;

	if (dst == NULL || src == NULL)
		return (0);
	j = 0;
	l = ft_strlen(dst);
	i = l;
	if (size != 0 && size > l)
	{
		while (i < size - 1 && src[j] != 0)
		{
			dst[i] = src[j++];
			i++;
		}
		dst[i] = 0;
	}
	if (l < size)
		i = l + ft_strlen(src);
	else
		i = ft_strlen(src) + size;
	return (i);
}
