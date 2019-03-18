/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 01:25:13 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/18 19:42:16 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		process_act(t_param *param, t_process *process)
{
	if (process->wait == 0)
	{
		if (process->op.type > 0 && process->op.type < 17)
		{
			op_args(process);
			if (g_op_tab[process->op.id].f_check(process))
				g_op_tab[process->op.id].f_do(param, process);
			process->pc = process->op.ptr;
			process->op.type = 0;
		}
		else
		{
			process->op.id = 0;
			process->pc = get_step(process->map, process->pc, 1);
			process->op.type = *process->pc;
			while (process->op.type != g_op_tab[process->op.id].id)
				++process->op.id;
			process->wait = g_op_tab[process->op.id].cycles;
		}
	}
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
			process_act(param, tmp);
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
