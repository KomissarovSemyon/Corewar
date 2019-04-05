/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:51:42 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/05 02:27:39 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		arg_champ(char *str)
{
	char	*point;

	point = str + ft_strlen(str);
	while (point != str && *point != '.')
		--point;
	if (point == str)
		return (0);
	if (!ft_strcmp(point, ".cor"))
		return (2);
	return (1);
}

static void		arg_num(int i, t_param *p, int argc, char **argv)
{
	if (i >= argc)
		usage();
	if (!ft_strcmp(argv[i - 1], "-dump"))
		p->flag.dump = ft_atoi(argv[i]);
	else if (!ft_strcmp(argv[i - 1], "-step"))
		p->flag.step = ft_atoi(argv[i]);
}

static int		arg1(int i, t_param *p, int argc, char **argv)
{
	if (!ft_strcmp(argv[i], "-help"))
		help();
	else if (!ft_strcmp(argv[i], "-dump"))
		arg_num(++i, p, argc, argv);
	else if (!ft_strcmp(argv[i], "-step"))
		arg_num(++i, p, argc, argv);
	else if (!ft_strcmp(argv[i], "-vis"))
		p->flag.vis = 1;
	else if (!ft_strcmp(argv[i], "-cycle"))
		p->flag.cycle = 1;
	else if (!ft_strcmp(argv[i], "-map"))
		p->flag.map = 1;
	else if (!ft_strcmp(argv[i], "-param"))
		p->flag.param = 1;
	else if (!ft_strcmp(argv[i], "-process"))
		p->flag.process = 1;
	else if (!ft_strcmp(argv[i], "-oper"))
		p->flag.oper = 1;
	else if (!ft_strcmp(argv[i], "-check"))
		p->flag.check = 1;
	else
		usage();
	return (i);
}

static void		players_id(t_param *p)
{
	int		i;
	int		emp[MAX_PLAYERS];

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (p->champs[i].n)
		{
			if (p->champs[i].n > p->players)
				champ_err(p->players, 3, 0, 0);
			else if (p->champs[p->champs[i].n].n == p->champs[i].n)
				champ_err(0, 4, 0, 0);
			swap_champ(p->champs[i],  p->champs[p->champs[i].n]);
		}
		else
			++i;
	}
	i = -1;
	while (++i < MAX_PLAYERS)
		if (!p->champs[i].n)
			p->champs[i].n = i + 1;
}

int				read_args(t_param *p, int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-n"))
		{
			if (i + 3 > argc)
				usage();
			p->champs[p->players].n = ft_atoi(argv[++i]);
			if (arg_champ(argv[++i]) != 2)
				usage();
			get_champ(argv[i], p, p->players++);
			if (p->champs[p->players].n < 0 ||
					p->champs[p->players].n > MAX_PLAYERS)
				help();
		}
		else if (arg_champ(argv[i]) == 2)
			get_champ(argv[i], p, p->players++);
		else
			i = arg1(i, p, argc, argv);
		if (p->players > MAX_PLAYERS)
			help();
	}
	return (0);
}
