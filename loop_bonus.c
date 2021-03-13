/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:01:28 by dcordeli          #+#    #+#             */
/*   Updated: 2021/03/04 12:54:47 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		ft_close(t_all *all)
{
	int		i;

	mlx_destroy_image(all->win->mlx, all->win->img);
	mlx_destroy_window(all->win->mlx, all->win->win);
	free(all->win);
	free(all->plr->zbuf);
	free(all->plr);
	ft_free_split(all->map);
	i = -1;
	while (++i < SPR)
	{
		free(all->s[i]);
		free(all->s_tex[i].path);
		free(all->s_tex[i].img);
		if (i < TEX)
		{
			free(all->t[i].path);
			free(all->t[i].img);
		}
	}
	free(all->t);
	free(all->s);
	free(all);
	system("killall afplay");
	exit(0);
}

void	draw_game_over(t_all *all, char *path)
{
	t_point p;
	t_point	k;
	t_tex	g;
	int		color;

	g.img = mlx_xpm_file_to_image(all->win->mlx, path, &g.w, &g.h);
	g.addr = mlx_get_data_addr(g.img, &g.bpp, &g.line_l, &g.en);
	p.y = (all->win->height > g.h) ? (int)(all->win->height / 2 - g.h / 2) : 0;
	k.y = -1;
	while (++k.y < g.h && p.y < all->win->height)
	{
		p.x = (all->win->width > g.w) ? (all->win->width / 2 - g.w / 2) : 0;
		k.x = -1;
		while (++k.x < g.w && p.x < all->win->width)
		{
			color = my_tex_pixel_put(&g, &k);
			if ((color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(all->win, &p, color);
			p.x++;
		}
		p.y++;
	}
	mlx_destroy_image(all->win->mlx, g.img);
}

int		loop_key(t_all *all)
{
	mlx_destroy_image(all->win->mlx, all->win->img);
	all->win->img = mlx_new_image(all->win->mlx, all->win->width,
		all->win->height);
	all->win->addr = mlx_get_data_addr(all->win->img, &(all->win->bpp),
		&all->win->line_l, &all->win->en);
	key_hook(all);
	draw_scene(all);
	all->i = (all->i > 9) ? 0 : all->i + 1;
	if (all->plr->hp < 1)
		draw_game_over(all, "./textures/game_over2.xpm");
	if (all->plr->wolf >= 50)
		draw_game_over(all, "./textures/the_end.xpm");
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	return (0);
}

int		key_hook(t_all *all)
{
	if (all->plr->hp > 0 && all->plr->wolf < 50)
	{
		if (all->key & K_W)
			key_w(all, 0);
		if (all->key & K_S)
			key_s(all, 0);
		if (all->key & K_D)
			key_d(all);
		if (all->key & K_A)
			key_a(all);
		if (all->key & K_R)
			keyrot(all, ROT_SPEED);
		if (all->key & K_L)
			keyrot(all, -ROT_SPEED);
		if (all->key & K_UP && all->win->up < 0.7)
			all->win->up += 0.05;
		if (all->key & K_DOW && all->win->up > -0.7)
			all->win->up -= 0.05;
	}
	return (0);
}
