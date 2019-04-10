/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 01:25:13 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/10 07:47:29 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		op_show(t_process *process)
{
	unsigned char	*ptr;
	int				i;

	ft_printf("process %d:\n", process->id);
	ptr = process->pc;
	i = -1;
	while (++i < 16)
	{
		ft_printf("%02hhx ", *ptr);
		ptr = get_step(process->map, ptr, 1);
	}
	ft_printf("\n%s ", g_op_tab[process->op.id].name);
	i = 0;
	while (i < 3 && process->op.arg_type[i])
	{
		if (process->op.arg_type[i] == DIR_CODE)
			ft_printf("%ld (%d) ", process->op.arg[i],
										process->op.arg[i] % IDX_MOD);
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
	if (param->flag.oper && param->current_cycle > param->flag.start)
		op_show(process);
	if (op_check(process))
		g_op_tab[process->op.id].f_do(param, process);
	else if (param->flag.oper && param->current_cycle > param->flag.start)
		ft_printf("process %d invalid args for  %s\n", process->id,
											g_op_tab[process->op.id].name);
	if (param->flag.oper && param->current_cycle > param->flag.start)
		ft_printf("step on %d to %02hhx\n\n", process->op.ptr > process->pc ?
		process->op.ptr - process->pc :
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
		else
			process->wait = g_op_tab[process->op.id].cycles - 1;
	}
	if (process->wait == 0)
	{
		if (process->op.id < 16)
			do_op(param, process);
		else
			process->pc = get_step(process->map, process->pc, 1);
	}
	--process->wait;
}

static void		game_output(t_param *param)
{
	if (param->flag.vis)
	{
		if (param->current_cycle > param->flag.start ||
					param->current_cycle == 1)
			vis_print(param);
	}
	else if (param->flag.dump &&
				param->current_cycle == param->flag.dump)
	{
		param->flag.map = 1;
		map_print(param);
		exit(0);
	}
	else if (param->current_cycle > param->flag.start)
		map_print(param);
}

void			start_game(t_param *param)
{
	t_process	*tmp;
	char		c;
	int			flag;

	flag = 1;
	while (flag)
	{
		++param->current_cycle;
		tmp = param->process;
		if (param->flag.cycle && param->current_cycle > param->flag.start)
			ft_printf("cycle - %d\n", param->current_cycle);
		while (tmp)
		{
			process_act(param, tmp);
			tmp = tmp->next;
		}
		game_output(param);
		c = 0;
		if (param->flag.step && !(param->current_cycle % param->flag.step))
			while (c != '\n')
				read(0, &c, 1);
		flag = check_cycle(param);
	}
}
