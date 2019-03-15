/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:59:06 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/15 19:07:56 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			process_free(t_param *p)
{
	t_process	*prev;
	t_process	*cur;

	cur = p->process;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		free(prev);
	}
	p->process = NULL;
}

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

void			process_new(t_param *p, t_process *parent)
{
	t_process	*new;

	if (!(new = (t_process *)malloc(sizeof(t_process))))
		malloc_err();
	new->next = p->process;
	new->id = p->process ? p->process->id + 1 : 1;
	ft_memcpy(&new->r[0], &parent->r[0], REG_SIZE);
	p->process = new;
}
