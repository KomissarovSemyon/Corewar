/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 22:19:11 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/18 18:25:51 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		do_op(t_param *param, t_process *process)
{
	int		i;

	i = 0;
	while (g_op_tab[i].id != process->op.type)
		++i;
	op_args(process);
	if (g_op_tab[i].f_check(process))
		g_op_tab[i].f_do(param, process);
	process->pc = process->op.ptr;
	process->op.type = 0;
}
