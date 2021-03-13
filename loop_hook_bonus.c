/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:37:51 by dcordeli          #+#    #+#             */
/*   Updated: 2021/03/09 00:37:56 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		keyup_hook(int keycode, t_all *all)
{
	if (keycode == W)
		all->key -= K_W;
	if (keycode == S)
		all->key -= K_S;
	if (keycode == D)
		all->key -= K_D;
	if (keycode == A)
		all->key -= K_A;
	if (keycode == RIGHT)
		all->key -= K_R;
	if (keycode == LEFT)
		all->key -= K_L;
	if (keycode == UP)
		all->key -= K_UP;
	if (keycode == DOWN)
		all->key -= K_DOW;
	return (0);
}

int		keydown_hook(int keycode, t_all *all)
{
	if (keycode == ESC)
		ft_close(all);
	if (all->plr->hp > 0 && all->plr->wolf < 50)
	{
		if (keycode == W)
			all->key |= K_W;
		if (keycode == S)
			all->key |= K_S;
		if (keycode == D)
			all->key |= K_D;
		if (keycode == A)
			all->key |= K_A;
		if (keycode == RIGHT)
			all->key |= K_R;
		if (keycode == LEFT)
			all->key |= K_L;
		if (keycode == UP && all->win->up < 0.7)
			all->key |= K_UP;
		if (keycode == DOWN && all->win->up > -0.7)
			all->key |= K_DOW;
	}
	return (0);
}

void	put_bar(t_all *all)
{
	int		i;
	t_point p;
	int		size;
	int		x;

	i = ((all->win->height * all->win->width / 200000) > 2) ?
	(int)(all->win->height * all->win->width / 200000) : 2;
	size = put_map(all->map, all->win, i);
	x = ft_strlen(all->map[0]) * i;
	put_life(all, size, x, -1);
	p.x = (int)((all->plr->pos_x - 0.5) * i);
	p.y = (int)((all->plr->pos_y - 0.5) * i);
	mlx_o(all->win, &p, 0x0000FF, i);
	if (all->plr->wolf > 0)
		put_barws(all, size, x, 6);
	if (all->plr->svitok > 0)
		put_barws(all, size, x, 3);
}
