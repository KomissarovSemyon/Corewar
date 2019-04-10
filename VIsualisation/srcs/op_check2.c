/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 06:44:43 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/10 06:53:31 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int			part2(t_process *p, int codage)
{
	int		size;

	size = 1;
	if (((codage >> 6) & 3) == 2)
		size = g_op_tab[5].label_size;
	else if (((codage >> 6) & 3) == 3)
		size = 2;
	if (((codage >> 4) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2 + size)))
			return (0);
	size += 1;
	if (((codage >> 4) & 3) == 2)
		size += g_op_tab[5].label_size - 1;
	else if (((codage >> 4) & 3) == 3)
		size += 2 - 1;
	if (((codage >> 2) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2 + size)))
			return (0);
	return (1);
}

static int			part1(t_process *p)
{
	int		codage;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (!((codage >> 2) & 3) || !((codage >> 4) & 3) || !((codage >> 6) & 3))
		return (0);
	if (((codage >> 2) & 3) != 1)
		return (0);
	if (((codage >> 6) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2)))
			return (0);
	return (part2(p, codage));
}

int					op_check_and(t_process *p)
{
	return (part1(p));
}

int					op_check_or(t_process *p)
{
	return (part1(p));
}

int					op_check_xor(t_process *p)
{
	return (part1(p));
}
