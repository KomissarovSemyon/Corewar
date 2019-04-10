/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 05:01:27 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/10 17:47:05 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_sti(t_param *param, t_process *process)
{
	long long		l[2];
	int				i;
	unsigned char	*dst;

	i = -1;
	while (++i < 2)
		if (process->op.arg_type[i + 1] == REG_CODE)
			l[i] = get_signed_value(NULL,
						process->r[process->op.arg[i + 1]], REG_SIZE);
		else if (process->op.arg_type[i + 1] == DIR_CODE)
			l[i] = process->op.arg[i + 1];
		else
			l[i] = get_signed_value(process->map,
				(unsigned char *)process->op.arg[i + 1], DIR_SIZE);
	dst = get_step(process->map, process->pc, (l[0] + l[1]) % IDX_MOD);
	set_value(process->map, dst, get_value(NULL,
				process->r[process->op.arg[0]], REG_SIZE), REG_SIZE);
	set_color(param, dst - process->map, REG_SIZE,
				-1 * get_signed_value(NULL, process->r[0], REG_SIZE));
}

void		op_ldi(t_param *param, t_process *process)
{
	long long		l[2];
	int				i;
	unsigned char	*ptr;
	long long		value;

	(void)param;
	i = -1;
	while (++i < 2)
		if (process->op.arg_type[i] == DIR_CODE)
			l[i] = process->op.arg[i];
		else if (process->op.arg_type[i] == REG_CODE)
			l[i] = get_signed_value(NULL,
					process->r[process->op.arg[i]], REG_SIZE);
		else
			l[i] = get_signed_value(process->map,
					(unsigned char *)process->op.arg[i], DIR_SIZE);
	ptr = get_step(process->map, process->pc, (l[0] + l[1]) % IDX_MOD);
	value = get_value(process->map, ptr, REG_SIZE);
	set_value(NULL, process->r[process->op.arg[2]], value, REG_SIZE);
}

void		op_lldi(t_param *param, t_process *process)
{
	long long	l[2];
	int			i;

	(void)param;
	i = -1;
	while (++i < 2)
		if (process->op.arg_type[i] == DIR_CODE)
			l[i] = process->op.arg[i];
		else if (process->op.arg_type[i] == REG_CODE)
			l[i] = get_value(NULL, process->r[process->op.arg[i]], REG_SIZE);
		else
			l[i] = get_value(process->map,
					(unsigned char *)process->op.arg[i], DIR_SIZE);
	set_value(NULL, process->r[process->op.arg[2]], (l[0] + l[1]), REG_SIZE);
	process->carry = 1;
	if (get_value(NULL, process->r[process->op.arg[2]], REG_SIZE))
		process->carry = 0;
}
