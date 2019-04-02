/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_h.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:27:58 by vferry            #+#    #+#             */
/*   Updated: 2019/01/31 19:18:53 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ml_o_h(va_list ap)
{
	unsigned int	o_h;
	char			*str;

	o_h = (unsigned short)va_arg(ap, unsigned int);
	str = ft_itoabase(o_h, (unsigned int)8);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	ml_u_h(va_list ap)
{
	unsigned int	u_h;
	char			*str;

	u_h = (unsigned short)va_arg(ap, unsigned int);
	str = ft_itoabase(u_h, (unsigned int)10);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	ml_x_h(va_list ap)
{
	unsigned int	x_h;
	size_t			i;
	char			*str;

	x_h = (unsigned short)va_arg(ap, unsigned int);
	str = ft_itoabase(x_h, (unsigned int)16);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
	i = 0;
	while (i < g_info.strlen)
	{
		g_info.str[i] = ft_tolower(g_info.str[i]);
		i++;
	}
}

void	ml_upx_h(va_list ap)
{
	unsigned int	x_h;
	char			*str;

	x_h = (unsigned short)va_arg(ap, unsigned int);
	str = ft_itoabase(x_h, (unsigned int)16);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	ml_di_h(va_list ap)
{
	char	*str;
	int		di_h;

	di_h = (short)va_arg(ap, int);
	str = ft_itoa(di_h);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}
