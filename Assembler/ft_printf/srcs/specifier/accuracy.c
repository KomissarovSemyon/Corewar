/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accuracy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:35:47 by vferry            #+#    #+#             */
/*   Updated: 2019/02/04 15:36:49 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	minus(void)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(g_info.str) + 1);
	while (i < g_info.strlen)
	{
		str[i] = g_info.str[i];
		if (g_info.str[i] == '-')
		{
			str[i] = '0';
			str[0] = '-';
		}
		i++;
	}
	str[i] = 0;
	info_add_strn(str, g_info.strlen, 1);
	ft_strdel(&str);
}

void		ac_ups(void)
{
	unsigned char	*str;
	char			*byte;
	int				len;
	int				c;
	int				j;

	if ((len = ft_atoi(g_info.accuracy->data)) == 0)
		return ;
	str = malloc(sizeof(char) * len + 1);
	j = 1;
	c = 0;
	str = (unsigned char *)ft_strsub(g_info.str, 0, len);
	while ((len - j) > 0)
		if (str[len - j] >= 192)
			break ;
		else
			j++;
	byte = ft_itoabase(str[len - j], 2);
	while (byte[c] != '0')
		c++;
	if (c > j)
		str[len - j] = '\0';
	ft_strdel(&byte);
	info_add_strn((char *)str, ft_strlen((char *)str), 1);
	free(str);
}

void		ac_csp(void)
{
	char		*str;
	size_t		i;
	size_t		len;

	if (g_info.type->val[0] == 's' && g_info.ml && g_info.ml->data[0] == 'l')
	{
		ac_ups();
		return ;
	}
	i = 0;
	len = ft_atoi(g_info.accuracy->data);
	str = malloc(sizeof(char) * len + 1);
	while (i < len && g_info.str[i])
	{
		str[i] = g_info.str[i];
		i++;
	}
	str[i] = 0;
	info_add_strn(str, i, 1);
	ft_strdel(&str);
}

static void	ac_dioux_vs(int width, int w_str)
{
	int		i;
	char	*str;

	width = width - w_str;
	str = malloc(sizeof(char) * width + 1);
	i = 0;
	while (i < width)
	{
		str[i] = '0';
		i++;
	}
	str[i] = 0;
	g_info.side = 1;
	info_add_strn(str, width, 0);
	ft_strdel(&str);
	if (g_info.type->val[0] == 'd' || g_info.type->val[0] == 'i')
		minus();
}

void		ac_dioux(void)
{
	int		width;
	int		w_str;

	width = ft_atoi(g_info.accuracy->data);
	w_str = ft_strlen(g_info.str);
	if (g_info.str[0] == '-')
		w_str--;
	if (width == 0 && g_info.str[0] == '0')
	{
		info_add_strn("", 0, 1);
		return ;
	}
	if (width <= w_str)
		return ;
	else
		ac_dioux_vs(width, w_str);
}
