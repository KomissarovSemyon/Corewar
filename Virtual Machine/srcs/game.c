/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 01:25:13 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/18 13:28:21 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		set_wait(t_process *p)
{
	if (p->op.type == AFF)
		p->wait = 2;
	else if (p->op.type == LD || p->op.type == ST)
		p->wait = 5;
	else if (p->op.type == AND || p->op.type == OR || p->op.type == XOR)
		p->wait = 6;
	else if (p->op.type == LIVE || p->op.type == SUB
			|| p->op.type == ADD || p->op.type == LLD)
		p->wait = 10;
	else if (p->op.type == ZJMP)
		p->wait = 20;
	else if (p->op.type == LDI || p->op.type == STI)
		p->wait = 25;
	else if (p->op.type == LLDI)
		p->wait = 50;
	else if (p->op.type == FORK)
		p->wait = 800;
	else if (p->op.type == LFORK)
		p->wait = 1000;
}

static void		process_move(t_param *param, t_process *process)
{
	if (process->wait == 0)
	{
		if (process->op.type > 0 && process->op.type < 17)
		{
//			if (op_check(process))
//			{
				process->step = 0;
				op_args(process);
				do_op(param, process);
				process->pc = process->op.ptr;
				process->op.type = 0;
//			}
//			else
//				process->pc = get_step(process->map, process->pc, 1);
			process->pc = process->op.ptr;
		}
		else
		{
			process->pc = get_step(process->map, process->pc, 1);
			process->op.type = *process->pc;
			set_wait(process);
		}
	}
	else
		--process->wait;
}

void			start_game(t_param *param)
{
	t_process	*tmp;
	char		c = 0;

	while (param->process)
	{
		tmp = param->process;
		while (tmp)
		{
			process_move(param, tmp);
			tmp = tmp->next;
		}
		++param->current_cycle;
		ft_printf("cycle - %d\n", param->current_cycle);
		map_print(param);
		while (c != '\n')
			read(0, &c, 1);
		c = 0;
	}
}
