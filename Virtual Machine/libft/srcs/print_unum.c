/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 05:29:34 by jcorwin           #+#    #+#             */
/*   Updated: 2019/01/18 16:34:53 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long long	get_num(t_printf *pr, t_printf_param *p)
{
	if (p->t == u || p->t == U)
		p->base = 10;
	else
		p->base = p->t == o || p->t == O ? 8 : 16;
	if (p->t == 5 || p->t == 6)
	{
		p->f |= F_L;
		p->f |= F_HASH;
	}
	else if (p->t == u || p->t == U)
		p->f &= ~F_HASH;
	if (p->f & F_J)
		return ((uintmax_t)va_arg(pr->args, uintmax_t));
	else if (p->f & F_Z)
		return ((uintmax_t)va_arg(pr->args, size_t));
	else if (p->f & F_LL)
		return ((uintmax_t)va_arg(pr->args, unsigned long long));
	else if (p->f & F_L)
		return ((uintmax_t)va_arg(pr->args, unsigned long));
	else if (p->f & F_HH)
		return ((uintmax_t)(unsigned char)(va_arg(pr->args, unsigned long)));
	else if (p->f & F_H)
		return ((uintmax_t)(unsigned short)(va_arg(pr->args, unsigned long)));
	return (uintmax_t)va_arg(pr->args, unsigned int);
}

static void					pr_unbr(t_printf *pr, t_printf_param *p, int len,
														uintmax_t num)
{
	char	ch;

	if (len > 1)
		pr_unbr(pr, p, len - 1, num / p->base);
	ch = num % p->base;
	if (ch < 10)
		ch += '0';
	else
		ch += (p->t == X || p->t == P ? 'A' : 'a') - 10;
	buf_add(pr, ch);
}

static void					pr_sign(t_printf *pr, t_printf_param *p,
														uintmax_t num)
{
	if (p->f & F_HASH)
	{
		if (p->t == o || p->t == O)
		{
			if (num != 0 || p->prec == 0)
				buf_add(pr, '0');
		}
		else if (p->t != u && p->t != U &&
				!(num == 0 && (p->t == x || p->t == X)))
		{
			buf_add(pr, '0');
			buf_add(pr, p->t == X || p->t == P ? 'X' : 'x');
		}
	}
	if (p->len > 0 && !(p->prec == 0 && num == 0))
		pr_unbr(pr, p, p->len, num);
}

static void					pr_fucktheflags(t_printf_param *p, uintmax_t num)
{
	if (!(num == 0 && !(p->t == 5 || p->t == 6)) && p->f & F_HASH)
	{
		if (p->wid > p->prec)
			p->wid -= p->t == o || p->t == O ? 1 : 2;
		else if (p->t == o || p->t == O)
			p->prec -= p->t == o || p->t == O ? 1 : 2;
	}
	if (p->len < p->prec)
		p->len = p->prec;
	if (!(p->f & F_MINUS) && !(p->f & F_PREC) && p->f & F_NUL)
		p->len = p->wid > p->len ? p->wid : p->len;
	if (num == 0 && p->prec >= 0 && (p->t == u || p->t == U))
	{
		p->len = p->prec;
		p->f &= ~F_NUL;
	}
}

void						print_unum(t_printf *pr, t_printf_param *p)
{
	uintmax_t	num;
	uintmax_t	tmp;

	num = get_num(pr, p);
	tmp = num;
	while (tmp /= p->base)
		++p->len;
	++p->len;
	pr_fucktheflags(p, num);
	if (p->f & F_MINUS)
	{
		p->f &= ~F_NUL;
		pr_sign(pr, p, num);
		buf_fill(pr, p);
	}
	else
	{
		if (p->prec == 0 && num == 0)
			p->len = 0;
		buf_fill(pr, p);
		pr_sign(pr, p, num);
	}
}
