/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:40:27 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/10 17:44:51 by amerlon-         ###   ########.fr       */
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
	{
		p->op.arg_type[0] = DIR_CODE;
		p->op.arg_type[1] = 0;
		p->op.arg_type[2] = 0;
	}
}

static void			arg_ind(t_process *p, int i)
{
	long long		move;

	move = get_signed_value(p->map, p->op.ptr, IND_SIZE);
	if (p->op.id != LLD)
		p->op.arg[i] = (long long)get_step(p->map, p->pc,
														move % IDX_MOD);
	else
		p->op.arg[i] = (long long)get_step(p->map, p->pc, move);
	p->op.ptr = get_step(p->map, p->op.ptr, IND_SIZE);
}

static void			reg_step(t_process *p, int i)
{
	p->op.arg[i] = *p->op.ptr - 1;
	p->op.ptr = get_step(p->map, p->op.ptr, 1);
}

void				op_args(t_process *p)
{
	int		i;

	i = -1;
	op_type(p);
	while (++i < 3)
	{
		if (g_op_tab[p->op.id].params_type[i] == 0)
			break ;
		if (p->op.arg_type[i] == REG_CODE)
			reg_step(p, i);
		else if (p->op.arg_type[i] == DIR_CODE)
		{
			if (g_op_tab[p->op.id].codage && p->op.id != LDI &&
					p->op.id != LLDI && p->op.id != STI)
				p->op.arg[i] = get_value(p->map, p->op.ptr,
									g_op_tab[p->op.id].label_size);
			else
				p->op.arg[i] = get_signed_value(p->map, p->op.ptr,
									g_op_tab[p->op.id].label_size);
			p->op.ptr = get_step(p->map, p->op.ptr,
									g_op_tab[p->op.id].label_size);
		}
		else if (p->op.arg_type[i] == IND_CODE)
			arg_ind(p, i);
	}
}
