/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 22:19:11 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/16 02:41:52 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		do_op(t_param *param, t_process *process)
{
	if (process->op.type == LIVE)
	{
		process->livin = param->current_cycle;
		if (*process->op.arg[0] < 0 && *process->op.arg[0] >=
				-param->players)
			param->winner = -1 * *process->op.arg[0];
	}
	else if (process->op.type == LD)
		;
	else if (process->op.type == ST)
		;
	else if (process->op.type == ADD)
		;
	else if (process->op.type == SUB)
		;
	else if (process->op.type == AND)
		;
	else if (process->op.type == OR)
		;
	else if (process->op.type == XOR)
		;
	else if (process->op.type == ZJMP)
		;
	else if (process->op.type == LDI)
		;
	else if (process->op.type == STI)
		;
	else if (process->op.type == FORK)
		;
	else if (process->op.type == LLD)
		;
	else if (process->op.type == LLDI)
		;
	else if (process->op.type == LFORK)
		;
	else if (process->op.type == AFF)
		;
}
