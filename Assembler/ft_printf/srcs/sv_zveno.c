/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_zveno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:02:03 by vferry            #+#    #+#             */
/*   Updated: 2019/02/04 15:27:15 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision(va_list ap)
{
	char	*precision;
	int		pre;

	pre = va_arg(ap, int);
	precision = ft_itoa(pre);
	if (g_info.accuracy->data)
		free(g_info.accuracy->data);
	g_info.accuracy->data = precision;
}

static void	w_str(va_list ap)
{
	int		width;

	width = va_arg(ap, int);
	g_info.width = ft_itoa(width);
}

static void	vs_svyaz(va_list ap, size_t *j)
{
	int	i;

	i = 0;
	*j = 0;
	if (g_info.width && g_info.width[0] == '*')
		w_str(ap);
	if (g_info.accuracy->data && g_info.accuracy->data[0] == '*')
		precision(ap);
	if (g_info.ml == NULL)
		g_info.type->fun(ap);
	else
	{
		while (g_info.ml->access[i].val != NULL)
			if (g_info.ml->access[i].val[0] == g_info.type->val[0])
			{
				g_info.ml->access[i].fun(ap);
				break ;
			}
			else
				i++;
	}
}

void		svyaz(va_list ap)
{
	size_t	i;
	int		j;

	vs_svyaz(ap, &i);
	if (g_info.accuracy->data)
		while (g_info.accuracy->access[i].val != NULL)
		{
			if (g_info.accuracy->access[i].val[0] == g_info.type->val[0])
				g_info.accuracy->access[i].fun(ap);
			i++;
		}
	i = 0;
	if (g_info.flag == 0)
		while (g_info.flags[i])
		{
			j = 0;
			while (j < (TYPES_LEN + 1) && g_info.flags[i]->access[j].val)
			{
				if (g_info.flags[i]->access[j].val[0] == g_info.type->val[0])
					g_info.flags[i]->access[j].fun(ap);
				j++;
			}
			i++;
		}
	field_width();
}
