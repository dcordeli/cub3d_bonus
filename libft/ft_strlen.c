/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:13:23 by dcordeli          #+#    #+#             */
/*   Updated: 2020/10/29 20:25:35 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t l;

	if (s == NULL)
		return (0);
	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

size_t	ft_strlen_l(const wchar_t *s)
{
	size_t l;

	if (s == NULL)
		return (0);
	l = 0;
	while (s[l] != L'\0')
		l++;
	return (l);
}

size_t	ft_strlen_c(const char *s, char c)
{
	int		i;
	size_t	l;

	l = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i++] != '\0')
		l++;
	return (l);
}
