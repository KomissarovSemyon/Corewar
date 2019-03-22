/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 21:15:58 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/20 23:16:16 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned char		*get_step(unsigned char *map, unsigned char *ptr, int step)
{
	return (map + (ptr - map + step) % MEM_SIZE);
}

void				set_value(unsigned char *map, unsigned char *dst,
												long long src, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		if (!map)
			dst[i] = (src << (sizeof(long long) - (size - i) * 8)) >>
				(sizeof(long long) - 8);
		else
			*get_step(map, dst, i) = (src << (sizeof(long long) -
						(size - i) * 8)) >>
							 (sizeof(long long) - 8);
}

long long			get_value(unsigned char *map, unsigned char *ptr, int size)
{
	long long	res;
	int			i;

	res = 0;
	i = -1;
	while (++i < size)
		if (map)
			res = (res << (8 * i)) + *get_step(map, ptr, i);
		else
			res = (res << (8 * i)) + ptr[i];
	return (res);
}

void			swap_champ(t_champ c1, t_champ c2)
{
	t_champ		c3;

	c3 = c1;
	c1 = c2;
	c2 = c3;
}
