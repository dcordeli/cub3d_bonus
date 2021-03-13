/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:23:49 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/01 13:41:11 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int cc, size_t n)
{
	const unsigned char	*s;
	unsigned char		c;
	size_t				i;

	i = 0;
	if (src == NULL)
		return (NULL);
	c = (unsigned char)cc;
	s = (const unsigned char *)src;
	while (i < n && s[i] != c)
		i++;
	if (i == n)
		return (NULL);
	else if (s[i] == c)
		s = s + i;
	return ((void *)s);
}
