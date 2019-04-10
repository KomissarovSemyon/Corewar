/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_diouxX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:37:59 by vferry            #+#    #+#             */
/*   Updated: 2019/02/01 14:49:31 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_upx(va_list ap)
{
	char			*str;
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	str = ft_itoabase(x, (unsigned int)16);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	type_x(va_list ap)
{
	char			*str;
	unsigned int	x;
	size_t			i;

	i = 0;
	x = va_arg(ap, unsigned int);
	str = ft_itoabase(x, (unsigned int)16);
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	info_add_strn(str, i, 1);
	ft_strdel(&str);
}

void	type_u(va_list ap)
{
	char			*str;
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	str = ft_itoabase(u, (unsigned int)10);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	type_o(va_list ap)
{
	char			*str;
	unsigned int	o;

	o = va_arg(ap, unsigned int);
	str = ft_itoabase(o, (unsigned int)8);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	type_di(va_list ap)
{
	char	*str;
	int		di;

	di = va_arg(ap, int);
	str = ft_itoa(di);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}
