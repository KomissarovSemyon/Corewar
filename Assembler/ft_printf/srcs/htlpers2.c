/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htlpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 17:48:35 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/02/03 17:48:39 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ml.h"

int		init_weidth(const char *fmt)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (fmt[i] == '*')
	{
		g_info.width = ft_strdup("*");
		i++;
	}
	else
	{
		while (fmt[i] && (fmt[i] >= '0' && fmt[i] <= '9'))
			i++;
		if (i > 0)
		{
			while (fmt[j] == '0')
				j++;
			g_info.width = ft_strsub(fmt, j, i - j);
		}
		else
			g_info.width = NULL;
	}
	return (i);
}

int		init_accuracy(const char *fmt)
{
	int		i;

	i = 0;
	if (fmt[i] && fmt[i] == '.' && (i++ || 1))
	{
		if (fmt[i] == '*' && i++)
			g_info.accuracy->data = ft_strdup("*");
		else
		{
			if (fmt[i] && fmt[i] == '-')
				g_info.accuracy->data = ft_strdup("0");
			else
			{
				while (fmt[i] && (fmt[i] >= '0' && fmt[i] <= '9'))
					i++;
				if (i != 1)
					g_info.accuracy->data = ft_strsub(fmt, 1, i - 1);
				else
					g_info.accuracy->data = ft_strdup("0");
			}
		}
	}
	else
		g_info.accuracy->data = NULL;
	return (i);
}

char	set_ml(char c, int j)
{
	if (c == g_modlen[j].data[0])
	{
		g_info.ml = &g_modlen[j + 1];
		return (2);
	}
	else
	{
		g_info.ml = &g_modlen[j];
		return (1);
	}
}

int		init_modlen(const char *fmt)
{
	int		j;
	char	r;

	j = 0;
	r = 0;
	while (fmt[0] && j < ML_LEN)
	{
		if (fmt[0] == g_modlen[j].data[0])
		{
			r = set_ml(fmt[1], j);
			j = ML_LEN;
		}
		j++;
	}
	if (j != ML_LEN + 1)
		g_info.ml = NULL;
	return (r);
}
