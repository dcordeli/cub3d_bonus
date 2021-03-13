/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:12:53 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/04 19:14:08 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		c;

	i = 0;
	if (n == 0 || s1 == NULL || s2 == NULL)
		return (0);
	while (i < n - 1 && s1[i] != 0 && s1[i] == s2[i])
		i++;
	if (ft_isascii((int)s1[i]) == 0 || ft_isascii((int)s2[i]) == 0)
		return (1);
	c = s1[i] - s2[i];
	return (c);
}
