/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:51:06 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/02/01 18:46:54 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_diez_f(void)
{
	int		i;
	char	dot;

	if (g_info.str)
	{
		i = 0;
		dot = 0;
		while (g_info.str[i])
			if (g_info.str[i++] == '.')
				return ;
		g_info.side = 0;
		info_add_strn(".", 1, 0);
	}
}

void	get_newstr(int i, int w)
{
	char	*temp;
	char	*s;

	temp = init_str_symb('0', w - i);
	if (g_info.str[0] == '-' || g_info.str[0] == '+')
	{
		if (g_info.str[0] == '-')
			s = ft_strjoin("-", temp);
		else
			s = ft_strjoin("+", temp);
		ft_strdel(&temp);
		temp = ft_strsub(g_info.str, 1, i - 1);
		ft_strdel(&g_info.str);
		g_info.str = ft_strjoin(s, temp);
		g_info.strlen += w - i;
		ft_strdel(&temp);
		ft_strdel(&s);
	}
	else
	{
		g_info.side = 1;
		info_add_strn(temp, w - i, 0);
	}
}

void	flag_null_d(void)
{
	int		i;
	int		w;
	int		res;

	w = 0;
	if (g_info.accuracy->data)
		return ;
	if (g_info.width)
		w = ft_atoi(g_info.width);
	i = ft_strlen(g_info.str);
	res = (is_flag('+') || is_flag(' '))
		&& g_info.str && g_info.str[0] != '-';
	if (w > i + res)
		get_newstr(i + res, w);
}

void	flag_null_f(void)
{
	int		i;
	int		w;
	int		res;

	w = 0;
	if (g_info.width)
		w = ft_atoi(g_info.width);
	i = ft_strlen(g_info.str);
	res = (is_flag('+') || is_flag(' '))
		&& g_info.str && g_info.str[0] != '-';
	if (w > i + res)
		get_newstr(i + res, w);
}

void	flag_probel(void)
{
	if (g_info.str && g_info.str[0] != '-')
	{
		g_info.side = 1;
		info_add_strn(" ", 1, 0);
	}
}
