/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:23:03 by jcorwin           #+#    #+#             */
/*   Updated: 2019/01/18 16:36:13 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		pr_f(t_printf *pr, t_printf_param *p, long full, long dec)
{
	pr_nbr(pr, p->len - 1 - p->prec, full);
	buf_add(pr, '.');
	pr_nbr(pr, p->prec > 100 ? 100 : p->prec, dec);
	if (p->prec > 100)
		while (p->prec-- > 100)
			buf_add(pr, '0');
}

static void		pr_sign(t_printf *pr, t_printf_param *p, long full, long dec)
{
	if (full < 0 || p->f & F_PLUS || p->f & F_SPACE)
	{
		if (full < 0 || p->f & F_PLUS)
			buf_add(pr, full < 0 ? '-' : '+');
		else
			buf_add(pr, ' ');
		--p->len;
		pr_f(pr, p, full, dec);
		++p->len;
	}
	else
		pr_f(pr, p, full, dec);
}

static long		get_dec(double num, int len, long *full)
{
	long	dec;
	int		slen;
	double	prec;

	num = FT_ABS(num);
	len = len > 100 ? 100 : len;
	dec = 0;
	slen = len;
	prec = 0.1;
	while (slen--)
		prec *= 0.1;
	if (num + prec > 1.0)
		*full += 1.0;
	while (len--)
	{
		num *= 10.0;
		prec *= 10.0;
		dec = dec * 10 + (long)(num + prec) % 10;
	}
	return (dec);
}

static void		pr_all(t_printf *pr, t_printf_param *p, long full, long dec)
{
	if (p->f & F_MINUS)
	{
		pr_sign(pr, p, full, dec);
		buf_fill(pr, p);
	}
	else
	{
		buf_fill(pr, p);
		pr_sign(pr, p, full, dec);
	}
}

void			print_float(t_printf *pr, t_printf_param *p)
{
	double		num;
	long		full;
	long		dec;
	long		tmp;

	if (!(p->f & F_PREC))
		p->prec = 6;
	num = (double)va_arg(pr->args, double);
	full = (long)(num);
	dec = get_dec(num - (double)full, p->prec, &full);
	tmp = full;
	while (tmp /= 10)
		++p->len;
	++p->len;
	p->len += 1 + p->prec;
	if (p->f & F_PLUS || p->f & F_SPACE || full < 0)
		++p->len;
	p->wid = p->wid < p->len ? p->len : p->wid;
	if (!(p->f & F_MINUS) && p->f & F_NUL && p->wid > p->len)
		p->len = p->wid;
	pr_all(pr, p, full, dec);
}
