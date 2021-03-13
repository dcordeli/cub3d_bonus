/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:41:22 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/04 17:31:20 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int					res;
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	i = 0;
	res = 0;
	if (n == 0 || str1 == NULL || str2 == NULL)
		return (0);
	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (s1[i] == s2[i] && i < n - 1)
		i++;
	res = s1[i] - s2[i];
	return (res);
}
