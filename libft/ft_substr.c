/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:15:40 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/04 20:45:37 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	if (s == 0)
		return (NULL);
	if (start < ft_strlen(s))
		i = start;
	else
		i = ft_strlen(s);
	j = 0;
	res = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (NULL == res)
		return (NULL);
	while (s[i] != 0 && j < len)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = 0;
	return (res);
}
