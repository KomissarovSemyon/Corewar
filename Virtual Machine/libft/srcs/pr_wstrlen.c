/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:43:00 by jcorwin           #+#    #+#             */
/*   Updated: 2019/01/18 16:29:23 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pr_wstrlen(wchar_t *str)
{
	int		len;
	int		res;

	res = 0;
	len = 0;
	while (str[len] != 0)
	{
		if (str[len] < 0x80)
			++res;
		else if (str[len] < 0x800)
			res += 2;
		else if (str[len] < 0x10000)
			res += 3;
		else
			res += 4;
		++len;
	}
	return (res);
}
