/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:01:56 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/07 22:01:58 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				col_rainbow(int color, int step)
{
	int r;
	int g;
	int b;

	r = (color >> 16) & 255;
	g = (color >> 8) & 255;
	b = (color) & 255;
	if (b == 0 && r == 255 && g <= 255 - step)
		g += step;
	else if (g >= 255 - step && r >= step && b == 0)
		r -= step;
	else if (r <= step && g >= 255 - step && b <= 255 - step)
		b += step;
	else if (r <= step && b >= 255 - step && g >= step)
		g -= step;
	else if (b >= 255 - step && g <= step && r <= 255 - step)
		r += step;
	else
	{
		r = 255;
		g = 0;
		b = 0;
	}
	return (trgb(0, r, g, b));
}

static void		spr_help(t_all *all, t_spr_help *s)
{
	s->spr_x = all->s[s->i].x - all->plr->pos_x;
	s->spr_y = all->s[s->i].y - all->plr->pos_y;
	s->inv_d = 1.0 / (all->plr->plane_x * all->plr->dir_y -
			all->plr->dir_x * all->plr->plane_y);
	s->trf_x = s->inv_d * (all->plr->dir_y * s->spr_x - all->plr->dir_x *
			s->spr_y);
	s->trf_y = s->inv_d * (all->plr->plane_x * s->spr_y - all->plr->plane_y *
			s->spr_x);
	s->s_scr_x = (int)((all->win->width / 2) * (1 + s->trf_x / s->trf_y));
	s->vm_scr = (int)(VMOVE / s->trf_y);
	s->spr_h = abs((int)(all->win->height / (s->trf_y) * all->win->k)) / VDIV;
	s->draw_s_y = all->win->height / 2 - s->spr_h / 2 + s->vm_scr;
	if (s->draw_s_y < 0)
		s->draw_s_y = 0;
	s->draw_e_y = s->spr_h / 2 + all->win->height / 2 + s->vm_scr;
	if (s->draw_e_y > all->win->height)
		s->draw_e_y = all->win->height;
	s->spr_w = abs((int)(all->win->height / (s->trf_y) * all->win->k)) / UDIV;
	s->draw_s_x = s->s_scr_x - s->spr_w / 2;
	if (s->draw_s_x < 0)
		s->draw_s_x = 0;
	s->draw_e_x = s->spr_w / 2 + s->s_scr_x;
	if (s->draw_e_x > all->win->width)
		s->draw_e_x = all->win->width;
	s->stripe = s->draw_s_x - 1;
}

static void		spr_help_2(t_all *all, t_spr_help *s)
{
	s->s_tex_x = (int)(256 * (s->stripe - (-s->spr_w / 2 + s->s_scr_x)) *
					all->s_tex.w / s->spr_w) / 256;
	s->y = s->draw_s_y - 1;
	if (s->trf_y > 0 && s->stripe >= 0 && s->stripe < all->win->width &&
		s->trf_y < all->plr->zbuf[s->stripe])
		while (++s->y < s->draw_e_y)
		{
			s->d = (s->y - s->vm_scr) * 256 - all->win->height * 128 +
					s->spr_h * 128;
			s->s_tex_y = ((s->d * all->s_tex.h) / s->spr_h) / 256;
			s->k.x = s->s_tex_x;
			s->k.y = s->s_tex_y;
			s->color = my_tex_pixel_put(&all->s_tex, &s->k);
			s->k.x = s->stripe;
			s->k.y = s->y;
			if ((s->color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(all->win, &s->k, s->color);
		}
}

void			draw_sprites(t_all *all)
{
	t_spr_help s;

	s.i = -1;
	while (++s.i < all->win->s_num)
		all->s[s.i].s_dist = (pow((all->plr->pos_x - all->s[s.i].x), 2) +
			pow((all->plr->pos_y - all->s[s.i].y), 2));
	s.i = all->win->s_num;
	ft_qsortspr(all->s, 0, all->win->s_num - 1);
	while (--s.i >= 0)
	{
		spr_help(all, &s);
		while (++s.stripe < s.draw_e_x)
			spr_help_2(all, &s);
	}
}
