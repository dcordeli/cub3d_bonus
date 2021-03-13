/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:54:07 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/15 18:54:09 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_header(int fd, t_all *all)
{
	char			buf[54];
	unsigned int	size;

	size = 54 + 4 * all->win->width * all->win->height;
	ft_bzero(buf, 54);
	buf[0] = 'B';
	buf[1] = 'M';
	buf[2] = (unsigned char)(size);
	buf[3] = (unsigned char)(size >> 8);
	buf[4] = (unsigned char)(size >> 16);
	buf[5] = (unsigned char)(size >> 24);
	buf[10] = (unsigned char)(54);
	buf[14] = (unsigned char)(40);
	buf[18] = (unsigned char)(all->win->width);
	buf[19] = (unsigned char)(all->win->width >> 8);
	buf[20] = (unsigned char)(all->win->width >> 16);
	buf[21] = (unsigned char)(all->win->width >> 24);
	buf[22] = (unsigned char)all->win->height;
	buf[23] = (unsigned char)(all->win->height >> 8);
	buf[24] = (unsigned char)(all->win->height >> 16);
	buf[25] = (unsigned char)(all->win->height >> 24);
	buf[26] = (unsigned char)(1);
	buf[28] = (unsigned char)(all->win->bpp);
	buf[29] = (unsigned char)(all->win->bpp >> 8);
	write(fd, buf, 54);
}

void	take_screenshot(t_all *all)
{
	int				fd;
	int				i;
	int				j;
	unsigned int	*dst;

	j = all->win->height + 1;
	if (!(fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, 0777)))
		ft_print_error("Invalid create file\n");
	print_header(fd, all);
	draw_scene(all);
	while (--j >= 0)
	{
		i = -1;
		while (++i < all->win->width)
		{
			dst = (unsigned int *)(all->win->addr + (j * all->win->line_l +
					i * (all->win->bpp / 8)));
			write(fd, dst, 4);
		}
	}
	close(fd);
}
