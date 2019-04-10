/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_check1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 06:44:00 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/10 07:00:45 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char					get_map_pos(t_process *p, int pos)
{
	while (pos >= MEM_SIZE)
		pos -= MEM_SIZE;
	return (*(p->map + pos));
}

int						check_reg(int reg)
{
	return (reg > 0 && reg <= REG_NUMBER);
}

int						op_check(t_process *p)
{
	t_funs		*op;
	int			codage;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (p->op.id == LIVE || p->op.id == ZJMP || p->op.id == FORK ||
			p->op.id == LFORK)
		return (1);
	if (p->op.id > 15)
		return (0);
	return (g_op_tab[p->op.id].f_check(p));
}

int						op_check_live(t_process *p)
{
	return (1);
}
