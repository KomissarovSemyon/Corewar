/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:08:46 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/21 17:44:00 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			set_color(t_param *p, int place, int size, int color)
{
	while (size--)
		p->map_color[(place + size) % MEM_SIZE] =
									color < 4 && color > 0 ? color : 0;;
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

void			map_print(t_param *p)
{
	int			line;
	t_process	*tmp;

	line = 0;
	if (p->flag.param)
	{
		ft_printf("current cycle - %d\n", p->current_cycle);
		ft_printf("cycles to die - %d\n", p->cycles_to_die);
		ft_printf("last check - %d\n", p->last_check);
		ft_printf("number of live - %d\n", p->live_nbr);
	}
	if (p->flag.map)
		while (line < MEM_SIZE)
		{
			print_bytes(p, &p->map[line], 32);
			line += 32;
		}
	if (p->flag.vis)
		print_color(p);
	tmp = p->process;
	if (p->flag.process)
		while (tmp)
		{
			process_print(tmp);
			tmp = tmp->next;
		}
}
