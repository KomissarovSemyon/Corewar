/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:38:11 by vferry            #+#    #+#             */
/*   Updated: 2019/02/04 19:47:16 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	inf_or_nan(long double f)
{
	if (f != f)
	{
		info_add_strn("nan", 3, 1);
		g_info.flag = 1;
		return (1);
	}
	if (f == (3.0 / 0.0))
	{
		info_add_strn("inf", 3, 1);
		g_info.flag = 1;
		return (1);
	}
	if (f == (-3.0 / 0.0))
	{
		info_add_strn("-inf", 4, 1);
		g_info.flag = 1;
		return (1);
	}
	return (0);
}

void		ml_f(va_list ap)
{
	int			accuracy;
	long double	f;
	long double	d;

	f = va_arg(ap, long double);
	if (inf_or_nan(f) == 1)
		return ;
	if (f < 0)
		d = -f;
	else
		d = f;
	if (g_info.accuracy->data == NULL)
		accuracy = 6;
	else
		accuracy = ft_atoi(g_info.accuracy->data);
	new_f(d, f, accuracy);
}

void		type_f(va_list ap)
{
	int		accuracy;
	double	f;
	double	d;

	f = va_arg(ap, double);
	if (inf_or_nan(f) == 1)
		return ;
	if (f < 0)
		d = -f;
	else
		d = f;
	if (g_info.accuracy->data == NULL)
		accuracy = 6;
	else
		accuracy = ft_atoi(g_info.accuracy->data);
	new_f(d, f, accuracy);
}
