/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:01:28 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/07 22:01:30 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(t_all *all)
{
	int		i;

	i = -1;
	mlx_destroy_image(all->win->mlx, all->win->img);
	mlx_destroy_window(all->win->mlx, all->win->win);
	free(all->win);
	free(all->plr->zbuf);
	free(all->plr);
	while (all->map[++i] != NULL)
		free(all->map[i]);
	free(all->map);
	i = -1;
	while (++i < TEX)
	{
		free(all->t[i].path);
		free(all->t[i].img);
	}
	free(all->t);
	free(all->s_tex.path);
	free(all->s_tex.img);
	free(all->s);
	free(all);
	exit(0);
}

int		loop_key(t_all *all)
{
	mlx_destroy_image(all->win->mlx, all->win->img);
	all->win->img = mlx_new_image(all->win->mlx, all->win->width,
		all->win->height);
	all->win->addr = mlx_get_data_addr(all->win->img, &(all->win->bpp),
		&all->win->line_l, &all->win->en);
	draw_scene(all);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_all *all)
{
	if (keycode == W)
		key_w(all);
	if (keycode == S)
		key_s(all);
	if (keycode == D)
		key_d(all);
	if (keycode == A)
		key_a(all);
	if (keycode == ESC)
		ft_close(all);
	if (keycode == RIGHT)
		keyrot(all, ROT_SPEED);
	if (keycode == LEFT)
		keyrot(all, -ROT_SPEED);
	loop_key(all);
	return (0);
}
