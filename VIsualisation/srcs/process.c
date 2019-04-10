/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:59:06 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/07 16:08:47 by jcorwin          ###   ########.fr       */
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
	if (p->op.id < 15)
		ft_printf("op - %s\n", g_op_tab[p->op.id].name);
	else
		ft_printf("op - step\n");
	i = -1;
	while (++i < 3)
		ft_printf("arg[%d].type - %d\n", i, p->op.arg_type[i]);
	i = -1;
	while (++i < 3)
		ft_printf("arg[%d]e - %d\n", i, p->op.arg[i]);
	ft_printf("\n");
}

t_process		*process_kill(t_param *p, t_process *die)
{
	t_process	*tmp;

	tmp = p->process;
	--p->proc_nbr;
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

static void		process_init(t_param *p, t_process *new, unsigned char *pc)
{
	new->wait = -1;
	new->map = p->map;
	new->pc = pc;
	new->op.ptr = pc;
	new->op.next_id = *pc - 1;
	new->op.id = new->op.next_id;
	ft_bzero(new->r, REG_NUMBER * REG_SIZE);
	set_value(NULL, new->r[0], -1 * new->id, REG_SIZE);
}

void			process_new(t_param *p, t_process *parent, unsigned char *pc)
{
	t_process	*new;

	if (!(new = (t_process *)malloc(sizeof(t_process))))
		malloc_err();
	new->id = p->process ? p->process->id + 1 : 1;
	if (!parent)
		p->winner = new->id;
	process_init(p, new, pc);
	new->carry = parent ? parent->carry : 0;
	new->livin = parent ? parent->livin : 0;
	new->next = p->process;
	if (parent)
		ft_memcpy(new->r, parent->r, REG_NUMBER * REG_SIZE);
	p->process = new;
	++p->proc_nbr;
}
