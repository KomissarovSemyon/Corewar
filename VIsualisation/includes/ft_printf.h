/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 07:16:35 by jcorwin           #+#    #+#             */
/*   Updated: 2019/01/19 11:23:48 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <wchar.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFF 1000

# define F_MINUS (1 << 0)
# define F_PLUS (1 << 1)
# define F_SPACE (1 << 2)
# define F_HASH (1 << 3)
# define F_NUL (1 << 4)
# define F_B (1 << 5)
# define F_J (1 << 7)
# define F_Z (1 << 8)
# define F_HH (1 << 9)
# define F_H (1 << 10)
# define F_L (1 << 11)
# define F_LL (1 << 12)
# define F_LLL (1 << 13)
# define F_WID (1 << 14)
# define F_PREC (1 << 15)

# define MIN(a, b) (a > b ? b : a)
# define MAX(a, b) (a > b ? a : b)
# define FT_ABS(num) ((num) < 0 ? -(num) : (num))

typedef enum	e_type
{
	per = 0,
	c,
	C,
	s,
	S,
	p,
	P,
	d,
	D,
	i,
	I,
	o,
	O,
	u,
	U,
	x,
	X,
	f,
	F,
	e,
	g,
	hz
}				t_type;

typedef struct	s_printf_param
{
	unsigned short		f;
	int					wid;
	int					prec;
	t_type				t;
	int					len;
	int					base;
}				t_printf_param;

typedef struct	s_printf
{
	va_list		args;
	char		*str;
	char		buf[BUFF];
	int			len;
	char		*cur;
	int			fd;
}				t_printf;

int				ft_fprintf(int fd, const char *restrict format, ...);
int				ft_printf(const char *restrict format, ...);
void			print_format(t_printf *pr);
void			pars(t_printf *pr);
void			get_width(t_printf *pr, t_printf_param *p);

void			print_bin(t_printf *pr, t_printf_param *p);
void			print_wchar(t_printf *pr, t_printf_param *p, wchar_t wc);
void			print_str(t_printf *pr, t_printf_param *p);
void			print_num(t_printf *pr, t_printf_param *p);
void			print_unum(t_printf *pr, t_printf_param *p);
void			print_float(t_printf *pr, t_printf_param *p);

void			pr_nbr(t_printf *pr, int len, intmax_t num);

void			buf_check(t_printf *pr);
void			buf_fill(t_printf *pr, t_printf_param *p);
void			buf_add(t_printf *pr, char c);

int				pr_atoi(char **str);
int				pr_isdigit(int c);
int				pr_strchri(char *str, char c);
int				pr_strlen(char *str);
int				pr_wstrlen(wchar_t *str);
double			pr_pow(double num, int power);

void			pr_bufaddstr(t_printf *pr, char *str);

void			pars_color(t_printf *pr);

#endif
