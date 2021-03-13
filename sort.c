/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:01:49 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/07 22:01:51 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_sort_help(float *s_arr, int *left, int *right)
{
	float tmp;

	if (*left <= *right)
	{
		tmp = s_arr[*left];
		s_arr[*left] = s_arr[*right];
		s_arr[*right] = tmp;
		(*left)++;
		(*right)--;
	}
}

void		ft_qsortf(float *s_arr, int first, int last)
{
	int		left;
	int		right;
	float	middle;

	if (first < last)
	{
		left = first;
		right = last;
		middle = s_arr[(left + right) / 2];
		while (left <= right)
		{
			while (s_arr[left] < middle)
				left++;
			while (s_arr[right] > middle)
				right--;
			ft_sort_help(s_arr, &left, &right);
		}
		ft_qsortf(s_arr, first, right);
		ft_qsortf(s_arr, left, last);
	}
}

static void	ft_sort_help_spr(t_spr *s_arr, int *left, int *right)
{
	t_spr tmp;

	if (*left <= *right)
	{
		tmp.x = s_arr[*left].x;
		tmp.y = s_arr[*left].y;
		tmp.s_dist = s_arr[*left].s_dist;
		s_arr[*left].x = s_arr[*right].x;
		s_arr[*left].y = s_arr[*right].y;
		s_arr[*left].s_dist = s_arr[*right].s_dist;
		s_arr[*right].x = tmp.x;
		s_arr[*right].y = tmp.y;
		s_arr[*right].s_dist = tmp.s_dist;
		(*left)++;
		(*right)--;
	}
}

void		ft_qsortspr(t_spr *s_arr, int first, int last)
{
	int		left;
	int		right;
	float	middle;

	if (first < last)
	{
		left = first;
		right = last;
		middle = s_arr[(left + right) / 2].s_dist;
		while (left <= right)
		{
			while (s_arr[left].s_dist < middle)
				left++;
			while (s_arr[right].s_dist > middle)
				right--;
			ft_sort_help_spr(s_arr, &left, &right);
		}
		ft_qsortspr(s_arr, first, right);
		ft_qsortspr(s_arr, left, last);
	}
}
