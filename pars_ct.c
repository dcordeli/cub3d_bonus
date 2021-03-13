/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_ct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:51:26 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/15 18:51:28 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_pars_t_help(t_pars *p, char *s, char *path)
{
	if (s[0] == 'N' && (p->f & F_NO) == 0)
		p->f |= F_NO;
	else if (s[0] == 'W' && (p->f & F_WE) == 0)
		p->f |= F_WE;
	else if (s[0] == 'E' && (p->f & F_EA) == 0)
		p->f |= F_EA;
	else if (s[0] == 'S' && s[1] == 'O' && (p->f & F_SO) == 0)
		p->f |= F_SO;
	else if (s[0] == 'S' && s[1] == '\0' && (p->f & F_S) == 0)
		p->f |= F_S;
	else
		ft_print_error("Double parametr in the file\n");
	if (s[0] == 'N')
		p->p_no = path;
	else if (s[0] == 'W')
		p->p_we = path;
	else if (s[0] == 'E')
		p->p_ea = path;
	else if (s[0] == 'S' && s[1] == 'O')
		p->p_so = path;
	else if (s[0] == 'S' && s[1] == '\0')
		p->p_s = path;
}

void			ft_pars_t(t_pars *p, char *str, t_list **head)
{
	char	**s;
	int		i;

	i = 0;
	s = ft_split(str, ' ');
	while (s[i] != NULL)
		i++;
	if (i != 2 || open(s[1], O_RDONLY) == -1)
	{
		i = 0;
		while (s[i] != NULL)
			free(s[i++]);
		free(s);
		ft_lstclear(head, free);
		free(p);
		ft_print_error("Invalid textures or sprites string\n");
	}
	else
	{
		ft_pars_t_help(p, s[0], s[1]);
		free(s[0]);
		free(s);
	}
}

int				ft_pars_c_help_two(char *tmp)
{
	t_color color;
	int		i;
	int		kol;
	char	**s;

	i = -1;
	kol = 0;
	while (tmp[++i] != '\0' && (ft_isdigit(tmp[i]) == 1 || tmp[i] == ','))
		if (tmp[i] == ',')
			kol++;
	if (tmp[i] != '\0' || kol != 2 || !(s = ft_split(tmp, ',')) ||
		s[0] == NULL || s[1] == NULL || s[2] == NULL)
		return (-1);
	if (ft_strlen_c(s[0], '0') > 3 || ft_strlen_c(s[1], '0') > 3 ||
		ft_strlen_c(s[2], '0') > 3)
		return (ft_free_split(s));
	color.r = ft_atoi(s[0]);
	color.g = ft_atoi(s[1]);
	color.b = ft_atoi(s[2]);
	ft_free_split(s);
	if (color.r > 255 || color.g > 255 || color.b > 255)
		return (-1);
	return (trgb(0, color.r, color.g, color.b));
}

int				ft_pars_c_help(t_pars *p, char **s, int i, int j)
{
	char	*tmp;
	int		color;

	tmp = NULL;
	while (++j < i)
	{
		tmp = ft_realloc(tmp, ft_strlen(s[j]) + 1);
		ft_strlcat(tmp, s[j], ft_strlen(tmp) + ft_strlen(s[j]) + 1);
	}
	if (!tmp || ((color = ft_pars_c_help_two(tmp)) == -1))
		return (-1);
	free(tmp);
	if (s[0][0] == 'F' && (p->f & F_F) == 0)
	{
		p->f |= F_F;
		p->f_col = color;
	}
	else if (s[0][0] == 'C' && (p->f & F_C) == 0)
	{
		p->f |= F_C;
		p->c_col = color;
	}
	else
		return (-1);
	return (0);
}

void			ft_pars_c(t_pars *p, char *str, t_list **head)
{
	char	**s;
	int		i;

	i = 0;
	s = ft_split(str, ' ');
	while (s[i] != NULL)
		i++;
	if (i < 2 || i > 6 || ft_pars_c_help(p, s, i, 0) == -1)
	{
		ft_lstclear(head, free);
		free(p);
		ft_print_error("Invalid color string\n");
	}
	ft_free_split(s);
}
