/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:02:15 by dcordeli          #+#    #+#             */
/*   Updated: 2021/03/04 13:27:03 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_tex		*tex_init(t_all *all, char **path)
{
	t_tex	*t;
	int		i;

	i = -1;
	if (!(t = (t_tex *)malloc(sizeof(t_tex) * TEX)))
		return (NULL);
	while (++i < TEX)
	{
		t[i].path = path[i];
		t[i].img = mlx_xpm_file_to_image(all->win->mlx, t[i].path, &t[i].w,
											&t[i].h);
		if (t[i].img == NULL)
			ft_print_error("Invalid texture file\n");
		t[i].addr = mlx_get_data_addr(t[i].img, &t[i].bpp, &t[i].line_l,
											&t[i].en);
	}
	return (t);
}

int			spr_init(t_all *all, int i, int j)
{
	int		k[SPR];

	ft_bzero(k, SPR * sizeof(int));
	if (!(all->s = (t_spr **)malloc(sizeof(t_spr *) * SPR)))
		return (-1);
	while (++j < SPR)
		if (!(all->s[j] = (t_spr *)malloc(sizeof(t_spr) * all->win->s_num[j])))
			return (-1);
	while (all->map[++i] != NULL)
	{
		j = -1;
		while (all->map[i][++j] != '\0')
		{
			if (ft_isdigit(all->map[i][j]) && all->map[i][j] > '1')
				ft_spr_init(all, i, j, k[all->map[i][j] - '2']++);
		}
	}
	return (0);
}

int			spr_tex_init(t_all *all, char **str)
{
	int i;
	int	j;

	j = -1;
	while (++j < SPR)
	{
		all->s_tex[j].path = str[j];
		all->s_tex[j].img = mlx_xpm_file_to_image(all->win->mlx,
			all->s_tex[j].path, &all->s_tex[j].w, &all->s_tex[j].h);
		if (all->s_tex[j].img == NULL)
			ft_print_error("Invalid sprite file\n");
		all->s_tex[j].addr = mlx_get_data_addr(all->s_tex[j].img,
			&all->s_tex[j].bpp, &all->s_tex[j].line_l, &all->s_tex[j].en);
		i = -1;
		while (++i < all->win->s_num[j])
		{
			all->s[j][i].s_dist = (float)(pow((all->plr->pos_x - (float)
					all->s[j][i].x), 2) + pow((all->plr->pos_y - (float)
					all->s[j][i].y), 2));
		}
	}
	return (0);
}
