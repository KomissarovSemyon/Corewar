/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htlpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:47:23 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/02/03 18:47:24 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "flags.h"
#include "initdata.h"

void	flag_up(int index, char c1, int *active)
{
	int			i;
	t_bigdata	*t;

	i = 0;
	while (i < index)
	{
		if (g_info.flags[i]->data[0] == c1)
		{
			t = g_info.flags[*active];
			g_info.flags[*active] = g_info.flags[i];
			g_info.flags[i] = t;
			(*active)++;
			break ;
		}
		i++;
	}
}

int		flag_swap(int *index, char c1, char c2)
{
	int		i;
	int		j;
	int		m;

	i = 0;
	j = -1;
	m = -1;
	while (i < *index)
	{
		if (g_info.flags[i]->data[0] == c1)
			j = i;
		if (g_info.flags[i]->data[0] == c2)
			m = i;
		i++;
	}
	if (j != -1 && m != -1)
	{
		(*index)--;
		g_info.flags[j] = g_info.flags[*index];
		g_info.flags[*index] = NULL;
		return (1);
	}
	return (0);
}

int		init_type(const char *fmt)
{
	int		j;
	char	norm;

	j = 0;
	norm = 0;
	while (fmt[0] && j < TYPES_LEN && !norm)
	{
		if (fmt[0] == g_types[j].val[0])
		{
			norm = 1;
			g_info.type = &g_types[j];
		}
		j++;
	}
	if (!fmt[0] || !norm)
	{
		clear();
		exit(1);
	}
	return (1);
}

void	flag_if(char c, int *k, int *index, int *good)
{
	if (c == g_flags[*k].data[0])
	{
		while (*good < *index && *good >= 0)
		{
			if (c == g_info.flags[*good]->data[0])
				*good = -10;
			(*good)++;
		}
		if (*good >= 0)
			g_info.flags[(*index)++] = &g_flags[*k];
		*good = 1;
	}
	(*k)++;
}

int		init_flags(const char *fmt)
{
	int		index;
	int		j;
	int		good;
	int		k;

	j = 0;
	index = 0;
	good = 1;
	while (good && fmt[j])
	{
		k = 0;
		good = 0;
		while (!good && k < FLAGS_LEN)
			flag_if(fmt[j], &k, &index, &good);
		j++;
	}
	g_info.flags[index] = NULL;
	check_flags(index);
	if ((good == 1 && fmt[0] == 0) || j == 0)
		return (0);
	return (j - 1);
}
