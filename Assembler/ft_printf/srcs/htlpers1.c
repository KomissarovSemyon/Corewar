/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htlpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 17:36:29 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/02/03 17:36:31 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ac.h"

void	set_str(const char *s2, size_t size)
{
	char	*s;
	char	*t;

	t = g_info.str;
	s = (char *)malloc(g_info.strlen + size + 1);
	if (g_info.side == 0)
	{
		s = ft_memcpy(s, t, g_info.strlen);
		ft_memcpy(s + g_info.strlen, s2, size);
	}
	else
	{
		s = ft_memcpy(s, s2, size);
		ft_memcpy(s + size, t, g_info.strlen);
	}
	g_info.strlen += size;
	g_info.str = s;
	g_info.str[g_info.strlen] = '\0';
}

void	info_add_strn(const char *s2, size_t size, char new)
{
	char	*s;
	char	*t;

	if (g_info.strlen > 0 && new == 0)
		set_str(s2, size);
	else
	{
		t = g_info.str;
		s = (char *)malloc(size + 1);
		s = ft_memcpy(s, s2, size);
		g_info.strlen = size;
		g_info.str = s;
		g_info.str[g_info.strlen] = '\0';
		ft_strdel(&t);
	}
}

void	info_add_resn(const char *s2, size_t size, char new)
{
	char	*s;
	char	*t;

	t = g_info.res;
	if (g_info.len > 0 && new == 0)
	{
		s = (char *)malloc(g_info.len + size + 1);
		s = ft_memcpy(s, t, g_info.len);
		ft_memcpy(s + g_info.len, s2, size);
		g_info.len += size;
	}
	else
	{
		s = (char *)malloc(size + 1);
		s = ft_memcpy(s, s2, size);
		g_info.len = size;
	}
	g_info.res = s;
	g_info.res[g_info.len] = '\0';
	ft_strdel(&t);
}

void	clear(void)
{
	size_t	i;

	i = 0;
	g_info.type = NULL;
	g_info.ml = NULL;
	if (g_info.accuracy && g_info.accuracy->data)
		ft_strdel(&g_info.accuracy->data);
	g_info.accuracy->data = NULL;
	if (g_info.width)
		ft_strdel(&g_info.width);
	g_info.width = NULL;
	while (i < FLAGS_LEN)
	{
		g_info.flags[i] = NULL;
		i++;
	}
	if (g_info.str)
		ft_strdel(&g_info.str);
	g_info.str = NULL;
	g_info.side = 0;
	g_info.strlen = 0;
}

void	init_info(void)
{
	int		i;

	g_info.type = NULL;
	g_info.ml = NULL;
	g_info.accuracy = &g_accuracy;
	g_info.width = NULL;
	i = 0;
	while (i < FLAGS_LEN)
		g_info.flags[i++] = NULL;
	g_info.str = NULL;
	g_info.res = NULL;
	g_info.len = 0;
	g_info.side = 0;
	g_info.strlen = 0;
	g_info.flag = 0;
}
