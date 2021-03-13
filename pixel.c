/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:03:12 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/07 22:03:28 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				my_tex_pixel_put(t_tex *data, t_point *p)
{
	char	*dst;
	int		color;

	dst = data->addr + (p->y * data->line_l + p->x * (data->bpp / 8));
	color = (int)*(unsigned int*)dst;
	return (color);
}

void			my_mlx_pixel_put(t_win *data, t_point *p, int color)
{
	char	*dst;

	dst = data->addr + (p->y * data->line_l + p->x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int				trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int				ft_isplayer(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	else
		return (0);
}
