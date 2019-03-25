/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:44:56 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/25 22:58:57 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ft_printf.h"
# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
#include "vm.h"

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
	long long	cycles;
	int			run;
	int			color[10];
	t_process	*process;
	int			process_count;
	int			first_proces;
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

void			ft_open_win(char *str, int argc, char **argv);

int				ft_draw(t_data *data);
void			ft_draw_px(t_data *data, int x, int y, int color);
void			line_fast(t_data *env, double *p1, double *p2, int color);
void			ft_linefast_int(t_data *data, int *p1, int *p2, int color);
void			ft_draw_square(t_data *data, int *pos, int rad, int color);
void			ft_clearwin(t_data *data);

int				key_press(int key, t_data *data);
int				key_release(int key, t_data *data);

int				ft_close(t_data *data);

char			*ft_rebase(unsigned long long n, int base);

#endif
