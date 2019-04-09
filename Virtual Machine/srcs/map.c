/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:08:46 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/09 17:57:05 by jcorwin          ###   ########.fr       */
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

void			map_init(t_param *p)
{
	int		i;
	int		step;

	i = -1;
	while (++i <= MEM_SIZE)
	{
		p->map[i] = 0;
		p->map_color[i] = 0;
	}
	step = MEM_SIZE / p->players;
	i = -1;
	while (++i < p->players)
	{
		ft_memcpy(&p->map[i * step], p->champs[i].champ,
											p->champs[i].champ_size);
		set_color(p, i * step, p->champs[i].champ_size, i + 1);
		process_new(p, NULL, &p->map[i * step]);
	}
}

static void		print_bytes(t_param *p, unsigned char *str, int len)
{
	if (len == 0)
		len = ft_strlen((char *)str);
	while (len--)
	{
		if (*str < 16)
			ft_printf("0");
			ft_printf("%hhx ", *str++);
	}
	if (!p->flag.vis)
		ft_printf("\n");
}

static void		print_color(t_param *p)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
		ft_printf("%d ", p->map_color[i]);
}

void			vis_print(t_param *p)
{
	 t_process	*tmp;
	 int		magic;
	 int		i;
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
	i = -1;
	while (++i < MEM_SIZE)
		if (p->map_color[i] > 4 && p->map_color[i] < 9)
			if (!(--p->map_color_cycle[i]))
				p->map_color[i] -= 4;
}

void			map_print(t_param *p)
{
	int			line;
	t_process	*tmp;

	line = 0;
	if (!p->flag.cycle && p->flag.process)
		 ft_printf("%{02:00}cycle - %d%{99:99}\n\n", p->current_cycle);
	else if (!p->flag.cycle && (p->flag.map || p->flag.oper))
		ft_printf("cycle - %d\n\n", p->current_cycle);
	if (p->flag.map)
	{
		while (line < MEM_SIZE)
		{
			if (line == 0)
				ft_printf("0x");
			ft_printf("%#.4x : ", line);
			print_bytes(p, &p->map[line], 64);
			line += 64;
		}
		ft_printf("\n");
	}
	tmp = p->process;
	if (p->flag.process)
		while (tmp)
		{
			process_print(tmp);
			tmp = tmp->next;
		}
}
