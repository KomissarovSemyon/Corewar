/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 05:29:34 by jcorwin           #+#    #+#             */
/*   Updated: 2019/01/18 16:34:26 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long long	get_num(t_printf *pr, t_printf_param *p)
{
	if (p->f & F_J)
		return ((intmax_t)va_arg(pr->args, intmax_t));
	else if (p->f & F_LL)
		return ((intmax_t)va_arg(pr->args, long long));
	else if (p->f & F_L)
		return ((intmax_t)va_arg(pr->args, long));
	else if (p->f & F_HH)
		return ((intmax_t)(char)(va_arg(pr->args, long)));
	else if (p->f & F_H)
		return ((intmax_t)(short)(va_arg(pr->args, long)));
	else
		return (intmax_t)va_arg(pr->args, int);
}

void				pr_nbr(t_printf *pr, int len, intmax_t num)
{
	if (len > 1)
		pr_nbr(pr, len - 1, num / 10);
	buf_add(pr, FT_ABS(num % 10) + '0');
}

static void			pr_sign(t_printf *pr, t_printf_param *p, intmax_t num)
{
	if (num < 0 || p->f & F_PLUS || p->f & F_SPACE)
	{
		if (num < 0 || p->f & F_PLUS)
			buf_add(pr, num < 0 ? '-' : '+');
		else
			buf_add(pr, ' ');
		pr_nbr(pr, --p->len, num);
		++p->len;
	}
	else
		pr_nbr(pr, p->len, num);
}

static void			pr_fucktheflags(t_printf_param *p, intmax_t num)
{
	p->len = (p->f & F_PREC) && p->len < p->prec ? p->prec : p->len;
	if (p->f & F_PLUS || p->f & F_SPACE || num < 0)
		++p->len;
	if (!(p->f & F_MINUS) && !(p->f & F_PREC) && p->f & F_NUL)
		p->len = p->f & F_WID && p->wid > p->len ? p->wid : p->len;
	if (num == 0 && p->prec >= 0)
	{
		p->len = p->prec;
		p->f &= ~F_NUL;
	}
}

void				print_num(t_printf *pr, t_printf_param *p)
{
	intmax_t	num;
	intmax_t	tmp;

	num = get_num(pr, p);
	tmp = num;
	while (tmp /= 10)
		++p->len;
	++p->len;
	pr_fucktheflags(p, num);
	if (p->f & F_MINUS)
	{
		p->f &= ~F_NUL;
		if (p->len > 0)
			pr_sign(pr, p, num);
		buf_fill(pr, p);
	}
	else
	{
		if (p->wid > p->prec)
			p->f &= ~F_NUL;
		buf_fill(pr, p);
		if (p->len > 0)
			pr_sign(pr, p, num);
	}
}
