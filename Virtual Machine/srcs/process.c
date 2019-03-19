/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:59:06 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/19 09:45:49 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			process_print(t_process *p)
{
	int		i;

	ft_printf("id - %d\n", p->id);
	ft_printf("carry - %d\n", p->carry);
	ft_printf("place - %d\n", p->pc - p->map);
	ft_printf("wait - %d\n", p->wait);
	ft_printf("livin - %d\n", p->livin);
	ft_printf("op_id - %d\n", p->op.id);
	ft_printf("op_id - %d\n", p->op.type);
	i = -1;
	while (++i < 3)
		ft_printf("arg[%d].type - %d\n", i, p->op.arg_type[i]);
	i = -1;
	while (++i < 3)
		ft_printf("arg[%d]e - %d\n", i, p->op.arg[i]);
}

t_process		*process_kill(t_param *p, t_process *die)
{
	t_process	*tmp;

	tmp = p->process;
	if (tmp == die)
	{
		p->process = p->process->next;
		free(die);
		return (p->process);
	}
	while (tmp->next != die)
		tmp = tmp->next;
	tmp->next = die->next;
	free(die);
	return (tmp);
}

void			process_new(t_param *p, t_process *parent, unsigned char *pc)
{
	t_process	*new;

	if (!(new = (t_process *)malloc(sizeof(t_process))))
		malloc_err();
	new->livin = p->current_cycle;
	new->wait = 0;
	new->carry = parent ? parent->carry : 1;
	new->map = p->map;
	new->pc = pc;
	new->op.type = 0;
	new->next = p->process;
	new->id = p->process ? p->process->id + 1 : 1;
	if (parent)
		ft_memcpy(new->r, parent->r, REG_NUMBER * REG_SIZE);
	else
	{
		ft_bzero(new->r, REG_NUMBER * REG_SIZE);
		new->r[0][REG_SIZE - 1] = -1 * new->id;
	}
	p->process = new;
}
