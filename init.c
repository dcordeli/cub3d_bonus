/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:02:15 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/07 22:02:18 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_win		*win_init(t_pars *p, int argc)
{
	t_win	*win;
	int		wid;
	int		heig;

	if (!(win = (t_win *)malloc(sizeof(t_win))))
		return (NULL);
	win->mlx = mlx_init();
	mlx_get_screen_size(win->mlx, &wid, &heig);
	if (p->w > wid && argc == 2)
		p->w = wid;
	if (p->h > heig && argc == 2)
		p->h = heig;
	win->win = mlx_new_window(win->mlx, p->w, p->h, "cub3D");
	win->img = mlx_new_image(win->mlx, p->w, p->h);
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->line_l, &win->en);
	win->height = p->h;
	win->width = p->w;
	win->color_ceil = p->c_col;
	win->color_floor = p->f_col;
	win->s_num = 0;
	win->k = (float)((float)p->w / (float)p->h * (float)0.75);
	return (win);
}

void		plr_dir_init(char c, t_plr *plr)
{
	if (c == 'N')
	{
		plr->dir_x = 0;
		plr->dir_y = -(float)0.99;
	}
	if (c == 'S')
	{
		plr->dir_x = 0;
		plr->dir_y = (float)0.99;
	}
	if (c == 'E')
	{
		plr->dir_x = (float)0.99;
		plr->dir_y = 0;
	}
	if (c == 'W')
	{
		plr->dir_x = -(float)0.99;
		plr->dir_y = 0;
	}
}

t_plr		*plr_init(t_all *all, int i, int j, char c)
{
	t_plr *plr;

	if (!(plr = (t_plr *)malloc(sizeof(t_plr))))
	{
		free(all->win);
		free(all);
		return (NULL);
	}
	plr->pos_x = (float)j + (float)0.5;
	plr->pos_y = (float)i + (float)0.5;
	plr_dir_init(c, plr);
	plr->camerax = 0;
	plr->plane_x = -(float)0.66 * plr->dir_y;
	plr->plane_y = (float)0.66 * plr->dir_x;
	return (plr);
}

int			player_init(t_all *all)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (all->map[i] != NULL)
	{
		while (all->map[i][j] != '\0')
		{
			if (ft_isplayer(all->map[i][j]) == 1)
				if (!(all->plr = plr_init(all, i, j, all->map[i][j])))
					return (-1);
			if (all->map[i][j] == '2')
				all->win->s_num++;
			j++;
		}
		j = 0;
		i++;
	}
	if (!(all->plr->zbuf = (float *)malloc(sizeof(float) * all->win->width)))
		return (-1);
	return (0);
}

t_all		*all_init(t_pars *p, int argc)
{
	t_all	*all;
	char	*path[TEX];

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		return (NULL);
	if (!(all->win = win_init(p, argc)))
		return (NULL);
	all->map = p->map;
	if (player_init(all) == -1 || spr_init(all) == -1)
		return (NULL);
	spr_tex_init(all, p->p_s);
	path[0] = p->p_no;
	path[1] = p->p_so;
	path[2] = p->p_we;
	path[3] = p->p_ea;
	if (!(all->t = tex_init(all, path)))
		return (NULL);
	free(p);
	return (all);
}
