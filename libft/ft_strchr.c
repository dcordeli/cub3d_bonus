/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:50:03 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/06 18:07:52 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*u;
	size_t		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	u = s;
	while (s[i] != 0 && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
	{
		u = u + i;
		return ((char *)u);
	}
	else
		return (NULL);
}
