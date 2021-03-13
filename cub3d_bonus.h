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

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "minilibx/mlx.h"

# define SCALE		20
# define TEX		4
# define SPR		8
# define ROT_SPEED	0.1
# define MOVE_SPEED	0.2
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
# define F_NONE	0b000000000000000
# define F_R	0b000000000000001
# define F_NO	0b000000000000010
# define F_SO	0b000000000000100
# define F_WE	0b000000000001000
# define F_EA	0b000000000010000
# define F_S1	0b000000000100000
# define F_F	0b000000001000000
# define F_C	0b000000010000000
# define F_S2	0b000000100000000
# define F_S3	0b000001000000000
# define F_S4	0b000010000000000
# define F_S5	0b000100000000000
# define F_S6	0b001000000000000
# define F_S7	0b010000000000000
# define F_S8	0b100000000000000
# define F_ALL	0b111111111111111
# define K_NONE	0b00000000
# define K_W	0b00000001
# define K_A	0b00000010
# define K_S	0b00000100
# define K_D	0b00001000
# define K_L	0b00010000
# define K_R	0b00100000
# define K_UP	0b01000000
# define K_DOW	0b10000000
# define K_ALL	0b11111111

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
	int			s_num[SPR];
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
	char		type;
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
	int			hp;
	int			wolf;
	int			svitok;
	int			ziri;
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
	t_spr		**s;
	t_tex		s_tex[SPR];
	int			i;
	char		key;
	t_tex		flo;
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
	char			*p_s[SPR];
	unsigned short	f;
	char			**map;
}				t_pars;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_floor
{
	int			p;
	int			c_x;
	int			c_y;
	int			color;
	float		rdx_s;
	float		rdy_s;
	float		rdx_e;
	float		rdy_e;
	float		pos_z;
	float		row_dist;
	float		fstep_x;
	float		fstep_y;
	float		f_x;
	float		f_y;
}				t_floor;

void			my_mlx_pixel_put(t_win *data, t_point *p, int color);
int				trgb(int t, int r, int g, int b);
t_win			*win_init(t_pars *pars, int argc, int i);
t_plr			*plr_init(t_all *all, int i, int j, char c);
t_all			*all_init(t_pars *p, int argc);
int				ft_isplayer(char c);
void			dda(t_all *all);
void			draw_scene(t_all *all);
int				ft_close(t_all *all);
int				key_hook(t_all *all);
int				my_tex_pixel_put(t_tex *data, t_point *p);
t_tex			*tex_init(t_all *all, char **path);
int				spr_init(t_all *all, int i, int j);
int				spr_tex_init(t_all *all, char **str);
void			ft_qsortf(float *s_arr, int first, int last);
void			ft_qsortspr(t_spr *s_arr, int first, int last);
void			keyrot(t_all *all, float rot);
void			key_w(t_all *all, int x);
void			key_s(t_all *all, int x);
void			key_d(t_all *all);
void			key_a(t_all *all);
void			draw_sprites(t_all *all, int i, float k);
void			ft_print_error(char *str);
int				check_cub(char *str);
void			check_file_help(char **line, t_list **head);
t_list			*check_file(char *file);
char			ft_ispars(char *str);
char			ft_search_string(char *str, t_pars *p);
int				all_is_digit(char *str);
int				ft_free_split(char **s);
void			ft_pars_r(t_pars *p, char *str, t_list **head, int i);
void			ft_pars_t_help(t_pars *p, char *s);
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
int				put_map(char **map, t_win *win, int size);
void			ft_pars_t_path(t_pars *p, char *s, char *path);
void			ft_spr_init(t_all *all, int i, int j, int k);
void			put_life(t_all *all, int size, int x, int i);
void			loop_wolf(t_all *all, int i, int j);
void			loop_svitok(t_all *all, int i, int j);
void			draw_floor(t_all *all);
void			put_text(t_all *all, char *path, int i);
void			draw_text(t_all *all);
int				keyup_hook(int keycode, t_all *all);
int				keydown_hook(int keycode, t_all *all);
void			put_barws(t_all *all, int size, int x, int i);
void			put_bar(t_all *all);

#endif
