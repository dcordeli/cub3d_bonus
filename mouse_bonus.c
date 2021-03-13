/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:10:21 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/20 17:10:24 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		ft_rout(int button, int x, int y, t_all *all)
{
	(void)y;
	if (button == 1 && x >= all->win->width / 2)
		keyrot(all, ROT_SPEED);
	else if (button == 1 && x < all->win->width / 2)
		keyrot(all, -ROT_SPEED);
	loop_key(all);
	return (0);
}

void	ft_pars_t_path(t_pars *p, char *s, char *path)
{
	if (s[0] == 'N')
		p->p_no = path;
	else if (s[0] == 'W')
		p->p_we = path;
	else if (s[0] == 'E')
		p->p_ea = path;
	else if (s[0] == 'S' && s[1] == 'O')
		p->p_so = path;
	else if (s[0] == 'S' && ft_strchr("12345678", s[1]))
		p->p_s[s[1] - '1'] = path;
}

void	ft_spr_init(t_all *all, int i, int j, int k)
{
	int tmp;

	tmp = all->map[i][j] - '2';
	all->s[tmp][k].x = (float)j + (float)0.5;
	all->s[tmp][k].y = (float)i + (float)0.5;
	all->s[tmp][k].type = all->map[i][j];
}

void	loop_wolf(t_all *all, int i, int j)
{
	if (all->map[i][j] == '8')
	{
		if (all->s[6][0].s_dist < 1)
			all->s[6][0].y += 1;
		all->map[i][j] = '0';
		all->plr->wolf++;
	}
	if (all->map[i][j] == '9' && all->plr->wolf == 0)
		all->plr->hp--;
	if (all->map[i][j] == '9' && all->plr->wolf > 0)
	{
		if (all->s[7][0].s_dist < 1)
			all->s[7][0].y += 2;
		all->map[i][j] = '0';
	}
	if (all->map[i][j] == '6')
	{
		if (all->s[4][0].s_dist < 1)
			all->s[4][0].y += 1;
		else if (all->s[4][1].s_dist < 1)
			all->s[4][1].y += 1;
		all->map[i][j] = '0';
		all->plr->hp++;
	}
	loop_svitok(all, i, j);
}

void	loop_svitok(t_all *all, int i, int j)
{
	if (all->map[i][j] == '5')
	{
		if (all->s[3][0].s_dist < 1)
			all->s[3][0].y += 1;
		all->map[i][j] = '0';
		all->plr->svitok++;
	}
	if (all->map[i][j] == '7' && all->plr->svitok > 0)
	{
		if (all->s[5][0].s_dist < 2)
			all->s[5][0].y += 2;
		all->map[i][j] = '0';
	}
}
