/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:51:43 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/15 18:51:45 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			ft_search_string(char *str, t_pars *p)
{
	char c;

	if (p->f & F_ALL)
		while (*str == ' ')
			str++;
	c = ft_ispars(str);
	if (c == 'R')
		return ('R');
	if (c == 'N' || c == 'S' || c == 's' || c == 'W' || c == 'E')
		return ('T');
	if (c == 'F' || c == 'C')
		return ('C');
	if (c == '1')
		return ('M');
	if (c == 'Z')
		return ('Z');
	return ('E');
}

int				all_is_digit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

int				ft_free_split(char **s)
{
	int i;

	i = -1;
	while (s[++i] != NULL)
		free(s[i]);
	free(s);
	return (-1);
}

void			ft_pars_r(t_pars *p, char *str, t_list **head, int i)
{
	char	**s;

	if (!(s = ft_split(str, ' ')))
		ft_print_error("Malloc is too greedy\n");
	while (s[i] != NULL)
		i++;
	if (i != 3 || all_is_digit(s[1]) == 0 || all_is_digit(s[2]) == 0 ||
		ft_atoi(s[1]) == 0 || ft_atoi(s[2]) == 0)
	{
		free(p);
		ft_free_split(s);
		ft_lstclear(head, free);
		ft_print_error("Invalid resolution string\n");
	}
	else
	{
		p->f = p->f | F_R;
		p->w = (ft_strlen_c(s[1], '0') > 5 ? INT16_MAX : ft_atoi(s[1]));
		p->h = (ft_strlen_c(s[2], '0') > 5 ? INT16_MAX : ft_atoi(s[2]));
		ft_free_split(s);
	}
}

void			ft_pars_pult(t_pars *p, t_list *tmp, t_list **head, char f)
{
	if (f == 'E' || (f == 'R' && (p->f & F_R) == 1))
	{
		free(p);
		ft_lstclear(head, free);
		ft_print_error("File content is incorrect\n");
	}
	if (f == 'R' && (p->f & F_R) == 0)
		ft_pars_r(p, tmp->content, head, 0);
	if (f == 'T')
		ft_pars_t(p, tmp->content, head);
	if (f == 'C')
		ft_pars_c(p, tmp->content, head);
	*head = ft_lstdelnote(*head, tmp, free);
}
