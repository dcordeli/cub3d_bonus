/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:08:09 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/04 17:22:37 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		cc;
	size_t				i;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	cc = (unsigned char)c;
	if (n == 0 || dest == NULL || src == NULL)
		return (NULL);
	while (i < n && s[i] != cc && n != 0)
	{
		d[i] = s[i];
		i++;
	}
	if (i == n)
		return (NULL);
	d[i] = cc;
	d = d + i + 1;
	return ((void *)d);
}
