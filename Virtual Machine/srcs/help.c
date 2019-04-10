/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 21:15:58 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/10 17:19:35 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned char		*get_step(unsigned char *map,
									unsigned char *ptr, int step)
{
	long long		i;

	i = step > 0 ? step : -step;
	while (i--)
		if (step > 0)
		{
			if (ptr == map + MEM_SIZE - 1)
				ptr = map;
			else
				++ptr;
		}
		else
		{
			if (ptr == map)
				ptr = map + MEM_SIZE - 1;
			else
				--ptr;
		}
	return (ptr);
}

void				set_value(unsigned char *map, unsigned char *dst,
												long long src, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		if (!map)
			dst[i] = (src >> (size - i - 1) * 8) & 0xff;
		else
			*get_step(map, dst, i) = (src >> (size - i - 1) * 8) & 0xff;
}

long long			get_signed_value(unsigned char *map,
									unsigned char *ptr, int size)
{
	long long	res;
	int			i;
	int			sign;

	sign = 0;
	if (*ptr & 0x80)
		sign = 1;
	res = 0;
	i = -1;
	while (++i < size)
		if (map)
		{
			res = (res << 8) + (sign ? 0xff - *ptr : *ptr);
			ptr = get_step(map, ptr, 1);
		}
		else
			res = (res << 8) + (sign ? 0xff - ptr[i] : ptr[i]);
	if (sign)
		res = -res - 1;
	return (res);
}

long long			get_value(unsigned char *map, unsigned char *ptr, int size)
{
	long long	res;
	int			i;

	res = 0;
	i = -1;
	while (++i < size)
		if (map)
		{
			res = (res << 8) + (long long)(unsigned)*ptr;
			ptr = get_step(map, ptr, 1);
		}
		else
			res = (res << 8) + ptr[i];
	return (res);
}

void				swap_champ(t_champ *c1, t_champ *c2)
{
	t_champ		c3;

	c3 = *c1;
	*c1 = *c2;
	*c2 = c3;
}
