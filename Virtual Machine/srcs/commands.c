/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:05:03 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/06 02:24:31 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_live(t_param *param, t_process *process)
{
	long long	val;

	val = process->op.arg[0];
	process->livin = param->current_cycle;
	if (val < 0 && val >= -param->players)
		param->winner = -1 * val;
	++param->live_nbr;
}

void		op_ld(t_param *param, t_process *process)
{
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
//		ft_printf("%d\n", -1 * get_signed_value(NULL, process->r[0], REG_SIZE));
	}
	else
		set_value(NULL, process->r[process->op.arg[1]], reg, REG_SIZE);
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
	unsigned char	reg[REG_SIZE];
	long long		res;

///	set_value(NULL, reg, process->op.arg[0], REG_SIZE);
//	res = get_signed_value(NULL, reg, REG_SIZE);
//	ft_printf("%x  %x\n", process->op.arg[0], res);
	if (process->carry)
		process->pc = get_step(process->map, process->pc,
				process->op.arg[0] % IDX_MOD);
}

void		op_sti(t_param *param, t_process *process)
{
	long long		l[2];
	int				i;
	unsigned char	*dst;

	i = -1;
	while (++i < 2)
		if (process->op.arg_type[i + 1] == REG_CODE)
			l[i] = get_signed_value(NULL,
						process->r[process->op.arg[i + 1]], REG_SIZE);
		else if (process->op.arg_type[i + 1] == DIR_CODE)
			l[i] = process->op.arg[i + 1];
		else
			l[i] = get_signed_value(process->map,
				(unsigned char *)process->op.arg[i + 1], DIR_SIZE);
	dst = get_step(process->map, process->pc, (l[0] + l[1]) % IDX_MOD);
	set_value(process->map, dst,
			get_value(NULL, process->r[process->op.arg[0]], REG_SIZE), REG_SIZE);
	set_color(param, dst - process->map, REG_SIZE,
				-1 * get_signed_value(NULL, process->r[0], REG_SIZE));
}

void		op_ldi(t_param *param, t_process *process)
{
	long long		l[2];
	int				i;
	unsigned char	*ptr;
	long long		value;

	i = -1;
	while (++i < 2)
		if (process->op.arg_type[i] == DIR_CODE)
			l[i] = process->op.arg[i];
		else if (process->op.arg_type[i] == REG_CODE)
			l[i] = get_signed_value(NULL, process->r[process->op.arg[i]], REG_SIZE);
		else
			l[i] = get_signed_value(process->map,
					(unsigned char *)process->op.arg[i], DIR_SIZE);
	ptr = get_step(process->map, process->pc, (l[0] + l[1]) % IDX_MOD);
	value = get_value(process->map, ptr, REG_SIZE);
	set_value(NULL, process->r[process->op.arg[2]], value, REG_SIZE);
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
	process->carry = 1;
	if (get_value(NULL, process->r[process->op.arg[2]], REG_SIZE))
		process->carry = 0;
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
//	write(1, &c, 1);
}
