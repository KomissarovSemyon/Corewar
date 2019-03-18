/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 22:19:11 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/18 13:44:02 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		do_op(t_param *param, t_process *process)
{
	int		i;

	i = 0;
	while (g_op_tab[i].id != process->op.type)
		++i;
	g_op_tab[i].fun(param, process);
}
