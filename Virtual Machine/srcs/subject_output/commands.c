/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:05:03 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/10 22:10:50 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_fork(t_param *param, t_process *process)
{
	process_new(param, process,
			get_step(process->map, process->pc, process->op.arg[0] % IDX_MOD));
}

void		op_lfork(t_param *param, t_process *process)
{
	process_new(param, process,
			get_step(process->map, process->pc, process->op.arg[0]));
}

void		op_aff(t_param *param, t_process *process)
{
	char	c;

	(void)param;
	c = (char)get_value(NULL, process->r[process->op.arg[0]], REG_SIZE);
	write(1, &c, 1);
}
