/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:16:23 by dcordeli          #+#    #+#             */
/*   Updated: 2020/11/04 14:35:01 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rank(int n)
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

static int	ft_degree(int rank)
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

void		ft_putnbr_fd(int n, int fd)
{
	char		c;
	long int	nbr;
	int			rank;
	int			i;

	i = 0;
	rank = ft_rank(n);
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n > 0)
		nbr = n;
	else
	{
		nbr = (long int)n * (-1);
		ft_putchar_fd('-', fd);
		i = 1;
	}
	while (rank != 0 && n != 0)
	{
		c = nbr / ft_degree(rank) + 48;
		nbr = nbr % ft_degree(rank--);
		ft_putchar_fd(c, fd);
	}
}
