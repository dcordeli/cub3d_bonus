/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:51:14 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/15 18:51:19 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_max_map(t_list **list)
{
	t_list	*tmp;
	int		max;

	tmp = *list;
	max = ft_strlen(tmp->content);
	while (tmp)
	{
		if (ft_strlen(tmp->content) > (size_t)max)
			max = ft_strlen(tmp->content);
		tmp = tmp->next;
	}
	return (max);
}

int				ft_check_map_c(t_list **list, int f)
{
	int		i;
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		i = -1;
		while (((char *)(tmp->content))[++i] != '\0' &&
			ft_strchr(" 012NWES", ((char *)(tmp->content))[i]))
		{
			if (ft_isplayer(((char *)(tmp->content))[i]))
			{
				if (f == 0)
					f = 1;
				else
					return (-1);
			}
		}
		if (((char *)(tmp->content))[i] != '\0')
			return (-1);
		tmp = tmp->next;
	}
	if (f == 0)
		return (-1);
	return (0);
}

char			*ft_create_map(char *str, int max)
{
	char	*map;
	int		l;
	int		i;

	l = ft_strlen(str);
	i = -1;
	if (!(map = (char *)malloc(sizeof(char) * (max + 1))))
		return (NULL);
	while (++i < l)
		map[i] = str[i];
	while (i < max)
		map[i++] = ' ';
	map[max] = '\0';
	return (map);
}

char			**ft_pars_map_two(t_list **list, int max, int i, t_list *tmp)
{
	char	**map;

	if (!(map = (char **)malloc(sizeof(char *) * (ft_lstsize(*list) + 2))))
		return (NULL);
	while (tmp)
	{
		if (((char *)(tmp->content))[0] == '\0' && tmp->next != NULL)
			if (((char *)(tmp->next->content))[0] != '\0')
			{
				free(map);
				return (NULL);
			}
		if (((char *)(tmp->content))[0] != '\0' && max > 0)
			if (!(map[++i] = ft_create_map(tmp->content, max)))
			{
				while (--i >= 0)
					free(map[i]);
				free(map);
				return (NULL);
			}
		tmp = tmp->next;
	}
	map[i + 1] = NULL;
	return (map);
}

void			ft_pars_map(t_pars *p, t_list **list, t_list **head)
{
	if (p->f != F_ALL || ft_check_map_c(list, 0) == -1 ||
		!(p->map = ft_pars_map_two(list, ft_max_map(list), -1, *list)))
	{
		free(p);
		ft_lstclear(head, free);
		ft_print_error("Invalid map\n");
	}
	ft_lstclear(head, free);
}
