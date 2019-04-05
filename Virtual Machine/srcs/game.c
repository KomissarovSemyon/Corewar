/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 01:25:13 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/05 08:21:49 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		op_show(t_process *process)
{
	unsigned char	*ptr;
	int				i;
	long long		value;

	ft_printf("process %d:\n", process->id);
	ptr = process->pc;
	i = -1;
	while (++i < 16)
	{
		ft_printf("%02hhx ", *ptr);
		ptr = get_step(process->map, ptr, 1);
	}
	ft_printf("\n");
	ft_printf("%s ", g_op_tab[process->op.id].name);
	i = 0;
	while (i < 3 && process->op.arg_type[i])
	{
//		ft_printf("%d\n", i);
		if (process->op.arg_type[i] == DIR_CODE)
			ft_printf("%ld (%d) ", process->op.arg[i], process->op.arg[i] % IDX_MOD);
		else if (process->op.arg_type[i] == IND_CODE)
			ft_printf("%ld ", process->op.arg[i] - (long)process->pc);
		else
			ft_printf("r%ld ", process->op.arg[i] + 1);
		++i;
	}
	ft_printf("\n");
}

static void		do_op(t_param *param, t_process *process)
{
	op_args(process);
	if (param->flag.oper && !param->flag.cycle)
		ft_printf("cycle - %d\n", param->current_cycle);
	if (param->flag.oper)
		op_show(process);
	if (op_check(process))
	{
//		if (param->flag.oper)
//			ft_printf("process %d executing %s\n", process->id,
//												g_op_tab[process->op.id].name);
		
		g_op_tab[process->op.id].f_do(param, process);
	}
	else if (param->flag.oper)
		ft_printf("process %d invalid args for  %s\n", process->id,
												g_op_tab[process->op.id].name);
	if (param->flag.oper)
//		ft_printf("moving to %d %hhx\n\n", process->op.ptr - process->map,
//						*process->op.ptr);
		ft_printf("step on %d to %hhx\n\n", 
			process->op.ptr > process->pc ? process->op.ptr - process->pc :
			MEM_SIZE - (long)process->pc + (long)process->op.ptr, *process->op.ptr);
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

	if (param->flag.check)
	{
		ft_printf("last check was at %d\n", param->last_check);
		ft_printf("current cycle is %d\n", param->current_cycle);
		ft_printf("number of live %d\n", param->live_nbr);
		ft_printf("next check at %d\n", param->last_check + param->cycles_to_die);
		pr = param->process;
		while (pr)
		{
			ft_printf("process %d last live at %d\n", pr->id, pr->livin);
			pr = pr->next;
		}
		ft_printf("\n", param->current_cycle);
	}
	if (param->current_cycle >= param->last_check + param->cycles_to_die)
	{
//		if (param->flag.check)
//			ft_printf("check:\n");
//		if (!param->flag.cycle && param->flag.check)
//			ft_printf("cycle - %d\n", param->current_cycle);
		param->last_check = param->current_cycle;
		pr = param->process;
		while (pr)
		{
			if (pr->livin <= param->current_cycle - param->cycles_to_die)
			{
//				if (param->flag.check)
//					ft_printf("kill process %d\n", param->process->id);
				pr = process_kill(param, pr);
			}
			else
				pr = pr->next;
		}
		if (param->flag.check)
			ft_printf("\n");
		if (!param->process)
			return (0);
//		ft_printf("number of live %d\n", param->live_nbr);
		if (++param->checks == MAX_CHECKS || param->live_nbr >= NBR_LIVE)
		{
//			ft_printf("%d\n", param->cycles_to_die);
			param->cycles_to_die -= CYCLE_DELTA;
//			ft_printf("%d\n", param->cycles_to_die);
			param->checks = 0;
		}
//		ft_printf("\n");
		param->live_nbr = 0;
	}
	return (1);
}

void			start_game(t_param *param)
{
	t_process	*tmp;
	char		c = 0;
	int			flag;

	flag = 1;
	while (flag)
	{
		++param->current_cycle;
		tmp = param->process;
		if (param->flag.cycle)
			ft_printf("cycle - %d\n", param->current_cycle);
		while (tmp)
		{
			process_act(param, tmp);
			tmp = tmp->next;
		}
		if (param->flag.vis && (param->current_cycle > 0))
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
		flag = check_cycle(param);
	}
//	if (param->current_cycle == param->flag.dump)
//	{
//		param->flag.map = 1;
//		map_print(param);
//	}
}
