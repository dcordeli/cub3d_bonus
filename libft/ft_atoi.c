/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:02:37 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/04 20:04:09 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	int			n;
	int			p;

	i = 0;
	n = 0;
	p = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32 || nptr[i] == 48)
		i++;
	if (nptr[i] == '-')
	{
		p = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		n = n + nptr[i] - 48;
		i++;
		if (nptr[i] > 47 && nptr[i] < 58)
			n = n * 10;
	}
	n = n * p;
	return (n);
}
