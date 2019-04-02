/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:11:40 by vferry            #+#    #+#             */
/*   Updated: 2019/02/01 14:46:36 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*s_str(int length)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * length + 1)))
		return (NULL);
	while (i < length)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = 0;
	return (str);
}

static void		it_do(int i, int f_w)
{
	char	*space;

	space = s_str(f_w - i);
	g_info.side = 1;
	info_add_strn(space, f_w - i, 0);
	ft_strdel(&space);
}

static void		do_it(int i, int f_w)
{
	char	*space;

	space = s_str(f_w - i);
	g_info.side = 0;
	info_add_strn(space, f_w - i, 0);
	ft_strdel(&space);
}

void			field_width(void)
{
	int		f_w;
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (g_info.width == NULL)
		return ;
	f_w = ft_atoi(g_info.width);
	i = g_info.strlen;
	if (i >= f_w)
		return ;
	while (g_info.flags[j])
	{
		if (g_info.flags[j]->data[0] == '-')
		{
			do_it(i, f_w);
			return ;
		}
		j++;
	}
	if (g_info.flags[j] == NULL)
		it_do(i, f_w);
}
