/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:50:59 by dcordeli          #+#    #+#             */
/*   Updated: 2020/12/07 14:42:35 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*get_check_buf(char **buf, char **line)
{
	char *ptr;

	ptr = NULL;
	if ((ptr = ft_strchr(*buf, '\n')) != NULL)
	{
		*ptr = '\0';
		*line = ft_realloc(*line, ft_strlen(*buf) + 1);
		ft_strlcat(*line, *buf, ft_strlen(*line) + ft_strlen(*buf) + 1);
		ft_strlcpy(*buf, ++ptr, BUFFER_SIZE + 1);
	}
	else
	{
		*line = ft_realloc(*line, ft_strlen(*buf) + 1);
		ft_strlcat(*line, *buf, ft_strlen(*line) + ft_strlen(*buf) + 1);
	}
	return (ptr);
}

static int		get_helper(int fd, char **line, char **buf, int s_read)
{
	char		*ptr;

	*line = NULL;
	ptr = get_check_buf(&(*buf), &(*line));
	while (ptr == NULL && (s_read = read(fd, *buf, BUFFER_SIZE)) != 0)
	{
		(*buf)[s_read] = '\0';
		if (*line == NULL)
		{
			free(*buf);
			*buf = NULL;
			return (-1);
		}
		ptr = get_check_buf(&(*buf), &(*line));
	}
	if (ft_strchr(*buf, '\n') != NULL || s_read > 0)
		return (1);
	free(*buf);
	*buf = NULL;
	return (0);
}

static t_gnl	*ft_lstnewg(int fd)
{
	t_gnl	*list;

	list = (t_gnl *)malloc(sizeof(t_gnl));
	if (NULL == list)
		return (NULL);
	list->fd = fd;
	list->buf = NULL;
	list->buf = ft_realloc(list->buf, BUFFER_SIZE + 1);
	if (NULL == list->buf)
	{
		free(list);
		return (NULL);
	}
	list->next = NULL;
	return (list);
}

static t_gnl	*ft_lstdelg(t_gnl *begin, t_gnl *tmp)
{
	t_gnl *pre;

	pre = begin;
	if (begin == tmp)
		begin = begin->next;
	else
	{
		while (pre->next != tmp)
			pre = pre->next;
		pre->next = tmp->next;
	}
	if (tmp->buf != NULL)
	{
		free(tmp->buf);
		tmp->buf = NULL;
	}
	tmp->next = NULL;
	free(tmp);
	tmp = NULL;
	return (begin);
}

int				get_next_line(int fd, char **line)
{
	static t_gnl	*begin;
	t_gnl			*tmp;
	int				res;

	if (fd < 0 || read(fd, 0, 0) == -1 || !line)
		return (-1);
	if (begin == NULL)
		if (!(begin = ft_lstnewg(fd)))
			return (-1);
	tmp = begin;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
		{
			tmp->next = ft_lstnewg(fd);
			if (tmp->next == NULL)
				return (-1);
		}
		tmp = tmp->next;
	}
	res = get_helper(fd, &(*line), &tmp->buf, 1);
	if (res < 1)
		begin = ft_lstdelg(begin, tmp);
	return (res);
}
