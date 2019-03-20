/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:40:27 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/19 07:23:53 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void			op_type(t_process *p)
{
	p->op.ptr = p->pc + 1;
	if (p->op.type != LIVE && p->op.type != ZJMP &&
			p->op.type != FORK && p->op.type != LFORK)
	{
		p->op.arg_type[0] = *p->op.ptr >> 6;
		p->op.arg_type[1] = *p->op.ptr << 2;
		p->op.arg_type[1] = p->op.arg_type[1] >> 6;
		p->op.arg_type[2] = *p->op.ptr << 4;
		p->op.arg_type[2] = p->op.arg_type[2] >> 6;
		p->op.ptr = get_step(p->map, p->op.ptr, 1);
	}
	else
		p->op.arg_type[0] = DIR_CODE;
	p->op.id = 0;
	while (g_op_tab[p->op.id].id != p->op.type)
		++p->op.id;
}

static void			arg_ind(t_process *p, int i)
{
	unsigned char	*ptr;

	if (p->op.type != LLD)
		p->op.arg[i] = (long long)get_step(p->map, p->op.ptr,
					get_value(p->map, p->op.ptr, IND_SIZE) % IDX_MOD);
	else
		p->op.arg[i] = (long long)get_step(p->map, p->op.ptr,
				get_value(p->map, p->op.ptr, IND_SIZE));
	p->op.ptr += IND_SIZE;
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
			p->op.ptr = get_step(p->op.ptr, p->map, 1);
		}
		else if (p->op.arg_type[i] == DIR_CODE)
		{
			p->op.arg[i] = get_value(p->map, p->op.ptr, g_op_tab[p->op.id].label_size);
			p->op.ptr += g_op_tab[p->op.id].label_size;
		}
		else
			arg_ind(p, i);
}
