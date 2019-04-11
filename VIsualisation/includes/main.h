/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:44:56 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/11 18:49:43 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ft_printf.h"
# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "vm.h"

# define WIN_H 1300
# define WIN_W 2500
# define WIN_S (WIN_W * WIN_H)
# define X_P 0
# define Y_P 1

# define B_SPACE 49
# define B_COMMAND 259
# define B_ESC 53
# define B_W 13
# define B_S 1
# define B_A 0
# define B_D 2
# define B_NUM_4 86
# define B_NUM_6 88

# define PRIN_RET(a,s) {if (a){ft_putendl(s); return (0);}}
# define BLOCK_1(a, b, c, d) {a -= b; c += d;}
# define BLOCK_2(a, b, c, d, e) {if ((a += e) >= b) BLOCK_1(a, b, c, d);}
# define SGN(x) ((x < 0) ? -1 : ((x > 0) ? 1 : 0))

# define RGB_RED 0xff0000
# define RGB_GREEN 0x00ff00
# define RGB_BLUE 0x87cefa
# define RGB_WHITE 0xffffff
# define RGB_YELLOW 0xffff33
# define RGB_BLACK 0x000000

# define BUF_SIZE 1024

typedef struct	s_map
{
	int			*map;
	int			*flags;
	int			*size;
}				t_map;

typedef struct	s_my_array
{
	int			color;
	char		*str;
}				t_my_array;

typedef struct	s_mydata
{
	t_my_array	*arr;
	int			run;
	int			color[10];
	t_process	*process;
	t_param		*param;
	int			process_count;
	int			active_proces_line;
	int			active_proces;
	int			first_proces;
	int			first_reg;
	int			win;
}				t_mydata;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		*img;
	t_mydata	*mydata;
}				t_data;

typedef struct	s_win_par
{
	int			x;
	int			y;
	int			color_str;
	int			color_num;
	char		*str;
	int			par;
}				t_win_par;

typedef struct	s_print_proces
{
	int			x;
	int			y;
	t_process	*p;
	int			active;
}				t_print_proces;

void			ft_open_win(char *str);

int				ft_draw(t_data *data);
void			ft_draw_px(t_data *data, int x, int y, int color);
void			line_fast(t_data *env, double *p1, double *p2, int color);
void			ft_draw_square(t_data *data, int *pos, int rad, int color);
void			ft_clearwin(t_data *data);
void			draw_cube_empty(t_data *data, double par[2][2], int color);
void			ft_draw_back(t_data *data);

int				key_press(int key, t_data *data);
int				key_release(int key, t_data *data);

int				mouse_move(int x, int y, t_data *data);

int				ft_close(t_data *data);

char			*ft_rebase(unsigned long long n, int base);

int				ft_get_reg(t_process *proc, int reg_num);

void			ft_update_my_arr(t_data *data);

void			ft_start_game(t_data *data);

void			ft_out_params(t_data *data, t_win_par par);

void			ft_print_proces(t_data *data, t_print_proces o);

void			ft_print_champs(t_data *data, t_champ *champs);

t_process		*ft_get_process_id(t_data *data, int id);

void			ft_print_process(t_data *data);

void			ft_draw_char_big(t_data *data, int pos[2], char str, int i);
int				get_color_big_str(int x, int y, int step);
void			ft_win_won(t_data *data, char *name);

#endif
