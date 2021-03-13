/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:03:37 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/04 20:50:41 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s, int len)
{
	int		i;
	char	c;

	i = 0;
	if (s == NULL || len < 0)
		return ;
	while (s[i] != '\0' && i < len)
	{
		c = s[i];
		write(1, &c, 1);
		i++;
	}
}

void	ft_putstr_l(wchar_t *s, int len)
{
	int			i;
	wchar_t		c;

	i = 0;
	if (s == NULL || len < 0)
		return ;
	while (s[i] != L'\0' && i < len)
	{
		c = s[i];
		write(1, &c, 1);
		i++;
	}
}
