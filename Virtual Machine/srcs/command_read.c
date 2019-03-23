/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:40:27 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/24 01:54:22 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void			op_type(t_process *p)
{
	p->op.ptr = get_step(p->map, p->pc, 1);
	if (p->op.id != LIVE && p->op.id != ZJMP &&
			p->op.id != FORK && p->op.id != LFORK)
	{
		p->op.arg_type[0] = *p->op.ptr >> 6;
		p->op.arg_type[1] = (*p->op.ptr >> 4) & 3;
		p->op.arg_type[2] = (*p->op.ptr >> 2) & 3;
		p->op.ptr = get_step(p->map, p->op.ptr, 1);
	}
	else
		p->op.arg_type[0] = DIR_CODE;
}

static void			arg_ind(t_process *p, int i)
{
	unsigned char	*ptr;
	long long		move;
	int				j;
	int				sign;

	sign = 0;
	if (*p->op.ptr & 128)
		sign = 1;
	move = 0;
	j = -1;
	while (++j < IND_SIZE)
	{
		move = (move << 8) + (sign ? 0xff - *p->op.ptr : *p->op.ptr);
		p->op.ptr = get_step(p->map, p->op.ptr, 1);
	}
	if (sign)
		move = -(move + 1);
	if (p->op.id != LLD)
		p->op.arg[i] = (long long)get_step(p->map, p->pc,
														move % IDX_MOD);
	else
		p->op.arg[i] = (long long)get_step(p->map, p->pc, move);
}

void				op_args(t_process *p)
{
	int		i;

	i = -1;
	op_type(p);
	while (++i < 3)
		if (p->op.arg_type[i] == 0)
			break ;
		else if (p->op.arg_type[i] == REG_CODE)
		{
			p->op.arg[i] = *p->op.ptr;
			p->op.ptr = get_step(p->map, p->op.ptr, 1);
		}
		else if (p->op.arg_type[i] == DIR_CODE)
		{
			p->op.arg[i] = get_value(p->map, p->op.ptr,
										g_op_tab[p->op.id].label_size);
			p->op.ptr = get_step(p->map, p->op.ptr,
										g_op_tab[p->op.id].label_size);
		}
		else
			arg_ind(p, i);
}
