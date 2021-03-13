/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:01:12 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/04 20:47:51 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		l;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	l = ft_strlen(s1) - 1;
	while (s1[i] != 0 && ft_check(set, s1[i]) == 1)
		i++;
	while (l >= 0 && ft_check(set, s1[l]) == 1)
		l--;
	if (i < l)
		res = ft_substr(s1, i, l - i + 1);
	else
		res = ft_strdup("");
	return (res);
}
