/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:47:41 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/01 13:02:07 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


static void		param_init(t_param *p)
{
	int		i;

	p->champ_arg = 0;
	p->players = 0;
	p->flag.comment = 0;
	p->process = NULL;
	p->cycles_to_die = CYCLE_TO_DIE;
	p->current_cycle = 0;
	p->last_check = 0;
	p->live_nbr = 0;
	p->checks = 0;
	p->flag.step = 0;
	p->flag.dump = 0;
	p->flag.vis = 0;
	p->flag.help = 0;
	p->flag.cycle = 0;
	p->flag.map = 0;
	p->flag.param = 0;
	p->flag.process = 0;
	p->flag.oper = 0;
	p->proc_nbr = 0;
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		p->champs[i].file = NULL;
		p->champs[i].n = 0;
	}
}

static void		param_vis(t_param *p)
{
//	p->flag.cycle = 1;
//	p->flag.map = 1;
//	p->flag.param = 1;
//	p->flag.process = 1;
//	p->flag.step = 1;
}

static void		intro(t_param *p)
{
	int		i;

	ft_printf("Introducing contestants...\n");
	i = -1;
	while (++i < p->players)
	{
		ft_printf("* Player %d, weighing ", i + 1);
		ft_printf("%d bytes, \"%s\" ", p->champs[i].champ_size, p->champs[i].name);
		ft_printf("(\"%s\") !\n", p->champs[i].comment);
	}
}

int				main(int argc, char **argv)
{
	t_param		p;
	int			i;
	char		s[4];

	param_init(&p);
	read_args(&p, argc, argv);
	p.winner = p.players - 1;
	if (p.flag.vis)
		param_vis(&p);
	if (p.players == 0)
		usage();
	map_init(&p);
	if (!p.flag.vis)
		intro(&p);
	start_game(&p);
	ft_printf("Contestant %d, \"%s\", has won !\n", p.winner + 1, p.champs[p.winner].name);
	return (0);
}
