/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:01:08 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/02/03 16:16:44 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TYPES_LEN 16
# define ML_LEN 7
# define FLAGS_LEN 5
# define ST 1
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_elem	t_elem;
typedef struct			s_data
{
	char				*val;
	void				(*fun)(va_list);
}						t_data;
typedef struct			s_bigdata
{
	char				*data;
	t_data				access[TYPES_LEN + 1];
}						t_bigdata;
struct					s_elem
{
	t_data				*type;
	t_bigdata			*ml;
	t_bigdata			*accuracy;
	char				*width;
	t_bigdata			*flags[FLAGS_LEN + 1];
	char				*res;
	size_t				len;
	char				*str;
	size_t				strlen;
	char				side;
	char				flag;
};
t_elem					g_info;
void					new_f(long double d, long double f, int accuracy);
void					flag_up(int index, char c1, int *active);
int						flag_swap(int *index, char c1, char c2);
int						check_flags(int index);
int						init_flags(const char *fmt);
int						init_type(const char *fmt);
int						init_weidth(const char *fmt);
int						init_accuracy(const char *fmt);
int						init_modlen(const char *fmt);
void					clear(void);
void					init_info(void);
void					info_add_strn(const char *s,
							size_t count, char new);
void					info_add_resn(const char *s,
							size_t count, char new);
int						is_flag(char flag);
char					*conver(unsigned int a, size_t *size);
char					*init_str_symb(char c, int len);
int						ft_printf(const char *fmt, ...);
void					type_di(va_list ap);
void					type_o(va_list ap);
void					type_u(va_list ap);
void					type_x(va_list ap);
void					type_upx(va_list ap);
void					type_c(va_list ap);
void					type_l_c(va_list ap);
void					type_p(va_list ap);
void					type_s(va_list ap);
void					type_f(va_list ap);
void					type_l_s(va_list ap);
void					type_proc(va_list ap);
void					ml_di_h(va_list ap);
void					ml_o_h(va_list ap);
void					ml_u_h(va_list ap);
void					ml_x_h(va_list ap);
void					ml_upx_h(va_list ap);
void					ml_di_hh(va_list ap);
void					ml_o_hh(va_list ap);
void					ml_u_hh(va_list ap);
void					ml_x_hh(va_list ap);
void					ml_upx_hh(va_list ap);
void					ml_di_l(va_list ap);
void					ml_o_l(va_list ap);
void					ml_u_l(va_list ap);
void					ml_x_l(va_list ap);
void					ml_di_ll(va_list ap);
void					ml_o_ll(va_list ap);
void					ml_u_ll(va_list ap);
void					ml_x_ll(va_list ap);
void					ml_upx_ll(va_list ap);
void					ml_f(va_list ap);
void					svyaz(va_list ap);
void					field_width();
void					ml_upo_l(va_list ap);
void					ml_upu_l(va_list ap);
void					ml_upx_l(va_list ap);
void					flag_diez_o();
void					flag_diez_x();
void					flag_diez_upx();
void					flag_diez_f();
void					flag_null_d();
void					flag_null_f();
void					flag_probel();
void					flag_plus();
void					ac_dioux();
void					ac_csp();
void					ac_ups();
void					get_newstr(int i, int w);
char					*parse(va_list ap, const char *fmt, int *q);
#endif
