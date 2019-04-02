/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 21:09:51 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/29 21:44:18 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	pc_move(t_process *proc)
{
	int		tmp;
	int		i;

	++proc.pc;
	tmp = 0;
	i = -1;
	while ((proc.pc >> (6 - i * 2)) & 3)
		if ((proc.pc >> (6 - i * 2)) & 3 == REG_CODE)
			++tmp;
		else if ((proc.pc >> (6 - i * 2)) & 3 == DIR_CODE)
			tmp += g_op_tab[proc.op.id].label_size;
		else
			tmp += IND_SIZE;
	proc.pc += tmp;
}

int			champ_check(unsigned char *map, unsigned char *start, int size)
{
	t_process	proc;

	proc.pc = start;
	proc.op.id = *proc.pc - 1;
	proc.map = map;
	while (proc.pc != start + size)
		if (!op_check(&proc))
			return (1);
		else if (*proc->pc == g_op_tab[LIVE].id ||
						*proc->pc == g_op_tab[ZJMP].id ||
							*proc->pc == g_op_tab[FORK].id ||
									*proc->pc == g_op_tab[LFORK].id)
			proc->pc += 1 + g_op_tab[proc.op.id];
		else
			pc_move(&proc);
	return (0);
}
