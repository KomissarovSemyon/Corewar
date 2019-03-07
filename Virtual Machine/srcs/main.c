/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:47:41 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/08 02:36:58 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		param_init(t_param *p)
{
	p->champ_arg = 0;
	p->champs = NULL;
	p->flag.comment = 0;
	p->flag.step = 0;
	p->flag.verb = 0;
	p->flag.mode = 0;
}

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

static int		get_arg2(char *str, t_param *p)
{
	if (!ft_strcmp(str, "-n"))
	{
		if (p->flag.step)
			return (1);
		p->flag.mode = NCURSES_MODE;
	}
	else if (!ft_strcmp(str, "-vis"))
	{
		if (p->flag.step)
			return (1);
		p->flag.mode = VIS_MODE;
	}
	else if (!ft_strcmp(str, "-help"))
		help();
	else
		return (1);
	return (0);
}

static int		get_arg(int *i, int argc, char **argv, t_param *p)
{
	if (!ft_strcmp(argv[*i], "-a"))
		p->flag.comment = 1;
	else if (!ft_strcmp(argv[*i], "-d"))
	{
		if (p->flag.step)
			return (1);
		p->flag.mode = DUMP_MODE;
		if (++(*i) == argc)
			usage();
		p->flag.step = ft_atoi(argv[*i]);
	}
	else if (!ft_strcmp(argv[*i], "-s"))
	{
		if (p->flag.step)
			return (1);
		p->flag.mode = STEP_MODE;
		if (++(*i) == argc)
			usage();
		p->flag.step = ft_atoi(argv[*i]);
	}
	else
		return (get_arg2(argv[*i], p));
	return (0);
}

int				main(int argc, char **argv)
{
	t_param		p;
	int			i;
	int			f;

	param_init(&p);
	i = 0;
	while (++i < argc)
		if ((f = arg_champ(argv[i])))
			break ;
		else if ((f = get_arg(&i, argc, argv, &p)))
			break ;
	while (i < argc && f == 2)
		if ((f = arg_champ(argv[i])) == 2)
			f = get_champ(argv[i++], &p);
		else
			break ;
	if (i != argc || argc == 1 || f != 2)
		usage();
	return (0);
}
