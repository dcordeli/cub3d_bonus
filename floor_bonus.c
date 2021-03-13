/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:57:13 by dcordeli          #+#    #+#             */
/*   Updated: 2021/03/07 22:05:14 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_floor_help(t_all *all, t_floor *f, t_point *p)
{
	f->rdx_s = all->plr->dir_x - all->plr->plane_x;
	f->rdy_s = all->plr->dir_y - all->plr->plane_y;
	f->rdx_e = all->plr->dir_x + all->plr->plane_x;
	f->rdy_e = all->plr->dir_y + all->plr->plane_y;
	f->p = p->y - all->win->height / 2 + all->win->up;
	f->pos_z = 0.5 * all->win->height + all->win->up;
	f->row_dist = f->pos_z / f->p;
	f->fstep_x = f->row_dist * (f->rdx_e - f->rdx_s) / all->win->width;
	f->fstep_y = f->row_dist * (f->rdy_e - f->rdy_s) / all->win->width;
	f->f_x = all->plr->pos_x + f->row_dist * f->rdx_s;
	f->f_y = all->plr->pos_y + f->row_dist * f->rdy_s;
	f->row_dist = f->row_dist * (1 + all->win->up);
	p->x = -1;
}

void		draw_floor(t_all *all)
{
	t_floor		f;
	t_point		p;
	t_point		k;

	p.y = all->win->height / 2 + all->win->up;
	while (++p.y < all->win->height)
	{
		draw_floor_help(all, &f, &p);
		while (++p.x < all->win->width)
		{
			f.c_x = (int)f.f_x;
			f.c_y = (int)f.f_y;
			k.x = (int)(all->flo.w * (f.f_x - f.c_x)) & (all->flo.w - 1);
			k.y = (int)(all->flo.h * (f.f_y - f.c_y)) & (all->flo.h - 1);
			f.f_x += f.fstep_x;
			f.f_y += f.fstep_y;
			f.color = my_tex_pixel_put(&all->flo, &k);
			my_mlx_pixel_put(all->win, &p, col_shadow(f.color, f.row_dist));
		}
	}
}

void		put_text(t_all *all, char *path, int i)
{
	t_point p;
	t_point	k;
	int		color;
	t_tex	t;

	k.y = 0;
	t.img = mlx_xpm_file_to_image(all->win->mlx, path, &t.w, &t.h);
	t.addr = mlx_get_data_addr(t.img, &t.bpp, &t.line_l, &t.en);
	i = (ceil(t.w / all->win->height) > ceil(t.w / all->win->width)) ?
		ceil(t.w / all->win->width) + 1 : ceil(t.w / all->win->height) + 1;
	p.y = (all->win->height > (t.h / i)) ? all->win->height - (t.h / i) : 0;
	while (k.y < t.h && p.y < all->win->height && ((p.x = -1) < 0))
	{
		k.x = 0;
		while (k.x < t.w && ++p.x < all->win->width)
		{
			color = my_tex_pixel_put(&t, &k);
			if ((color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(all->win, &p, color);
			k.x += i;
		}
		k.y += i;
		p.y++;
	}
	mlx_destroy_image(all->win->mlx, t.img);
}

void		draw_text(t_all *all)
{
	if (all->plr->ziri == 0 && all->s[0][0].s_dist < 1.5)
		put_text(all, "./textures/g0.xpm", 0);
	if (all->plr->ziri == 0 && all->s[1][0].s_dist < 1.5)
		put_text(all, "./textures/y1.xpm", 0);
	if (all->s[2][0].s_dist < 1.1 && all->plr->ziri < 50 &&
		all->plr->ziri++ > 0)
		put_text(all, "./textures/z1.xpm", 0);
	if (all->s[2][0].s_dist < 2 && all->plr->ziri > 49)
	{
		all->s[2][0].x = all->plr->pos_x + 0.5;
		all->s[2][0].y = all->plr->pos_y + 0.5;
	}
	if (all->s[1][0].s_dist < 2 && all->plr->ziri > 49)
	{
		all->s[1][0].x = all->plr->pos_x + 0.5;
		all->s[1][0].y = all->plr->pos_y - 0.5;
		all->plr->svitok = 50;
		all->map[2][30] = '0';
	}
	if (all->plr->ziri > 49 && all->s[0][0].s_dist < 1.5
		&& all->plr->svitok > 49 && all->plr->wolf < 50)
	{
		put_text(all, "./textures/g2.xpm", 0);
		all->plr->wolf++;
	}
}

void		put_barws(t_all *all, int size, int x, int i)
{
	t_point p;
	t_point	k;
	int		color;
	int		j;

	p.y = 0;
	k.y = 0;
	j = (i == 6) ? 0 : 1;
	while (k.y < all->s_tex[i].h && p.y < all->win->height)
	{
		p.x = (all->plr->hp + j) * size + x + size / 4;
		k.x = 0;
		while (k.x < all->s_tex[i].w && p.x < all->win->width)
		{
			color = my_tex_pixel_put(&all->s_tex[i], &k);
			if ((color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(all->win, &p, color);
			k.x += floor(1.1 * (all->s_tex[i].w) / size);
			p.x++;
		}
		k.y += floor(1.1 * (all->s_tex[i].h) / size);
		p.y++;
	}
}
