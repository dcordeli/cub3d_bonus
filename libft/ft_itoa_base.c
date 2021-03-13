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

static int			ft_rank(unsigned long long int n, int x)
{
	int rank;

	rank = 0;
	if (n == 0 || n == 1)
		return (1);
	while (n != 0)
	{
		n = n / x;
		rank++;
	}
	return (rank);
}

static long long	ft_degree(int rank, int x)
{
	long long int	res;

	res = 1;
	while (rank != 1)
	{
		res = res * x;
		rank--;
	}
	return (res);
}

static char			*ft_clone(unsigned long long int n, int i, int x, char *s)
{
	unsigned long long int	nbr;
	char					*res;
	int						rank;

	rank = ft_rank(n, x);
	res = (char *)malloc(rank + 2);
	if (NULL == res)
		return (NULL);
	if (n > 0)
		nbr = n;
	else if (n == 0)
		return ("0");
	while (rank != 0)
	{
		res[i++] = *(s + (nbr / ft_degree(rank, x)));
		nbr = nbr % ft_degree(rank--, x);
	}
	res[i] = 0;
	return (res);
}

char				*ft_itoa_base(unsigned long long int n, char c)
{
	char	*res;
	int		i;
	char	*s;

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
	if (!(s = (char *)malloc(sizeof(char) * 40)))
		return (NULL);
	if (c == 'x' || c == 'X' || c == 'p')
		s = (c == 'x' || c == 'p') ? "0123456789abcdef" : "0123456789ABCDEF";
	else if (c == 'o')
		s = "01234567";
	else
		s = "0123456789";
	res = ft_clone(n, i, (int)ft_strlen(s), s);
	return (res);
}
