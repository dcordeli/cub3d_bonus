/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:27:53 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/01 14:33:39 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;
	size_t			i;
	size_t			n;

	i = 0;
	n = nmemb * size / sizeof(unsigned char);
	res = (unsigned char *)malloc(nmemb * size);
	if (NULL == res)
		return (NULL);
	while (i < n)
	{
		res[i] = (unsigned char)0;
		i++;
	}
	return (res);
}
