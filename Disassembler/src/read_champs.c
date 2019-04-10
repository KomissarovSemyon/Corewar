/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:15:37 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/10 22:49:50 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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

static int		champ_check(unsigned char *start, int size)
{
	t_process	proc;

	proc.pc = start;
	proc.map = start;
	while (proc.pc < start + size)
	{
		proc.op.id = *proc.pc - 1;
		op_args(&proc);
		if (!op_check(&proc))
			return (1);
		proc.pc = proc.op.ptr;
	}
	return (proc.pc == start + size ? 0 : 1);
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
	if (champ_check((unsigned char *)p->champs[id].champ,
										p->champs[id].champ_size))
		champ_err(0, 5, str, 0);
	close(f);
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
