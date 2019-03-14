/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:15:37 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/13 19:01:33 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		champ_err(int f, char *str)
{
	if (f == 1)
		ft_printf("  can't open %s\n", str);
	else if (f == 2)
		ft_printf("  can't read %s\n", str);
	else if (f == 3)
		ft_printf("");
	exit(0);
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

int				get_champ(char *str, t_param *p, int id)
{
	int		f;

	if (!(f = open(str, O_RDONLY)))
		champ_err(1, str);
	if ((read(f, &p->champs[p->players].magic, 4)) == -1)
		champ_err(2, str);
	if ((read(f, p->champs[p->players].name, PROG_NAME_LENGTH)) == -1)
		champ_err(2, str);
	if ((read(f, p->champs[p->players].null_term, 4)) == -1)
		champ_err(2, str);
	p->champs[p->players].name[PROG_NAME_LENGTH] = '\0';
	if ((read(f, &p->champs[p->players].champ_size, 4)) == -1)
		champ_err(2, str);
	rev_bits((char *)&p->champs[p->players].champ_size, 4);
	if ((read(f, p->champs[p->players].comment, COMMENT_LENGTH)) == -1)
		champ_err(2, str);
	p->champs[p->players].comment[COMMENT_LENGTH] = '\0';
	if ((read(f, p->champs[p->players].null_term, 4)) == -1)
		champ_err(2, str);
	if ((read(f, p->champs[p->players].champ,
					p->champs[p->players].champ_size)) == -1)
		champ_err(2, str);
	p->champs[p->players].champ[p->champs[p->players].champ_size] = '\0';
	++p->players;
	return (2);
}
