/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:51:34 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/15 18:51:37 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void			ft_print_error(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	system("killall afplay");
	exit(1);
}

int				check_cub(char *str)
{
	int l;

	l = ft_strlen(str) - 1;
	if (str[l] == 'b' && str[l - 1] == 'u' && str[l - 2] == 'c' &&
		str[l - 3] == '.')
		return (1);
	else
		return (0);
}

void			check_file_help(char **line, t_list **head)
{
	t_list *list;

	if (!(list = ft_lstnew(*line)))
	{
		ft_lstclear(head, free);
		return ;
	}
	ft_lstadd_back(head, list);
}

t_list			*check_file(char *file)
{
	int		fd;
	char	*line;
	t_list	*head;

	if ((fd = open(file, O_RDONLY)) == -1 || (check_cub(file) == 0))
		ft_print_error("Invalid file name\n");
	head = NULL;
	while (get_next_line(fd, &line) > 0)
		check_file_help(&line, &head);
	check_file_help(&line, &head);
	close(fd);
	return (head);
}

char			ft_ispars(char *str)
{
	if (str[0] == 'R' && str[1] == ' ')
		return ('R');
	if (str[0] == 'S' && ft_isdigit(str[1]) && str[2] == ' ')
		return (str[1] + 1);
	if (str[0] == 'F' && str[1] == ' ')
		return ('F');
	if (str[0] == 'C' && str[1] == ' ')
		return ('C');
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		return ('N');
	if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		return ('S');
	if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		return ('W');
	if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		return ('E');
	if (str[0] == '1')
		return ('1');
	if (str[0] == '\0')
		return ('Z');
	return (0);
}
