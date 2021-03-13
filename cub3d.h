/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 22:02:07 by dcordeli          #+#    #+#             */
/*   Updated: 2021/02/07 22:02:09 by dcordeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "minilibx/mlx.h"

# define SCALE		20
# define TEX		4
# define ROT_SPEED	0.1
# define MOVE_SPEED	0.5
# define W		13
# define A		0
# define S		1
# define D		2
# define ESC	53
# define RIGHT	124
# define LEFT	123
# define UP		126
# define DOWN	125
# define UDIV	1
# define VDIV	1
# define VMOVE	0.0
# define F_NONE	0b00000000
# define F_R	0b00000001
# define F_NO	0b00000010
# define F_SO	0b00000100
# define F_WE	0b00001000
# define F_EA	0b00010000
# define F_S	0b00100000
# define F_F	0b01000000
# define F_C	0b10000000
# define F_ALL	0b11111111

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
	int			width;
	int			height;
	int			color_floor;
	int			color_ceil;
	int			s_num;
	float		k;
	float		up;
}				t_win;

typedef struct	s_tex
{
	char		*path;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
	int			w;
	int			h;
}				t_tex;

typedef struct	s_spr
{
	float		x;
	float		y;
	float		s_dist;
}				t_spr;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_plr
{
	float		pos_x;
	float		pos_y;
	float		dir;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	float		camerax;
	int			side;
	float		dist;
	float		tmp;
	double		wall_x;
	float		step[TEX];
	float		tex_pos[TEX];
	int			tex_x[TEX];
	int			tex_y;
	int			map_x;
	int			map_y;
	float		*zbuf;
}				t_plr;

typedef struct	s_spr_help
{
	float		spr_x;
	float		spr_y;
	float		inv_d;
	float		trf_x;
	float		trf_y;
	int			s_scr_x;
	int			vm_scr;
	int			spr_h;
	int			spr_w;
	int			draw_s_y;
	int			draw_s_x;
	int			draw_e_y;
	int			draw_e_x;
	int			stripe;
	int			s_tex_x;
	int			s_tex_y;
	int			d;
	int			i;
	int			y;
	t_point		k;
	int			color;
}				t_spr_help;

typedef struct	s_all
{
	t_win		*win;
	t_plr		*plr;
	char		**map;
	t_tex		*t;
	t_spr		*s;
	t_tex		s_tex;
}				t_all;

typedef struct	s_dda
{
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	float		ray_dir_x;
	float		ray_dir_y;
	float		d_dist_x;
	float		d_dist_y;
	float		s_dist_x;
	float		s_dist_y;
	float		pos_x;
	float		pos_y;
	int			line_h;
	int			draw_start;
	int			draw_end;
}				t_dda;

typedef struct	s_pars
{
	int				w;
	int				h;
	int				f_col;
	int				c_col;
	char			*p_no;
	char			*p_so;
	char			*p_we;
	char			*p_ea;
	char			*p_s;
	unsigned char	f;
	char			**map;
}				t_pars;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

void			my_mlx_pixel_put(t_win *data, t_point *p, int color);
int				trgb(int t, int r, int g, int b);
t_win			*win_init(t_pars *pars, int argc);
t_plr			*plr_init(t_all *all, int i, int j, char c);
t_all			*all_init(t_pars *p, int argc);
int				ft_isplayer(char c);
void			dda(t_all *all);
void			draw_scene(t_all *all);
int				ft_close(t_all *all);
int				key_hook(int keycode, t_all *all);
int				my_tex_pixel_put(t_tex *data, t_point *p);
t_tex			*tex_init(t_all *all, char **path);
int				spr_init(t_all *all);
int				spr_tex_init(t_all *all, char *str);
void			ft_qsortf(float *s_arr, int first, int last);
void			ft_qsortspr(t_spr *s_arr, int first, int last);
void			keyrot(t_all *all, float rot);
void			key_w(t_all *all);
void			key_s(t_all *all);
void			key_d(t_all *all);
void			key_a(t_all *all);
void			draw_sprites(t_all *all);
void			ft_print_error(char *str);
int				check_cub(char *str);
void			check_file_help(char **line, t_list **head);
t_list			*check_file(char *file);
char			ft_ispars(char *str);
char			ft_search_string(char *str, t_pars *p);
int				all_is_digit(char *str);
int				ft_free_split(char **s);
void			ft_pars_r(t_pars *p, char *str, t_list **head, int i);
void			ft_pars_t_help(t_pars *p, char *s, char *path);
void			ft_pars_t(t_pars *p, char *str, t_list **head);
int				ft_pars_c_help_two(char *tmp);
int				ft_pars_c_help(t_pars *p, char **s, int i, int j);
void			ft_pars_c(t_pars *p, char *str, t_list **head);
int				ft_max_map(t_list **list);
int				ft_check_map_c(t_list **list, int f);
char			*ft_create_map(char *str, int max);
char			**ft_pars_map_two(t_list **list, int max, int i, t_list *tmp);
void			ft_pars_map(t_pars *p, t_list **list, t_list **head);
void			ft_pars_pult(t_pars *p, t_list *tmp, t_list **head, char f);
void			ft_krest(char c, int i, int j, char **map);
t_pars			*ft_pars(t_list *head, int i, int j);
void			take_screenshot(t_all *all);
int				ft_rout(int button, int x, int y, t_all *all);
int				loop_key(t_all *all);
int				col_shadow(int color, float dist);
int				col_rainbow(int color, int step);
void			mlx_sq(t_win *win, t_point *p, int color, int size);
void			mlx_o(t_win *win, t_point *p, int color, int size);
void			mlx_t(t_win *win, t_point *p, int color, int size);
void			put_map(char **map, t_win *win, int size);

#endif
