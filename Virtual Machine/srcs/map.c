/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:08:46 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/10 22:11:30 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			set_color(t_param *p, int place, int size, int color)
{
	while (size--)
	{
		if (color <= p->players && color > 0)
		{
			p->map_color[(place + size) % MEM_SIZE] = color + 4;
			p->map_color_cycle[(place + size) % MEM_SIZE] = 10;
		}
		else
			p->map_color[(place + size) % MEM_SIZE] = 0;
	}
}

static void		color_old(t_param *p)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
		if (p->map_color[i] > 4 && p->map_color[i] < 9)
			if (!(--p->map_color_cycle[i]))
				p->map_color[i] -= 4;
}

void			vis_print(t_param *p)
{
	t_process	*tmp;
	int			magic;
	long long	val;

	magic = VIS_MAGIC;
	write(1, &magic, sizeof(int));
	tmp = p->process;
	ft_bzero(&p->player_proc_nbr, sizeof(int) * 4);
	while (tmp)
	{
		val = get_signed_value(NULL, tmp->r[0], REG_SIZE);
		if (val < 0 && val >= -p->players)
			p->player_proc_nbr[-val - 1] += 1;
		tmp = tmp->next;
	}
	write(1, p, sizeof(t_param));
	tmp = p->process;
	while (tmp)
	{
		write(1, tmp, sizeof(t_process));
		tmp = tmp->next;
	}
	color_old(p);
}

static void		map_dump(t_param *p)
{
	int		line;

	line = 0;
	while (line < MEM_SIZE)
	{
		if (line == 0)
			ft_printf("0x");
		ft_printf("%#.4x : ", line);
		print_bytes(p, &p->map[line], 32);
		line += 32;
		ft_printf("\n");
	}
}

void			map_print(t_param *p)
{
	t_process	*tmp;

	if (p->current_cycle != p->flag.dump)
	{
		if (!p->flag.cycle && p->flag.process)
			ft_printf("%{02:00}cycle - %d%{99:99}\n\n", p->current_cycle);
		else if (!p->flag.cycle && (p->flag.map || p->flag.oper))
			ft_printf("cycle - %d\n\n", p->current_cycle);
	}
	if (p->flag.map)
		map_dump(p);
	tmp = p->process;
	if (p->flag.process)
		while (tmp)
		{
			process_print(tmp);
			tmp = tmp->next;
		}
}
