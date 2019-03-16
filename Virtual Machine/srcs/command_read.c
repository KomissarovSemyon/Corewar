/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:40:27 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/16 02:37:18 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int			get_value(unsigned char *ptr, int size)
{
	int			i;
	int			res;

	i = 0;
	while (++i < size)
		++ptr;
	res = 0;
	while (i--)
		res = (res << 8) + *ptr--;
	return (res);
}

static void			op_type(t_process *p)
{
	p->op.ptr = p->pc + 1;
	if (p->op.type != LIVE && p->op.type != ZJMP &&
			p->op.type != FORK && p->op.type != LFORK)
	{
		++p->op.ptr;
		p->op.arg_type[0] = *p->op.ptr >> 6;
		p->op.arg_type[1] = (*p->op.ptr << 2) >> 6;
		p->op.arg_type[2] = (*p->op.ptr << 4) >> 6;
	}
	else
		p->op.arg_type[0] = DIR_CODE;
	++p->op.ptr;
}

void				op_args(t_process *p)
{
	int		i;

	i = -1;
	op_type(p);
	while (++i < 3)
		if (p->op.arg_type[i] == 0)
			break ;
		else if (p->op.arg_type[i] == REG)
		{
			p->op.arg[i] = &p->r[*p->op.ptr];
			p->op.ptr++;
		}
		else if (p->op.arg_type[i] == DIR)
		{
			p->op.arg[i] = &p->op.ptr;
			p->op.ptr += DIR_SIZE;
		}
		else
		{
			p->op.arg[i] = p->op.ptr + get_value(p->op.ptr, IND_SIZE) % IDX_MOD;
			p->op.ptr += IND_SIZE;
		}
}
