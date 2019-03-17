/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lives.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 06:36:38 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/17 06:37:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int
	check_live
	(t_process *p, int pc, unsigned char reg, int expected)
{
	int				result;

	while (pc >= MEM_SIZE)
		pc -= MEM_SIZE;
	p->pc = p->map + pc;
	set_map_pos(p, pc + 1, reg);
	result = op_check(p);
	ft_printf("reg = %2hhx(%2d)\t", reg, reg);
	check_int(expected, result);
	return (1);
}

void
	check_lives
	(void)
{
	t_process	p;

	p = init_process();

	ft_printf("test live:\n");
	p.op.type = 1;
	check_live(&p, 10, 0, 1);
	check_live(&p, 10, 1, 1);
	check_live(&p, 10, 16, 1);
	check_live(&p, 10, 17, 1);
	check_live(&p, MEM_SIZE - 1, 20, 1);
}
