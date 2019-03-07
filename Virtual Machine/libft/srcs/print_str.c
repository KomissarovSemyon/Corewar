/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 02:52:27 by jcorwin           #+#    #+#             */
/*   Updated: 2019/01/18 19:05:29 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			print_c(t_printf *pr, t_printf_param *p)
{
	char	ch;

	if (p->t == per)
		ch = '%';
	else
		ch = (char)va_arg(pr->args, int);
	p->len = 1;
	if (p->f & F_MINUS)
	{
		*pr->cur++ = ch;
		buf_check(pr);
		buf_fill(pr, p);
	}
	else
	{
		buf_fill(pr, p);
		*pr->cur++ = ch;
		buf_check(pr);
	}
}

static void			print_s(t_printf *pr, t_printf_param *p)
{
	char	*str;
	int		len;

	if ((str = (char *)va_arg(pr->args, char *)))
	{
		len = pr_strlen(str);
		p->len = (p->f & F_PREC) ? MIN(p->prec, len) : len;
		len = p->len;
		if (p->f & F_MINUS)
		{
			while (len--)
				buf_add(pr, *str++);
			buf_fill(pr, p);
		}
		else
		{
			buf_fill(pr, p);
			while (len--)
				buf_add(pr, *str++);
		}
	}
	else if (p->f & F_PREC)
		buf_fill(pr, p);
	else
		pr_bufaddstr(pr, "(null)");
}

static void			print_ws(t_printf *pr, t_printf_param *p)
{
	wchar_t		*str;
	int			len;

	if ((str = (wchar_t *)va_arg(pr->args, wchar_t *)))
	{
		len = (p->f & F_PREC) ? MIN(p->prec, pr_wstrlen(str)) : pr_wstrlen(str);
		p->len = len;
		if (p->f & F_MINUS)
		{
			while (p->len > 0)
				print_wchar(pr, p, *str++);
			p->len = p->len < -1 ? len - 1 : len;
			buf_fill(pr, p);
		}
		else
		{
			buf_fill(pr, p);
			while (p->len > 0)
				print_wchar(pr, p, *str++);
		}
	}
	else if (p->f & F_PREC)
		buf_fill(pr, p);
	else
		pr_bufaddstr(pr, "(null)");
}

void				print_str(t_printf *pr, t_printf_param *p)
{
	wchar_t		wc;

	if (p->t == C)
	{
		wc = (wchar_t)va_arg(pr->args, wchar_t);
		print_wchar(pr, p, wc);
	}
	else if (p->t == S)
		print_ws(pr, p);
	else if (p->t == c || p->t == per)
		print_c(pr, p);
	else
		print_s(pr, p);
}
