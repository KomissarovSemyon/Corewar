/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:05:03 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/18 19:58:01 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_live(t_param *param, t_process *process)
{
	process->livin = param->current_cycle;
	if (process->op.arg[0] < 0 && process->op.arg[0] >= -param->players)
		param->winner = -1 * process->op.arg[0];
}

void		op_ld(t_param *param, t_process *process)
{
	process_print(process);
	ft_printf("sha ebanet\n");
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
	ft_memcpy((void *)process->op.arg[1],
			(const void *)process->op.arg[0], REG_SIZE);
	if (process->op.arg_type[1] == IND_CODE)
		set_value(process->map, (unsigned char *)process->op.arg[1],
		get_value(NULL, process->r[process->op.arg[0]], REG_SIZE),
														REG_SIZE);
	else
		set_value(process->map, process->r[process->op.arg[1]],
		get_value(NULL, process->r[process->op.arg[0]], REG_SIZE),
														REG_SIZE);
}

void		op_add(t_param *param, t_process *process)
{
	set_value(NULL, process->r[process->op.arg[2]],
			get_value(NULL, process->r[process->op.arg[0]], REG_SIZE) +
			get_value(NULL, process->r[process->op.arg[1]], REG_SIZE),
			REG_SIZE);
	process->carry = 1;
	if (get_value(NULL, process->r[process->op.arg[2]], REG_SIZE))
		process->carry = 0;
}

void		op_sub(t_param *param, t_process *process)
{
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
	if (process->carry)
		process->pc = get_step(process->map, process->pc,
				process->op.arg[0] % IDX_MOD);
}

void		op_sti(t_param *param, t_process *process)
{
	long long	l[2];
	int			i;

	i = -1;
	while (++i < 2)
		if (process->op.arg_type[i + 1] == REG_CODE)
			l[i] = get_value(NULL, process->r[process->op.arg[i + 1]], REG_SIZE);
		else if (process->op.arg_type[i + 1] == DIR_CODE)
			l[i] = process->op.arg[i + 1];
		else
			l[i] = get_value(process->map,
				(unsigned char *)process->op.arg[i + 1], DIR_SIZE);
	set_value(process->map,
			get_step(process->map, process->pc, (l[0] + l[1]) % IDX_MOD),
			get_value(NULL, process->r[process->op.arg[2]], REG_SIZE), REG_SIZE);
}

void		op_ldi(t_param *param, t_process *process)
{
	long long	l[2];
	int			i;

	i = -1;
	while (++i < 2)
		if (process->op.arg_type[i] == DIR_CODE)
			l[i] = process->op.arg[i];
		else if (process->op.arg_type[i] == REG_CODE)
			l[i] = get_value(NULL, process->r[process->op.arg[i]], REG_SIZE);
		else
			l[i] = get_value(process->map,
					(unsigned char *)process->op.arg[i], DIR_SIZE);
	set_value(NULL, process->r[process->op.arg[2]], (l[0] + l[1]) % IDX_MOD, REG_SIZE);
}

void		op_lldi(t_param *param, t_process *process)
{
	long long	l[2];
	int			i;

	i = -1;
	while (++i < 2)
		if (process->op.arg_type[i] == DIR_CODE)
			l[i] = process->op.arg[i];
		else if (process->op.arg_type[i] == REG_CODE)
			l[i] = get_value(NULL, process->r[process->op.arg[i]], REG_SIZE);
		else
			l[i] = get_value(process->map,
					(unsigned char *)process->op.arg[i], DIR_SIZE);
	set_value(NULL, process->r[process->op.arg[2]], (l[0] + l[1]), REG_SIZE);
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

	c = (char)get_value(NULL, process->r[process->op.arg[0]], REG_SIZE);
	write(1, &c, 1);
}
