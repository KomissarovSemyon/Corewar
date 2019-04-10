/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:28:15 by vferry            #+#    #+#             */
/*   Updated: 2019/01/31 19:26:44 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ml_o_l(va_list ap)
{
	long long	o_l;
	char		*str;

	o_l = va_arg(ap, long long);
	str = ft_itoabasell(o_l, (long long)8);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	ml_u_l(va_list ap)
{
	long long	u_l;
	char		*str;

	u_l = va_arg(ap, long long);
	str = ft_itoabasell(u_l, (long long)10);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	ml_x_l(va_list ap)
{
	long long	x_l;
	size_t		i;
	char		*str;

	x_l = va_arg(ap, long long);
	str = ft_itoabasell(x_l, (long long)16);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
	i = 0;
	while (i < g_info.strlen)
	{
		g_info.str[i] = ft_tolower(g_info.str[i]);
		i++;
	}
}

void	ml_upx_l(va_list ap)
{
	unsigned long long	x_l;
	char				*str;

	x_l = va_arg(ap, unsigned long long);
	str = ft_itoabasell(x_l, (long long)16);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	ml_di_l(va_list ap)
{
	char		*str;
	long long	di;

	di = va_arg(ap, long long);
	str = ft_itoabase_size_p(di, 10);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}
