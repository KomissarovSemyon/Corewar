/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:58:19 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/11 03:10:04 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_ld(t_param *param, t_process *process)
{
	(void)param;
	if (process->op.arg_type[0] == DIR_CODE)
		set_value(NULL, process->r[process->op.arg[1]],
									process->op.arg[0], REG_SIZE);
	else
	{
		set_value(process->map, process->r[process->op.arg[1]],
			get_value(process->map, (unsigned char *)process->op.arg[0],
													DIR_SIZE), REG_SIZE);
	}
	process->carry = 1;
	if (get_value(NULL, process->r[process->op.arg[1]], REG_SIZE))
		process->carry = 0;
}

void		op_lld(t_param *param, t_process *process)
{
	op_ld(param, process);
}

void		op_st(t_param *param, t_process *process)
{
	long long	reg;

	reg = get_value(NULL, process->r[process->op.arg[0]], REG_SIZE);
	if (process->op.arg_type[1] == IND_CODE)
	{
		set_value(process->map, (unsigned char *)process->op.arg[1],
		reg, REG_SIZE);
		set_color(param, (unsigned char *)process->op.arg[1] -
			process->map, REG_SIZE,
			-1 * get_signed_value(NULL, process->r[0], REG_SIZE));
	}
	else
		set_value(NULL, process->r[process->op.arg[1]], reg, REG_SIZE);
}

void		op_add(t_param *param, t_process *process)
{
	(void)param;
	set_value(NULL, process->r[process->op.arg[2]],
			get_value(NULL, process->r[process->op.arg[0]], REG_SIZE) +
			get_value(NULL, process->r[process->op.arg[1]], REG_SIZE),
			REG_SIZE);
	process->carry = 1;
	if (get_value(NULL, process->r[process->op.arg[2]], REG_SIZE))
		process->carry = 0;
}
