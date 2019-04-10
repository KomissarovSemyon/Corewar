/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:44:20 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/02/01 18:45:42 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_plus(void)
{
	int		i;

	i = 0;
	while (g_info.str && g_info.str[i] && g_info.str[i] == ' ')
		i++;
	if (g_info.str[i] != '-')
	{
		if (i > 0)
			g_info.str[i - 1] = '+';
		else
		{
			g_info.side = 1;
			info_add_strn("+", 1, 0);
		}
	}
}
