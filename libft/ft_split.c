/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:31:06 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/09 15:11:43 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_alloc(char const *s, char c, int i, int l)
{
	char	**res;
	char	*dest;
	char	set[2];

	set[0] = c;
	set[1] = 0;
	dest = ft_strtrim(s, set);
	if (dest == NULL)
		return (NULL);
	while (dest[i] != 0)
	{
		while (dest[i] != 0 && dest[i] != c)
			i++;
		if (dest[i] == c)
			l++;
		while (dest[i] == c)
			i++;
	}
	res = (char **)malloc((l + 2) * sizeof(char *));
	if (NULL == res)
		return (NULL);
	free(dest);
	return (res);
}

static int	ft_sublen(char const *s, char c, int i)
{
	int	res;

	res = 0;
	while (s[i] != 0 && s[i] != c)
	{
		res++;
		i++;
	}
	return (res);
}

static char	**ft_clone(char const *s, char c, int i, int k)
{
	char	**res;

	res = ft_alloc(s, c, 0, 0);
	if (NULL == res)
		return (NULL);
	while (s[i] != 0)
	{
		while (s[i] != 0 && s[i] == c)
			i++;
		if (s[i] != 0)
		{
			res[k] = ft_substr(s, i, ft_sublen(s, c, i));
			if (res[k] == NULL)
			{
				while (k > 0)
					free(res[--k]);
				free(res);
				return (NULL);
			}
			k++;
		}
		i = i + ft_sublen(s, c, i);
	}
	res[k] = NULL;
	return (res);
}

char		**ft_split(char const *s, char c)
{
	char **res;

	if (s == NULL)
		return (NULL);
	if (c == '\0')
	{
		if (s[0] == 0)
		{
			res = (char **)malloc(1 * sizeof(char *));
			if (NULL == res)
				return (NULL);
			res[0] = NULL;
			return (res);
		}
		res = (char **)malloc(2 * sizeof(char *));
		if (NULL == res)
			return (NULL);
		res[0] = ft_substr(s, 0, ft_sublen(s, c, 0));
		if (res[0] == NULL)
			return (NULL);
		res[1] = NULL;
		return (res);
	}
	res = ft_clone(s, c, 0, 0);
	return (res);
}
