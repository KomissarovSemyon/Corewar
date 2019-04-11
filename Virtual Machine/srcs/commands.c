/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:05:03 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/11 03:32:36 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_live(t_param *param, t_process *process)
{
	long long	val;

	val = process->op.arg[0];
	process->livin = param->current_cycle;
	if (val < 0 && val >= -param->players)
	{
		param->winner = -1 * val;
		if (!param->flag.vis)
			ft_printf("A process shows that player %d (%s) is alive\n",
							param->winner, param->champs[param->winner - 1]);
	}
	++param->live_nbr;
}

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
	if (!param->flag.vis)
		write(1, c > 31 && c < 127 ? &c : ".", 1);
}
