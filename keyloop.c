/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyloop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:01:40 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/07 22:01:42 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keyrot(t_all *all, float rot)
{
	all->plr->tmp = all->plr->dir_x;
	all->plr->dir_x = all->plr->dir_x * cos(rot) - all->plr->dir_y * sin(rot);
	all->plr->dir_y = all->plr->tmp * sin(rot) + all->plr->dir_y * cos(rot);
	all->plr->tmp = all->plr->plane_x;
	all->plr->plane_x = all->plr->plane_x * cos(rot) - all->plr->plane_y *
		sin(rot);
	all->plr->plane_y = all->plr->tmp * sin(rot) + all->plr->plane_y * cos(rot);
}

void	key_w(t_all *all)
{
	if (all->map[(int)(all->plr->pos_y + all->plr->dir_y * MOVE_SPEED)]
		[(int)(all->plr->pos_x)] != '1' &&
		all->map[(int)(all->plr->pos_y + all->plr->dir_y * MOVE_SPEED)]
		[(int)(all->plr->pos_x)] != '2')
		all->plr->pos_y += all->plr->dir_y * MOVE_SPEED;
	if (all->map[(int)(all->plr->pos_y)]
		[(int)(all->plr->pos_x + all->plr->dir_x * MOVE_SPEED)] != '1' &&
		all->map[(int)(all->plr->pos_y)]
		[(int)(all->plr->pos_x + all->plr->dir_x * MOVE_SPEED)] != '2')
		all->plr->pos_x += all->plr->dir_x * MOVE_SPEED;
}

void	key_s(t_all *all)
{
	if (all->map[(int)(all->plr->pos_y - all->plr->dir_y * MOVE_SPEED)]
		[(int)(all->plr->pos_x)] != '1' &&
		all->map[(int)(all->plr->pos_y - all->plr->dir_y * MOVE_SPEED)]
		[(int)(all->plr->pos_x)] != '2')
		all->plr->pos_y -= all->plr->dir_y * MOVE_SPEED;
	if (all->map[(int)(all->plr->pos_y)]
		[(int)(all->plr->pos_x - all->plr->dir_x * MOVE_SPEED)] != '1' &&
		all->map[(int)(all->plr->pos_y)]
		[(int)(all->plr->pos_x - all->plr->dir_x * MOVE_SPEED)] != '2')
		all->plr->pos_x -= all->plr->dir_x * MOVE_SPEED;
}

void	key_a(t_all *all)
{
	if (all->map[(int)(all->plr->pos_y - all->plr->dir_x * MOVE_SPEED)]
		[(int)(all->plr->pos_x)] != '1' &&
		all->map[(int)(all->plr->pos_y - all->plr->dir_x * MOVE_SPEED)]
		[(int)(all->plr->pos_x)] != '2')
		all->plr->pos_y -= all->plr->dir_x * MOVE_SPEED;
	if (all->map[(int)(all->plr->pos_y)]
		[(int)(all->plr->pos_x + all->plr->dir_y * MOVE_SPEED)] != '1' &&
		all->map[(int)(all->plr->pos_y)]
		[(int)(all->plr->pos_x + all->plr->dir_y * MOVE_SPEED)] != '2')
		all->plr->pos_x += all->plr->dir_y * MOVE_SPEED;
}

void	key_d(t_all *all)
{
	if (all->map[(int)(all->plr->pos_y + all->plr->dir_x * MOVE_SPEED)]
		[(int)(all->plr->pos_x)] != '1' &&
		all->map[(int)(all->plr->pos_y + all->plr->dir_x * MOVE_SPEED)]
		[(int)(all->plr->pos_x)] != '2')
		all->plr->pos_y += all->plr->dir_x * MOVE_SPEED;
	if (all->map[(int)(all->plr->pos_y)]
		[(int)(all->plr->pos_x - all->plr->dir_y * MOVE_SPEED)] != '1' &&
		all->map[(int)(all->plr->pos_y)]
		[(int)(all->plr->pos_x - all->plr->dir_y * MOVE_SPEED)] != '2')
		all->plr->pos_x -= all->plr->dir_y * MOVE_SPEED;
}
