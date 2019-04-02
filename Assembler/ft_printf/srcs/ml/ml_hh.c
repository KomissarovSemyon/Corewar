/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_hh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:28:09 by vferry            #+#    #+#             */
/*   Updated: 2019/01/31 19:23:03 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ml_o_hh(va_list ap)
{
	unsigned int	o_hh;
	char			*str;

	o_hh = (unsigned char)va_arg(ap, unsigned int);
	str = ft_itoabase(o_hh, (unsigned int)8);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	ml_u_hh(va_list ap)
{
	unsigned int	u_hh;
	char			*str;

	u_hh = (unsigned char)va_arg(ap, unsigned int);
	str = ft_itoabase(u_hh, (unsigned int)10);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	ml_x_hh(va_list ap)
{
	unsigned int	x_hh;
	size_t			i;
	char			*str;

	x_hh = (unsigned char)va_arg(ap, unsigned int);
	str = ft_itoabase(x_hh, (unsigned int)16);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
	i = 0;
	while (i < g_info.strlen)
	{
		g_info.str[i] = ft_tolower(g_info.str[i]);
		i++;
	}
}

void	ml_upx_hh(va_list ap)
{
	unsigned int	x_hh;
	char			*str;

	x_hh = (unsigned char)va_arg(ap, unsigned int);
	str = ft_itoabase(x_hh, (unsigned int)16);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	ml_di_hh(va_list ap)
{
	char	*str;
	int		di_hh;

	di_hh = (char)va_arg(ap, int);
	str = ft_itoa(di_hh);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}
