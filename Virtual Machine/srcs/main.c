/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:47:41 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/10 17:44:25 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				print_bytes(t_param *p, unsigned char *str, int len)
{
	(void)p;
	if (len == 0)
		len = ft_strlen((const char *)str);
	while (len--)
	{
		if (*str < 16)
			ft_printf("0");
		ft_printf("%hhx ", *str++);
	}
	ft_printf("\n");
}

static void			map_init(t_param *p)
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

static void			param_init(t_param *p)
{
	int		tmp;

	p->cycles_to_die = CYCLE_TO_DIE;
	p->winner = p->players - 1;
	if (p->flag.vis)
	{
		tmp = p->flag.start;
		ft_bzero((void *)&p->flag, sizeof(t_flags));
		p->flag.vis = 1;
		p->flag.start = tmp;
	}
	map_init(p);
}

static void			intro(t_param *p)
{
	int		i;

	ft_printf("Introducing contestants...\n");
	i = -1;
	while (++i < p->players)
	{
		ft_printf("* Player %d, weighing ", i + 1);
		ft_printf("%d bytes, \"%s\" ", p->champs[i].champ_size,
													p->champs[i].name);
		ft_printf("(\"%s\") !\n", p->champs[i].comment);
	}
}

int					main(int argc, char **argv)
{
	t_param		p;
	int			magic;

	ft_bzero((void *)&p, sizeof(t_param));
	read_args(&p, argc, argv);
	if (p.players == 0)
		usage();
	param_init(&p);
	if (!p.flag.vis)
		intro(&p);
	start_game(&p);
	if (p.flag.vis)
	{
		magic = VIS_STOP;
		write(1, &magic, sizeof(int));
	}
	ft_printf("Contestant %d, \"%s\", has won !\n", p.winner,
											p.champs[p.winner - 1].name);
	return (0);
}
