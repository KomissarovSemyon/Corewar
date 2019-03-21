/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:15:37 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/21 15:15:20 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			champ_err(int value, int f, char *str, int expect)
{
	if (f == 1)
		ft_printf("  can't open %s\n", str);
	else if (f == 2)
		ft_printf("%s is not champion\n", str);
	else if (f == 3)
		ft_printf("There are only %d players\n", value);
	else if (f == 4)
		ft_printf("Duplicate player id\n", value);
	else if (value == -1)
		ft_printf("  can't read %s\n", str);
	else if (value < expect)
		ft_printf("Invalid champion %s\n", str);
	else
		return ;
	exit(0);
}

static void		check_null(char *nul, char *str)
{
	int		i;

	i = -1;
	while (++i < 4)
		if (nul[i] != 0)
			champ_err(0, 0, str, 1);
}

static void		rev_bits(char *str, int len)
{
	int		i;
	char	tmp;

	i = -1;
	while (++i < len)
	{
		tmp = str[i];
		str[i] = str[--len];
		str[len] = tmp;
	}
}

static void		get_champ2(int f, char *str, t_param *p, int id)
{
	if (p->champs[id].champ_size > CHAMP_MAX_SIZE)
		champ_err(0, 0, str, 1);
	champ_err(read(f, p->champs[id].comment, COMMENT_LENGTH), 0, str,
														COMMENT_LENGTH);
	p->champs[id].comment[COMMENT_LENGTH] = '\0';
	champ_err(read(f, p->champs[id].null_term, 4), 0, str, 4);
	check_null(p->champs[id].null_term, str);
	champ_err(read(f, p->champs[id].champ,
			p->champs[id].champ_size), 0, str,
									p->champs[id].champ_size);
	p->champs[id].champ[p->champs[id].champ_size] = '\0';

}

void			get_champ(char *str, t_param *p, int id)
{
	int		f;

	if (!(f = open(str, O_RDONLY)))
		champ_err(0, 1, str, 0);
	champ_err(read(f, &p->champs[id].magic, 4), 0, str, 4);
	rev_bits((char *)&p->champs[id].magic, 4);
	if (p->champs[id].magic != COREWAR_EXEC_MAGIC)
		champ_err(0, 2, str, 0);
	champ_err(read(f, p->champs[id].name, PROG_NAME_LENGTH), 0, str,
														PROG_NAME_LENGTH);
	champ_err(read(f, p->champs[id].null_term, 4), 0, str, 4);
	check_null(p->champs[id].null_term, str);
	p->champs[id].name[PROG_NAME_LENGTH] = '\0';
	champ_err(read(f, &p->champs[id].champ_size, 4), 0, str, 4);
	rev_bits((char *)&p->champs[id].champ_size, 4);
	get_champ2(f, str, p, id);
}
