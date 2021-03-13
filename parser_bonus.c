/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:51:54 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/15 18:51:56 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void			ft_krest(char c, int i, int j, char **map)
{
	if ((ft_strchr("023456789NWES", c) && (i == 0 || j == 0 || !map[i + 1])) ||
			(ft_strchr("023456789NWES", c) && (map[i][j + 1] == '\0' ||
			map[i - 1][j + 1] == '\0' || map[i + 1][j + 1] == '\0')) ||
			(ft_strchr("023456789NWES", c) && (map[i - 1][j - 1] == ' ' ||
			map[i - 1][j] == ' ' || map[i - 1][j + 1] == ' ' ||
			map[i][j - 1] == ' ' || map[i][j + 1] == ' ' ||
			map[i + 1][j - 1] == ' ' || map[i + 1][j] == ' ' ||
			map[i + 1][j + 1] == ' ')))
		ft_print_error("Map is open\n");
}

t_pars			*ft_pars(t_list *head, int i, int j)
{
	t_pars	*p;
	t_list	*tmp;
	char	f;

	if (!(p = (t_pars *)malloc(sizeof(t_pars))))
		return (NULL);
	p->f = F_NONE;
	tmp = head;
	while (tmp && ((f = ft_search_string(tmp->content, p)) != 'M'))
	{
		ft_pars_pult(p, tmp, &head, f);
		tmp = tmp->next;
	}
	ft_pars_map(p, &tmp, &head);
	while (p->map[++i] != NULL)
	{
		j = 0;
		while (p->map[i][j] != '\0')
		{
			ft_krest(((char **)(p->map))[i][j], i, j, p->map);
			j++;
		}
	}
	return (p);
}

void			ft_main_help(t_all *all)
{
	mlx_hook(all->win->win, 17, (1L << 2), ft_close, all);
	mlx_mouse_hook(all->win->win, ft_rout, all);
	mlx_hook(all->win->win, 2, (1L << 0), keydown_hook, all);
	mlx_hook(all->win->win, 3, (1L << 1), keyup_hook, all);
	mlx_loop_hook(all->win->mlx, loop_key, all);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	mlx_loop(all->win->mlx);
}

int				main(int argc, char **argv)
{
	t_pars		*p;
	t_all		*all;

	system("afplay ./music/track.mp3 &");
	if (argc == 2 || argc == 3)
	{
		if (!(p = ft_pars(check_file(argv[1]), -1, 0)))
			ft_print_error("Incorrect file\n");
		if (!(all = all_init(p, argc)))
			ft_print_error("Malloc is too greedy\n");
	}
	if (argc < 2 || argc > 3)
		ft_print_error("Invalid number of arguments\n");
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) != 6 || ft_strncmp(argv[2], "--save", 6) != 0)
			ft_print_error("Invalid second argument\n");
		take_screenshot(all);
	}
	if (argc == 2)
		ft_main_help(all);
	return (0);
}
