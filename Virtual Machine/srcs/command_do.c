/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 22:19:11 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/17 01:07:15 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		do_op(t_param *param, t_process *process)
{
	int		i;
	long	res;
	char	c;

	if (process->op.type == LIVE)
	{
		process->livin = param->current_cycle;
		if (*process->op.arg[0] < 0 && *process->op.arg[0] >=
				-param->players)
			param->winner = -1 * *process->op.arg[0];
	}
	else if (process->op.type == LD || process->op.type == LLD)
	{
		ft_memcpy(process->op.arg[0], process->op.arg[1], REG_SIZE);
		process->carry = 1;
		i = -1;
		while (++i < REG_SIZE)
			if (process->op.arg[1][i])
				process->carry = 0;
	}
	else if (process->op.type == ST)
		ft_memcpy(process->op.arg[1], process->op.arg[0], REG_SIZE);
	else if (process->op.type == ADD)
	{
		res = 0;
		i = REG_SIZE + 1;
		while (--i)
			res += (process->op.arg[0][REG_SIZE - i] + process->op.arg[1][REG_SIZE - i]) << ((i - 1) * 8);
		while (++i <= REG_SIZE)
			process->op.arg[2][REG_SIZE - i] = (res << (56 - i * 8)) >> 56;
	}
	else if (process->op.type == SUB)
	{
		res = 0;
		i = REG_SIZE + 1;
		while (--i)
			res += (process->op.arg[0][REG_SIZE - i] + process->op.arg[1][REG_SIZE - i]) << ((i - 1) * 8);
		while (++i <= REG_SIZE)
			process->op.arg[2][REG_SIZE - i] = (res << (56 - i * 8)) >> 56;	
	}
	else if (process->op.type == AND)
	{
		i = -1;
		process->carry = 1;
		while (++i < REG_SIZE)
			if ((process->op.arg[2][i] = process->op.arg[0][i] & process->op.arg[1][i]))
				process->carry = 1;
	}
	else if (process->op.type == OR)
	{
		i = -1;
		process->carry = 1;
		while (++i < REG_SIZE)
			if ((process->op.arg[2][i] = process->op.arg[0][i] | process->op.arg[1][i]))
				process->carry = 1;
	}
	else if (process->op.type == XOR)
	{
		i = -1;
		process->carry = 1;
		while (++i < REG_SIZE)
			if ((process->op.arg[2][i] = process->op.arg[0][i] ^ process->op.arg[1][i]))
				process->carry = 1;
	}
	else if (process->op.type == ZJMP)
	{
		res = 0;
		i = -1;
		while (++i < DIR_SIZE)
			res = (res << (i * 8)) + process->op.arg[0][i];
		if (process->carry)
			process->pc = get_step(param->map, process->pc, res);
	}
	else if (process->op.type == LDI || process->op.type == LLDI)
		set_value(process->op.arg[2],
			(get_value(process->op.arg[0], DIR_SIZE) +
			 get_value(process->op.arg[0], DIR_SIZE)) % 256 + (long)process->pc, REG_SIZE);
	else if (process->op.type == STI)
		ft_memcpy(process->pc + (get_value(process->op.arg[1], DIR_SIZE) +
			get_value(process->op.arg[2], DIR_SIZE) % 256), process->op.arg[0], REG_SIZE);
	else if (process->op.type == FORK)
		process_new(param, process, process->pc + get_value(process->op.arg[0], DIR_SIZE) % IDX_MOD);
	else if (process->op.type == LFORK)
		process_new(param, process, process->pc + get_value(process->op.arg[0], DIR_SIZE));
	else if (process->op.type == AFF)
	{
		c = get_value(process->op.arg[0], REG_SIZE) % 256;
		write(1, &c, 1);
	}
}
