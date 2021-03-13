/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:35:39 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/08 21:09:30 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	if (h == NULL || n == NULL || len == 0)
		return (NULL);
	if (n[0] == 0)
		return ((char *)h);
	i = 0;
	while (h[i] != 0 && i < len)
	{
		while (h[i] != 0 && i < len && h[i] != n[0])
			i++;
		if (h[i] == 0 || i == len)
			return (NULL);
		j = 0;
		while (h[i] != 0 && i < len && h[i] == n[j] && n[j] != 0)
		{
			i++;
			j++;
		}
		if (n[j] == 0)
			return ((char *)(h + i - j));
		i = i - j + 1;
	}
	return (NULL);
}
