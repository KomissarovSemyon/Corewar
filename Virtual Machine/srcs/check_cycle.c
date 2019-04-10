/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 07:15:54 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/11 02:41:16 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		do_check(t_param *param)
{
	t_process	*pr;

	if (!param->flag.cycle && param->flag.check &&
			param->current_cycle > param->flag.start)
		ft_printf("current cycle is %d\n", param->current_cycle);
	if (param->flag.check && param->current_cycle > param->flag.start)
	{
		ft_printf("last check was at %d\n", param->last_check);
		ft_printf("cycles to die is  %d\n", param->cycles_to_die);
	}
	param->last_check = param->current_cycle;
	pr = param->process;
	while (pr)
	{
		if (param->flag.check && param->current_cycle > param->flag.start)
			ft_printf("process %d last live at %d\n", pr->id, pr->livin);
		if (pr->livin <= param->current_cycle - param->cycles_to_die)
		{
			if (param->flag.check && param->current_cycle > param->flag.start)
				ft_printf("kill process %d\n", pr->id);
			pr = process_kill(param, pr);
		}
		else
			pr = pr->next;
	}
}

int				check_cycle(t_param *param)
{
	if (param->current_cycle >= param->last_check + param->cycles_to_die)
	{
		do_check(param);
		if (param->flag.check && param->current_cycle > param->flag.start)
		{
			ft_printf("current_check is %d\n", 1 + param->checks);
			ft_printf("number of live %d\n", param->live_nbr);
		}
		if (!param->process)
			return (0);
		if (++param->checks == MAX_CHECKS || param->live_nbr >= NBR_LIVE)
		{
			param->cycles_to_die -= CYCLE_DELTA;
			if (param->flag.check)
				ft_printf("cycles to die is now %d\n", param->cycles_to_die);
			param->checks = 0;
		}
		param->live_nbr = 0;
		if (param->flag.check && param->current_cycle > param->flag.start)
			ft_printf("\n");
	}
	return (1);
}
