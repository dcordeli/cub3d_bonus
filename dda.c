/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:02:27 by dcordeli          #+#    #+#             */
/*   Updated: 2021/03/04 12:47:29 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		dda_s_dist(t_dda *d)
{
	if (d->ray_dir_x < 0)
	{
		d->step_x = -1;
		d->s_dist_x = (d->pos_x - d->map_x) * d->d_dist_x;
	}
	else
	{
		d->step_x = 1;
		d->s_dist_x = (d->map_x + 1.0 - d->pos_x) * d->d_dist_x;
	}
	if (d->ray_dir_y < 0)
	{
		d->step_y = -1;
		d->s_dist_y = (d->pos_y - d->map_y) * d->d_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->s_dist_y = (d->map_y + 1.0 - d->pos_y) * d->d_dist_y;
	}
}

static void		dda_init(t_all *all, t_dda *d)
{
	d->pos_x = all->plr->pos_x;
	d->pos_y = all->plr->pos_y;
	d->ray_dir_x = all->plr->dir_x + all->plr->plane_x * all->plr->camerax;
	d->ray_dir_y = all->plr->dir_y + all->plr->plane_y * all->plr->camerax;
	d->map_x = (int)d->pos_x;
	d->map_y = (int)d->pos_y;
	d->d_dist_y = fabs(1 / d->ray_dir_y);
	d->d_dist_x = fabs(1 / d->ray_dir_x);
	d->hit = 0;
	dda_s_dist(d);
}

static void		dda_tex_help(t_all *all, t_dda *d)
{
	int	i;

	i = -1;
	all->plr->map_x = d->map_x;
	all->plr->map_y = d->map_y;
	if (all->plr->side == 0)
		all->plr->wall_x = d->pos_y + all->plr->dist * d->ray_dir_y;
	else
		all->plr->wall_x = d->pos_x + all->plr->dist * d->ray_dir_x;
	all->plr->wall_x -= floor((all->plr->wall_x));
	while (++i < TEX)
	{
		all->plr->tex_x[i] = (int)(all->plr->wall_x * (double)(all->t[i].w));
		if ((all->plr->side == 0 && d->ray_dir_x > 0)
			|| (all->plr->side == 1 && d->ray_dir_y < 0))
			all->plr->tex_x[i] = all->t[i].w - all->plr->tex_x[i] - 1;
	}
}

void			dda(t_all *all)
{
	t_dda	d;

	dda_init(all, &d);
	while (d.hit == 0)
	{
		if (d.s_dist_x < d.s_dist_y)
		{
			d.s_dist_x += d.d_dist_x;
			d.map_x += d.step_x;
			all->plr->side = 0;
		}
		else
		{
			d.s_dist_y += d.d_dist_y;
			d.map_y += d.step_y;
			all->plr->side = 1;
		}
		if (all->map[d.map_y][d.map_x] == '1')
			d.hit = 1;
	}
	if (all->plr->side == 0)
		all->plr->dist = (d.map_x - d.pos_x + (1 - d.step_x) / 2) / d.ray_dir_x;
	else
		all->plr->dist = (d.map_y - d.pos_y + (1 - d.step_y) / 2) / d.ray_dir_y;
	dda_tex_help(all, &d);
}
