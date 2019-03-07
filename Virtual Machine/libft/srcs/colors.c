/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:27:15 by jcorwin           #+#    #+#             */
/*   Updated: 2019/01/19 11:15:31 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		color_check(t_printf *pr)
{
	char	*str;

	++pr->str;
	str = pr->str + 1;
	if (!pr_isdigit(*str++))
		return (1);
	if (!pr_isdigit(*str++))
		return (1);
	if (*str++ != ':')
		return (1);
	if (!pr_isdigit(*str++))
		return (1);
	if (!pr_isdigit(*str++))
		return (1);
	if (*str != '}')
		return (1);
	++pr->str;
	return (0);
}

static int		color_getf(t_printf *pr)
{
	int		num;

	num = 0;
	if (*pr->str == '0')
	{
		num += 30;
		num += *(pr->str + 1) - '0';
	}
	else if (*pr->str == '1')
	{
		num += 90;
		num += *(pr->str + 1) - '0';
	}
	else
		return (99);
	return (num % 10 > 7 ? 99 : num);
}

static int		color_getb(t_printf *pr)
{
	int		num;

	num = 0;
	if (*pr->str == '0')
	{
		num += 40;
		num += *(pr->str + 1) - '0';
	}
	else if (*pr->str == '1')
	{
		num += 100;
		num += *(pr->str + 1) - '0';
	}
	else
		return (99);
	return (num % 10 > 7 ? 99 : num);
}

static void		add_num(t_printf *pr, int num)
{
	if (num > 9)
		add_num(pr, num / 10);
	buf_add(pr, num % 10 + '0');
}

void			pars_color(t_printf *pr)
{
	int		fg;
	int		bg;

	if (color_check(pr))
		return ;
	fg = color_getf(pr);
	pr->str += 3;
	bg = color_getb(pr);
	pr->str += 3;
	if (fg == 99 || bg == 99)
	{
		if (bg == 40)
			pr_bufaddstr(pr, "\e[1;1H\e[2J");
		pr_bufaddstr(pr, "\e[0;m");
	}
	else
	{
		pr_bufaddstr(pr, "\e[0");
		add_num(pr, fg);
		buf_add(pr, ';');
		add_num(pr, bg);
		pr_bufaddstr(pr, ";m");
	}
}
