/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 05:00:08 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/10 17:46:46 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_sub(t_param *param, t_process *process)
{
	(void)param;
	set_value(NULL, process->r[process->op.arg[2]],
			get_value(NULL, process->r[process->op.arg[0]], REG_SIZE) -
			get_value(NULL, process->r[process->op.arg[1]], REG_SIZE),
			REG_SIZE);
	process->carry = 1;
	if (get_value(NULL, process->r[process->op.arg[2]], REG_SIZE))
		process->carry = 0;
}

void		op_and(t_param *param, t_process *process)
{
	int			i;
	long long	l[2];

	i = -1;
	(void)param;
	while (++i < 2)
		if (process->op.arg_type[i] == DIR_CODE)
			l[i] = process->op.arg[i];
		else if (process->op.arg_type[i] == REG_CODE)
			l[i] = get_value(NULL, process->r[process->op.arg[i]], REG_SIZE);
		else
			l[i] = get_value(process->map,
					(unsigned char *)process->op.arg[i], DIR_SIZE);
	set_value(NULL, process->r[process->op.arg[2]], l[0] & l[1], REG_SIZE);
	process->carry = 1;
	if (get_value(NULL, process->r[process->op.arg[2]], REG_SIZE))
		process->carry = 0;
}

void		op_or(t_param *param, t_process *process)
{
	int			i;
	long long	l[2];

	i = -1;
	(void)param;
	while (++i < 2)
		if (process->op.arg_type[i] == DIR_CODE)
			l[i] = process->op.arg[i];
		else if (process->op.arg_type[i] == REG_CODE)
			l[i] = get_value(NULL, process->r[process->op.arg[i]], REG_SIZE);
		else
			l[i] = get_value(process->map,
					(unsigned char *)process->op.arg[i], DIR_SIZE);
	set_value(NULL, process->r[process->op.arg[2]], l[0] | l[1], REG_SIZE);
	process->carry = 1;
	if (get_value(NULL, process->r[process->op.arg[2]], REG_SIZE))
		process->carry = 0;
}

void		op_xor(t_param *param, t_process *process)
{
	int			i;
	long long	l[2];

	i = -1;
	(void)param;
	while (++i < 2)
		if (process->op.arg_type[i] == DIR_CODE)
			l[i] = process->op.arg[i];
		else if (process->op.arg_type[i] == REG_CODE)
			l[i] = get_value(NULL, process->r[process->op.arg[i]], REG_SIZE);
		else
			l[i] = get_value(process->map,
					(unsigned char *)process->op.arg[i], DIR_SIZE);
	set_value(NULL, process->r[process->op.arg[2]], l[0] ^ l[1], REG_SIZE);
	process->carry = 1;
	if (get_value(NULL, process->r[process->op.arg[2]], REG_SIZE))
		process->carry = 0;
}

void		op_zjmp(t_param *param, t_process *process)
{
	(void)param;
	if (process->carry)
		process->pc = get_step(process->map, process->pc,
				process->op.arg[0] % IDX_MOD);
}
