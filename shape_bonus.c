/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:39:02 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/27 16:48:18 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		mlx_sq(t_win *win, t_point *p, int color, int size)
{
	int i;
	int j;

	i = p->x;
	j = p->y;
	while ((p->y)++ < j + size && p->y < win->height)
	{
		p->x = i;
		while ((p->x)++ < i + size && p->x < win->width)
			my_mlx_pixel_put(win, p, color);
	}
	p->y -= size + 1;
	p->x = p->x - 1;
}

void		mlx_o(t_win *win, t_point *p, int color, int size)
{
	int i;
	int j;

	i = p->x;
	j = p->y;
	while ((p->y)++ < j + size && p->y < win->height)
	{
		color = col_rainbow(color, (int)255 / size);
		p->x = i;
		while ((p->x)++ < i + size && p->x < win->width)
			if ((p->x - i - size / 2) * (p->x - i - size / 2) + (p->y - j -
				size / 2) * (p->y - j - size / 2) <= size / 2 * size / 2)
				my_mlx_pixel_put(win, p, color);
	}
	p->y -= size + 1;
	p->x = p->x - 1;
}

void		mlx_t(t_win *win, t_point *p, int color, int size)
{
	int i;
	int j;

	i = p->x;
	j = p->y;
	while ((p->y)++ < j + size && p->y < win->height)
	{
		p->x = i;
		while ((p->x)++ < i + size && p->x < win->width)
		{
			if (p->y >= -2 * p->x + size + j + 2 * i &&
				p->y >= 2 * p->x + j - 2 * i - size && p->y <= j + size)
				my_mlx_pixel_put(win, p, color--);
			else
				my_mlx_pixel_put(win, p, trgb(0, 255, 125, 0));
		}
	}
	p->y -= size + 1;
	p->x = p->x - 1;
}

int			put_map(char **map, t_win *win, int size)
{
	t_point	p;
	int		i;
	int		j;

	i = -1;
	p.x = 0;
	p.y = 0;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (ft_strchr("17", map[i][j]) != NULL)
				mlx_sq(win, &p, trgb(0, 25, 125, 255), size);
			else if (ft_strchr("23", map[i][j]) != NULL)
				mlx_t(win, &p, trgb(0, 0, 255, 0), size);
			else
				mlx_sq(win, &p, trgb(0, 255, 125, 0), size);
		}
		p.x -= j * size;
		p.y += size;
	}
	return (p.y);
}

void		put_life(t_all *all, int size, int x, int i)
{
	t_point p;
	t_point	k;
	int		color;

	while (++i < all->plr->hp)
	{
		p.y = 0;
		k.y = 0;
		while (k.y < all->s_tex[4].h && p.y < all->win->height)
		{
			p.x = i * size + x + size / 4;
			k.x = 0;
			while (k.x < all->s_tex[4].w && p.x < all->win->width)
			{
				color = my_tex_pixel_put(&all->s_tex[4], &k);
				if ((color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(all->win, &p, color);
				k.x += floor(1.1 * (all->s_tex[4].w) / size);
				p.x++;
			}
			k.y += floor(1.1 * (all->s_tex[4].h) / size);
			p.y++;
		}
	}
}
