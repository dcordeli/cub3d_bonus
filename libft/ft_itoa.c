/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:49:13 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/06 21:13:02 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int					ft_rank(long long int n)
{
	int rank;

	rank = 0;
	if (n == 0 || n == 1)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		rank++;
	}
	return (rank);
}

static int					ft_degree(int rank)
{
	int	res;

	res = 1;
	while (rank != 1)
	{
		res = res * 10;
		rank--;
	}
	return (res);
}

static char					*ft_clone(long long int n, int i, int rank)
{
	long int	nbr;
	char		*res;

	res = (char *)malloc(rank + 2);
	if (NULL == res)
		return (NULL);
	if (n > 0)
		nbr = n;
	else if (n == 0)
		return ("0");
	else
	{
		nbr = (long int)n * (-1);
		res[0] = '-';
		i = 1;
	}
	while (rank != 0)
	{
		res[i++] = nbr / ft_degree(rank) + 48;
		nbr = nbr % ft_degree(rank--);
	}
	res[i] = 0;
	return (res);
}

char						*ft_itoa(long long int n)
{
	char	*res;
	int		i;
	int		rank;

	if (n == 0)
	{
		res = (char *)malloc(2 * sizeof(char));
		if (NULL == res)
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	i = 0;
	rank = ft_rank(n);
	res = ft_clone(n, i, rank);
	return (res);
}
