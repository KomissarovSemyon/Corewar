/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:21:19 by jcorwin           #+#    #+#             */
/*   Updated: 2019/01/19 11:23:51 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			buf_add(t_printf *pr, char c)
{
	*pr->cur++ = c;
	buf_check(pr);
}

void			buf_fill(t_printf *pr, t_printf_param *p)
{
	int		len;

	len = p->wid - p->len;
	while (len-- > 0)
	{
		*pr->cur++ = p->f & F_NUL ? '0' : ' ';
		buf_check(pr);
	}
}

void			buf_check(t_printf *pr)
{
	if (!(++pr->len % BUFF))
	{
		write(pr->fd, pr->buf, BUFF);
		pr->cur = pr->buf;
	}
}

void			print_format(t_printf *pr)
{
	while (*pr->str)
	{
		if (*pr->str == '%')
		{
			if (*(pr->str + 1) == '{')
				pars_color(pr);
			else
				pars(pr);
		}
		else
		{
			*pr->cur++ = *pr->str++;
			buf_check(pr);
		}
	}
}

int				ft_printf(const char *restrict format, ...)
{
	t_printf	pr;

	pr.len = 0;
	pr.cur = pr.buf;
	pr.fd = 1;
	va_start(pr.args, format);
	pr.str = (char *)format;
	print_format(&pr);
	va_end(pr.args);
	write(pr.fd, pr.buf, pr.len % 1000);
	return (pr.len);
}
