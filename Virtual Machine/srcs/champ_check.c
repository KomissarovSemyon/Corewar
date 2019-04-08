/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 21:09:51 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/07 21:53:15 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	pc_move(t_process *proc)
{
	int				tmp;
	int				i;
	unsigned char	codage;

	codage = *(proc->pc + 1);
	tmp = 2;
	i = -1;
	while (++i < 3)
		if (((codage >> (6 - i * 2)) & 3) == 0)
			break ;
		else if (((codage >> (6 - i * 2)) & 3) == REG_CODE)
			++tmp;
		else if (((codage >> (6 - i * 2)) & 3) == DIR_CODE)
			tmp += g_op_tab[proc->op.id].label_size;
		else
			tmp += IND_SIZE;
//	ft_printf("%d\n", tmp);
	proc->pc += tmp;
}

int			champ_check(unsigned char *start, int size)
{
	t_process	proc;

	proc.pc = start;
	proc.map = start;
	while (proc.pc < start + size)
	{
		proc.op.id = *proc.pc - 1;
		op_args(&proc);
		if (!op_check(&proc))
			return (1);
		proc.pc = proc.op.ptr;
	}
//	ft_printf("%d\n", proc.pc - start);
	return (proc.pc == start + size ? 0 : 1);
}
