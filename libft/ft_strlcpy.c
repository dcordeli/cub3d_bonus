/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:41:34 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/06 18:22:10 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t l;

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	l = 0;
	if (src == NULL)
		return (0);
	while (src[i] != 0)
	{
		if (i < size - 1 && size != 0)
		{
			dst[i] = src[i];
			l++;
		}
		i++;
	}
	if (size != 0)
		dst[l] = 0;
	return (i);
}
