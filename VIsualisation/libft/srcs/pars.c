/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:30:58 by jcorwin           #+#    #+#             */
/*   Updated: 2019/01/19 11:50:06 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		get_wp(t_printf *pr, t_printf_param *p, int prec)
{
	if (prec)
	{
		if (pr_isdigit(*pr->str))
			p->prec = pr_atoi(&(pr->str));
		else
		{
			if ((p->prec = (int)va_arg(pr->args, int)) < 0)
				p->prec = -1;
			++pr->str;
		}
	}
	else
	{
		if (pr_isdigit(*pr->str))
			p->wid = pr_atoi(&(pr->str));
		else
		{
			if ((p->wid = (int)va_arg(pr->args, int)) < 0)
			{
				p->wid *= -1;
				p->f |= F_MINUS;
			}
			++pr->str;
		}
	}
}

static void		set_type_mod(t_printf_param *p, int i)
{
	if (i == 0)
		p->f |= p->f & F_H ? F_HH : F_H;
	else if (i == 1)
		p->f |= p->f & F_L ? F_LL : F_L;
	else if (i == 2)
		p->f |= F_LLL;
	else if (i == 3)
		p->f |= F_J;
	else
		p->f |= F_Z;
}

static void		get_type(t_printf *pr, t_printf_param *p)
{
	int		i;

	--pr->str;
	while ((i = pr_strchri("hlLjz", *(++pr->str))) != -1)
		set_type_mod(p, i);
	if ((i = pr_strchri("%cCsSpPdDiIoOuUxXfFeg", *pr->str++)) != -1)
		p->t = i;
	else
	{
		p->t = hz;
		--pr->str;
	}
	if (p->t == D || p->t == O || p->t == I || p->t == U || p->t == F)
		p->f |= F_L;
	p->t = p->t == F ? f : p->t;
	p->f |= (p->f & F_Z) ? F_J : p->f;
	if (p->f & F_L && (p->t == c || p->t == s))
		p->t = p->t == c ? C : S;
}

static void		get_flags(t_printf *pr, t_printf_param *p)
{
	int		i;

	p->f = 0;
	while ((i = pr_strchri("-+ #0b", *(++pr->str))) != -1)
		p->f |= 1 << i;
	while (pr_isdigit(*pr->str) || *pr->str == '*')
		get_wp(pr, p, 0);
	if (*pr->str == '.')
	{
		++pr->str;
		p->prec = 0;
		while (pr_isdigit(*pr->str) || *pr->str == '*')
			get_wp(pr, p, 1);
	}
	if (p->wid != -1)
		p->f |= F_WID;
	if (p->prec != -1)
		p->f |= F_PREC;
}

void			pars(t_printf *pr)
{
	t_printf_param	p;

	p.wid = -1;
	p.prec = -1;
	p.len = 0;
	get_flags(pr, &p);
	get_type(pr, &p);
	if (p.t == f)
		print_float(pr, &p);
	else if (p.f & F_B)
		print_bin(pr, &p);
	else if (p.t == s || p.t == S || p.t == c || p.t == C || p.t == per)
		print_str(pr, &p);
	else if (p.t == d || p.t == D || p.t == i || p.t == I)
		print_num(pr, &p);
	else if (p.t == u || p.t == o || p.t == x || p.t == 5
			|| p.t == U || p.t == O || p.t == X || p.t == P)
		print_unum(pr, &p);
	else
	{
		p.len = 1;
		if (p.f & F_MINUS)
			buf_add(pr, *pr->str++);
		buf_fill(pr, &p);
	}
}
