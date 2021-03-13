/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:02:15 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/07 22:02:18 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int			spr_init(t_all *all)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!(all->s = (t_spr *)malloc(sizeof(t_spr) * all->win->s_num)))
		return (-1);
	while (all->map[i] != NULL)
	{
		while (all->map[i][j] != '\0')
		{
			if (all->map[i][j] == '2')
			{
				all->s[k].x = (float)j + (float)0.5;
				all->s[k].y = (float)i + (float)0.5;
				k++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int			spr_tex_init(t_all *all, char *str)
{
	int i;

	i = -1;
	all->s_tex.path = str;
	all->s_tex.img = mlx_xpm_file_to_image(all->win->mlx, all->s_tex.path,
										&all->s_tex.w, &all->s_tex.h);
	if (all->s_tex.img == NULL)
		ft_print_error("Invalid sprite file\n");
	all->s_tex.addr = mlx_get_data_addr(all->s_tex.img, &all->s_tex.bpp,
										&all->s_tex.line_l, &all->s_tex.en);
	while (++i < all->win->s_num)
	{
		all->s[i].s_dist = (float)(pow((all->plr->pos_x - (float)all->s[i].x)
					, 2) + pow((all->plr->pos_y - (float)all->s[i].y), 2));
	}
	return (0);
}
