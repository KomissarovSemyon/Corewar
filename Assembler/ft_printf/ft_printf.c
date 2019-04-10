/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:50:33 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/02/01 21:29:57 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flags(int index)
{
	int			ret;
	int			active;

	ret = 0;
	active = 0;
	flag_up(index, '#', &active);
	ret += flag_swap(&index, '0', '-');
	flag_up(index, '0', &active);
	ret += flag_swap(&index, ' ', '+');
	flag_up(index, '+', &active);
	return (ret);
}

char	*parse(va_list ap, const char *fmt, int *q)
{
	int		i;

	i = 0;
	i += init_flags(fmt);
	i += init_weidth(fmt + i);
	i += init_accuracy(fmt + i);
	i += init_modlen(fmt + i);
	i += init_type(fmt + i) + 1;
	*q += i;
	svyaz(ap);
	info_add_resn(g_info.str, g_info.strlen, 0);
	clear();
	return (NULL);
}

void	gogogo(const char *fmt, int *i, int *last, va_list ap)
{
	while (fmt[*i])
	{
		if (fmt[*i] == '%')
		{
			if (fmt[*i + 1] != '%')
			{
				info_add_resn(fmt + *last, *i - *last, 0);
				parse(ap, fmt + *i + 1, i);
				*last = *i;
			}
			else
			{
				info_add_resn(fmt + *last, *i - *last + 1, 0);
				*i += 2;
				*last = *i;
			}
		}
		else
			(*i)++;
	}
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		last;

	va_start(ap, fmt);
	i = 0;
	last = 0;
	init_info();
	gogogo(fmt, &i, &last, ap);
	info_add_resn(fmt + last, i - last, 0);
	va_end(ap);
	write(ST, g_info.res, g_info.len);
	ft_strdel(&g_info.res);
	return (g_info.len);
}
