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

#include "cub3d_bonus.h"

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

int				col_shadow(int color, float dist)
{
	int r;
	int g;
	int b;
	int shift;

	shift = (int)(dist - 2);
	if (shift <= 1)
		return (color);
	r = (int)((color >> 16));
	g = (int)((color >> 8));
	b = (int)((color));
	r = (int)(r & (255 / shift));
	g = (int)(g & (255 / shift));
	b = (int)(b & (255 / shift));
	return (trgb(0, r, g, b));
}

static void		spr_help(t_all *all, t_spr_help *s, int i, float k)
{
	s->spr_x = all->s[i][s->i].x - all->plr->pos_x;
	s->spr_y = all->s[i][s->i].y - all->plr->pos_y;
	s->inv_d = 1.0 / (all->plr->plane_x * all->plr->dir_y -
			all->plr->dir_x * all->plr->plane_y);
	s->trf_x = s->inv_d * (all->plr->dir_y * s->spr_x - all->plr->dir_x *
			s->spr_y);
	s->trf_y = s->inv_d * (all->plr->plane_x * s->spr_y - all->plr->plane_y *
			s->spr_x);
	s->s_scr_x = (int)((all->win->width / 2) * (1 + s->trf_x / s->trf_y));
	s->spr_h = abs((int)(((all->win->height / (s->trf_y) * all->win->k)) / k));
	s->vm_scr = (int)((VMOVE / s->trf_y) + all->win->up * s->spr_h / 2.0);
	s->draw_s_y = all->win->height / 2 - s->spr_h / 2 + s->vm_scr;
	if (s->draw_s_y < 0)
		s->draw_s_y = 0;
	s->draw_e_y = s->spr_h / 2 + all->win->height / 2 + s->vm_scr;
	if (s->draw_e_y > all->win->height)
		s->draw_e_y = all->win->height;
	s->spr_w = abs((int)(((all->win->height / (s->trf_y) * all->win->k)) / k));
	s->draw_s_x = s->s_scr_x - s->spr_w / 2;
	if (s->draw_s_x < 0)
		s->draw_s_x = 0;
	s->draw_e_x = s->spr_w / 2 + s->s_scr_x;
	if (s->draw_e_x > all->win->width)
		s->draw_e_x = all->win->width;
	s->stripe = s->draw_s_x - 1;
}

static void		spr_help_2(t_all *all, t_spr_help *s, int i)
{
	s->s_tex_x = (int)(256 * (s->stripe - (-s->spr_w / 2 + s->s_scr_x)) *
					all->s_tex[i].w / s->spr_w) / 256;
	s->y = s->draw_s_y - 1;
	if (s->trf_y > 0 && s->stripe >= 0 && s->stripe < all->win->width &&
		s->trf_y < all->plr->zbuf[s->stripe])
		while (++s->y < s->draw_e_y)
		{
			s->d = (s->y - s->vm_scr) * 256 - all->win->height * 128 +
					s->spr_h * 128;
			s->s_tex_y = ((s->d * all->s_tex[i].h) / s->spr_h) / 256;
			s->k.x = s->s_tex_x;
			s->k.y = s->s_tex_y;
			s->color = my_tex_pixel_put(&all->s_tex[i], &s->k);
			s->k.x = s->stripe;
			s->k.y = s->y;
			if ((s->color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(all->win, &s->k, s->color);
		}
}

void			draw_sprites(t_all *all, int i, float k)
{
	t_spr_help	s;

	while (++i < SPR)
	{
		s.i = -1;
		while (++s.i < all->win->s_num[i])
			all->s[i][s.i].s_dist = (pow((all->plr->pos_x - all->s[i][s.i]
					.x), 2) + pow((all->plr->pos_y - all->s[i][s.i].y), 2));
		s.i = all->win->s_num[i];
		while (--s.i >= 0)
		{
			k = (i == 4) ? 0.1 * all->i + 1 : 1;
			spr_help(all, &s, i, k);
			while (++s.stripe < s.draw_e_x)
				spr_help_2(all, &s, i);
		}
	}
	put_bar(all);
}
