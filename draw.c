/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:02:36 by dcordeli          #+#    #+#             */
/*   Updated: 2021/03/04 12:46:02 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			tex_draw_help(t_all *all, t_point *k, int i)
{
	int	color;

	k->x = all->plr->tex_x[i];
	k->y = (int)all->plr->tex_pos[i] & (all->t[i].h - 1);
	all->plr->tex_pos[i] += all->plr->step[i];
	color = my_tex_pixel_put(&all->t[i], k);
	return (color);
}

int			draw_tex(t_all *all, t_point *k)
{
	int	color;

	if (all->plr->side == 0 && (float)all->plr->map_x > all->plr->pos_x)
		color = tex_draw_help(all, k, 2);
	if (all->plr->side == 1 && (float)all->plr->map_y > all->plr->pos_y)
		color = tex_draw_help(all, k, 0);
	if (all->plr->side == 0 && (float)all->plr->map_x <= all->plr->pos_x)
		color = tex_draw_help(all, k, 3);
	if (all->plr->side == 1 && (float)all->plr->map_y <= all->plr->pos_y)
		color = tex_draw_help(all, k, 1);
	return (color);
}

static void	draw_line(t_all *all, t_dda *d, int x)
{
	t_point	p;
	t_point	k;

	p.x = x;
	p.y = 0;
	while (p.y < all->win->height)
	{
		if (p.y < d->draw_start)
			my_mlx_pixel_put(all->win, &p, all->win->color_ceil);
		else if (p.y > d->draw_end)
			my_mlx_pixel_put(all->win, &p, all->win->color_floor);
		else
			my_mlx_pixel_put(all->win, &p, draw_tex(all, &k));
		p.y++;
	}
}

void		tex_help(t_all *all, t_dda *d)
{
	int	i;

	i = -1;
	while (++i < TEX)
	{
		all->plr->step[i] = 1.0 * all->t[i].h / d->line_h;
		all->plr->tex_pos[i] = (d->draw_start - all->win->height / 2.0
				+ d->line_h / 2.0) * all->plr->step[i];
	}
}

void		draw_scene(t_all *all)
{
	int		x;
	t_dda	d;

	x = -1;
	while (++x < all->win->width)
	{
		all->plr->camerax = 2 * x / (double)all->win->width - 1;
		dda(all);
		all->plr->zbuf[x] = all->plr->dist;
		d.line_h = (int)(all->win->height / all->plr->dist * all->win->k);
		d.draw_start = (int)(all->win->height / 2 - d.line_h / 2);
		if (d.draw_start < 0)
			d.draw_start = 0;
		d.draw_end = (int)(d.line_h / 2 + all->win->height / 2);
		if (d.draw_end >= all->win->height)
			d.draw_end = all->win->height - 1;
		tex_help(all, &d);
		draw_line(all, &d, x);
	}
	draw_sprites(all);
}
