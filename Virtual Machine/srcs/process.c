/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:59:06 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/18 12:25:45 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			process_die(t_param *p, t_process *die)
{
	t_process	*tmp;

	tmp = p->process;
	if (tmp == die)
	{
		p->process = p->process->next;
		free(die);
	}
	else
	{
		while (tmp->next != die)
			tmp = tmp->next;
		tmp->next = die->next;
		free(die);
	}
}

void			process_new(t_param *p, t_process *parent, unsigned char *pc)
{
	t_process	*new;
	int			i;

	if (!(new = (t_process *)malloc(sizeof(t_process))))
		malloc_err();
	i = -1;
	new->carry = parent ? parent->carry : 1;
	new->map = p->map;
	new->pc = pc;
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
