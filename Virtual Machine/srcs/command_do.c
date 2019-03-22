/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 22:19:11 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/22 17:58:04 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		do_op(t_param *param, t_process *process)
{
	op_args(process);
	if (g_op_tab[i].f_check(process))
	{
		if (param->flag.oper)
			ft_printf("process %d executing %s\n", process->id,
												g_op_tab[process->op.id].name);
		g_op_tab[i].f_do(param, process);
	}
	else if (param->flag.oper)
		ft_printf("process %d failed %s\n", process->id, g_op_tab[process->op.id]);
	if (param->flag.oper)
		ft_printf("moving to %d\n\n", process->pc - process->map);
	process->pc = process->op.ptr;
	process->op.type = 0;
}
