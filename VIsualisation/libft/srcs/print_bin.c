/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:02:19 by jcorwin           #+#    #+#             */
/*   Updated: 2019/01/19 18:49:56 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		pr_bin(t_printf *pr, unsigned long long num, int size)
{
	int					i;

	i = size * 8;
	while (--i >= 0)
	{
		buf_add(pr, num & 1 << i ? '1' : '0');
		if (!(i % 8) && i != 0)
			buf_add(pr, ' ');
	}
}

void			print_bin(t_printf *pr, t_printf_param *p)
{
	unsigned long long	num;
	int					size;

	if (p->f & F_LL)
	{
		num = (unsigned long long)va_arg(pr->args, unsigned long long);
		size = 16;
	}
	else if (p->f & F_L || p->t == f || p->t == e || p->t == g || p->t == 2)
	{
		num = (unsigned long long)va_arg(pr->args, unsigned long);
		size = 8;
	}
	else
	{
		num = (unsigned long long)va_arg(pr->args, unsigned int);
		if (p->t == c || p->f & F_HH)
			size = 1;
		else if (p->f & F_H)
			size = 2;
		else
			size = 4;
	}
	pr_bin(pr, num, size);
}
