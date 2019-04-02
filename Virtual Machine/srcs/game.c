/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 01:25:13 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/01 17:20:13 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		do_op(t_param *param, t_process *process)
{
	op_args(process);
//	if (process->id == 84)
//	{
//		ft_fprintf(2, "%d\n", process->id);
//		process_print(process);
//	}
	if (param->flag.oper)
		ft_printf("cycle - %d\n", param->current_cycle);
	if (op_check(process))
	{
//		if (process->id == 84)
//			ft_fprintf(2, "check - ok\n");
		if (param->flag.oper)
			ft_printf("process %d executing %s\n", process->id,
												g_op_tab[process->op.id].name);
		g_op_tab[process->op.id].f_do(param, process);
	}
	else if (param->flag.oper)
		ft_printf("process %d failed %s\n", process->id,
												g_op_tab[process->op.id].name);
	if (param->flag.oper)
		ft_printf("moving to %d\n\n", process->op.ptr - process->map);
	if (!(process->op.id == ZJMP && process->carry && op_check(process)))
		process->pc = process->op.ptr;
}

static void		process_act(t_param *param, t_process *process)
{
	if (process->wait == -1)
	{
		process->op.id = *process->pc - 1;
		if (process->op.id > 15)
			process->wait = 0;
		else// if (op_check(process))
			process->wait = g_op_tab[process->op.id].cycles - 1;
//		else
//			process->wait = 1;
	}
	if (process->wait == 0)
	{
//		ft_fprintf(2, "sega posle pid %d\n", process->id);
		if (process->op.id < 16)
			do_op(param, process);
		else
			process->pc = get_step(process->map, process->pc, 1);
	}
	--process->wait;
}

static int		check_cycle(t_param *param)
{
	t_process	*pr;

	if (++param->current_cycle > param->last_check + CYCLE_TO_DIE)
	{
		param->last_check = param->current_cycle;
		pr = param->process;
		while (pr)
		{
			if (pr->livin <= param->current_cycle - CYCLE_TO_DIE)
				pr = process_kill(param, pr);
			else
				pr = pr->next;
		}
		if (!param->process)
			return (0);
		if (++param->checks == MAX_CHECKS || param->live_nbr >= NBR_LIVE)
		{
			param->cycles_to_die -= CYCLE_DELTA;
			param->checks = 0;
		}
		param->live_nbr = 0;
	}
	return (1);
}

void			start_game(t_param *param)
{
	t_process	*tmp;
	char		c = 0;

	while (check_cycle(param))
	{
		tmp = param->process;
		if (param->flag.cycle)
			ft_printf("cycle - %d\n", param->current_cycle);
		while (tmp)
		{
			process_act(param, tmp);
			tmp = tmp->next;
		}
		if (param->flag.vis && (param->current_cycle > 14000))
			vis_print(param);
		else
		{
			if (param->current_cycle == param->flag.dump)
			{
				param->flag.map = 1;
				map_print(param);
				exit(0);
			}
			if (param->flag.step && !(param->current_cycle % param->flag.step))
				map_print(param);
		}
		c = 0;
	}
//	if (param->current_cycle == param->flag.dump)
//	{
//		param->flag.map = 1;
//		map_print(param);
//	}
}
