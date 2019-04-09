/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 21:09:51 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/09 03:44:02 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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
