/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:31:25 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/02/01 18:42:21 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char flag)
{
	int		i;

	i = 0;
	while (flag && g_info.flags[i])
	{
		if (g_info.flags[i]->data[0] == flag)
			return (1);
		i++;
	}
	return (0);
}

void	flag_diez_o(void)
{
	if (g_info.str && g_info.str[0] != '0')
	{
		g_info.side = 1;
		info_add_strn("0", 1, 0);
	}
}

char	*init_str_symb(char c, int len)
{
	char	*s;
	int		i;

	s = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	s[len] = 0;
	return (s);
}

void	flag_diez_x(void)
{
	char	*temp;
	int		i;
	int		w;

	if (g_info.str && g_info.str[0] && g_info.str[0] != '0')
	{
		w = 0;
		if (g_info.width)
			w = ft_atoi(g_info.width);
		i = ft_strlen(g_info.str);
		if (w > i + 2 && is_flag('0'))
		{
			temp = init_str_symb('0', w - i - 2);
			g_info.side = 1;
			info_add_strn(temp, w - i - 2, 0);
			ft_strdel(&temp);
		}
		g_info.side = 1;
		info_add_strn("0x", 2, 0);
	}
}

void	flag_diez_upx(void)
{
	char	*temp;
	int		i;
	int		w;

	if (!g_info.str)
		return ;
	w = 0;
	if (g_info.width)
		w = ft_atoi(g_info.width);
	i = ft_strlen(g_info.str);
	if (w > i + 2)
	{
		temp = init_str_symb(is_flag('0') ? '0' : ' ', w - i - 2);
		g_info.side = 1;
		info_add_strn(temp, w - i - 2, 0);
		ft_strdel(&temp);
	}
	g_info.side = 1;
	info_add_strn("0X", 2, 0);
}
