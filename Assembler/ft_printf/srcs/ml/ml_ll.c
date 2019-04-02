/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_ll.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:28:23 by vferry            #+#    #+#             */
/*   Updated: 2019/01/31 19:32:18 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ml_o_ll(va_list ap)
{
	unsigned long long	o_ll;
	char				*str;

	o_ll = va_arg(ap, unsigned long long);
	str = ft_itoabasell(o_ll, (long long)8);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	ml_u_ll(va_list ap)
{
	unsigned long long	u_ll;
	char				*str;

	u_ll = va_arg(ap, unsigned long long);
	str = ft_itoabasell(u_ll, (long long)10);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	ml_x_ll(va_list ap)
{
	unsigned long long	x_ll;
	size_t				i;
	char				*str;

	x_ll = va_arg(ap, unsigned long long);
	str = ft_itoabasell(x_ll, (long long)16);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
	i = 0;
	while (i < g_info.strlen)
	{
		g_info.str[i] = ft_tolower(g_info.str[i]);
		i++;
	}
}

void	ml_upx_ll(va_list ap)
{
	unsigned long long	x_ll;
	char				*str;

	x_ll = va_arg(ap, unsigned long long);
	str = ft_itoabasell(x_ll, (unsigned long long)16);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	ml_di_ll(va_list ap)
{
	char		*str;
	long long	di_ll;

	di_ll = va_arg(ap, long long);
	str = ft_itoabase_size_p(di_ll, (long long)10);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}
