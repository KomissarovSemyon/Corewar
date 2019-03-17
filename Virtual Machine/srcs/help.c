/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 21:15:58 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/17 00:56:40 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned char		*get_step(unsigned char *map, unsigned char *ptr, int step)
{
	return (map + (ptr - map + step) % MEM_SIZE);
}

void				set_value(unsigned char *dst, long src, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		dst[i] = (src << (64 - (size - i) * 8)) >> 56;
}

long				get_value(unsigned char *ptr, int size)
{
	long	res;
	int		i;

	res = 0;
	i = -1;
	while (++i < size)
		res = (res << (8 * i)) + ptr[i];
	return (res);
}
