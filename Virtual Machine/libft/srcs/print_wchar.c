/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:47:49 by jcorwin           #+#    #+#             */
/*   Updated: 2019/01/18 19:00:10 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			wchar_add(t_printf *pr, char *tmp)
{
	buf_add(pr, tmp[0]);
	if (tmp[1])
		buf_add(pr, tmp[1]);
	if (tmp[2])
		buf_add(pr, tmp[2]);
	if (tmp[3])
		buf_add(pr, tmp[3]);
}

static void			wchar_decode(char *tmp, wchar_t wc, int *b)
{
	if (wc < 0x800)
	{
		*b = 2;
		tmp[0] = ((wc & (0x1f << 6)) >> 6) | 0xC0;
	}
	else
	{
		if (wc < 0x10000)
		{
			*b = 3;
			tmp[0] = ((wc >> 12) & 0xf) | 0xE0;
		}
		else
		{
			*b = 4;
			tmp[0] = ((wc >> 18) & 7) | 0xF0;
			tmp[1] = ((wc >> 12) & 0x3f) | 0x80;
		}
		tmp[*b - 2] = ((wc >> 6) & 0x3f) | 0x80;
	}
	tmp[*b - 1] = (wc & 0x3f) | 0x80;
}

static int			wchar_get(char *tmp, wchar_t wc)
{
	int		b;

	b = 1;
	tmp[0] = wc;
	if (wc > 0x7f)
		wchar_decode(tmp, wc, &b);
	return (b);
}

static void			wchar_fill(t_printf *pr, t_printf_param *p,
												char *tmp, char *ptr)
{
	if (p->len > -2)
	{
		if (p->f & F_MINUS)
		{
			wchar_add(pr, tmp);
			if (p->t == C)
				buf_fill(pr, p);
		}
		else
		{
			if (p->t == C)
				buf_fill(pr, p);
			wchar_add(pr, tmp);
		}
	}
	else if (p->f & F_WID)
	{
		ptr = ++pr->cur;
		while (*ptr != ' ')
		{
			*ptr = *(ptr - 1);
			ptr--;
		}
		buf_check(pr);
	}
}

void				print_wchar(t_printf *pr, t_printf_param *p, wchar_t wc)
{
	char	tmp[4];
	char	*ptr;

	ptr = NULL;
	tmp[1] = 0;
	tmp[2] = 0;
	tmp[3] = 0;
	if (p->t == C)
		p->len = 1;
	p->len -= wchar_get(tmp, wc);
	if (p->t == C)
		p->len = 1;
	wchar_fill(pr, p, tmp, ptr);
}
