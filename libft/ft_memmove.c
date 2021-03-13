/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:08:45 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/02 16:50:24 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					i;

	i = n;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (dest == NULL || src == NULL)
		return (dest);
	if (d > s && d < s + n)
	{
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	else
		d = (unsigned char *)ft_memcpy(dest, src, n);
	return (dest);
}
