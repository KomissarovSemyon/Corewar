/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_reg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:20:59 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/09 16:21:05 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static long long
	ft_get_value(unsigned char *ptr, int size)
{
	long long	res;
	int			i;

	res = 0;
	i = -1;
	while (++i < size)
		res = (res << (8 * i)) + ptr[i];
	return (res);
}

int
	ft_get_reg(t_process *proc, int reg_num)
{
	int		reg;

	reg = ft_get_value(proc->r[reg_num], REG_SIZE);
	return (reg);
}
