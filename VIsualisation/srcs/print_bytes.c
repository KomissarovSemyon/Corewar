/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:05:50 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/11 01:06:08 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				print_bytes(t_param *p, unsigned char *str, int len)
{
	(void)p;
	if (len == 0)
		len = ft_strlen((const char *)str);
	while (len--)
	{
		if (*str < 16)
			ft_printf("0");
		ft_printf("%hhx ", *str++);
	}
	ft_printf("\n");
}
