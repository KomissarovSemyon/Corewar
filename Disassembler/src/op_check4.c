/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_check4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 06:56:13 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/10 17:49:11 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int						op_check_ldi(t_process *p)
{
	int				codage;
	int				size;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (((codage >> 4) & 3) == 3 || ((codage >> 4) & 3) == 0)
		return (0);
	if (((codage >> 2) & 3) != 1)
		return (0);
	if (((codage >> 6) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2)))
			return (0);
	size = 1;
	if (((codage >> 6) & 3) == 2)
		size = g_op_tab[9].label_size;
	else if (((codage >> 6) & 3) == 3)
		size = 2;
	if (((codage >> 4) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2 + size)))
			return (0);
	size += 1;
	if (((codage >> 4) & 3) == 2)
		size += g_op_tab[9].label_size - 1;
	if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2 + size)))
		return (0);
	return (1);
}

int						op_check_lldi(t_process *p)
{
	return (op_check_ldi(p));
}

int						op_check_sti(t_process *p)
{
	int				codage;
	int				size;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (((codage >> 6) & 3) != 1)
		return (0);
	if (((codage >> 2) & 3) == 3 || ((codage >> 2) & 3) == 0)
		return (0);
	if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2)))
		return (0);
	if (((codage >> 4) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 3)))
			return (0);
	size = 1;
	if (((codage >> 4) & 3) == 2)
		size += g_op_tab[10].label_size - 1;
	else if (((codage >> 4) & 3) == 3)
		size += 2 - 1;
	if (((codage >> 2) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 3 + size)))
			return (0);
	return (1);
}
