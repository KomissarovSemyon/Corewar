/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:20:58 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/03/22 16:20:59 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned char	calc_type_args(int t1, int t2, int t3)
{
	unsigned char	val;

	val = 0;
	if (t1 > 0)
		val += t1 * 64;
	if (t2 > 0)
		val += t2 * 16;
	if (t3 > 0)
		val += t3 * 4;
	return (val);
}

int				live_check(t_asm *ch, char *line, int only)
{
	ch->tmp = ch->current_addr;
	ch->last = 1;
	get_args(ch, line, 2, 0);
	if (only)
		ch->current_addr += ch->args[0][2] + 1;
	else
	{
		ch->byte[ch->current_addr++] = 1;
		put_bytes(ch, ch->args[0][0], ch->args[0][2]);
	}
	return (1);
}

int				ld_check(t_asm *ch, char *line, int only)
{
	char			*tmp;

	ch->tmp = ch->current_addr;
	tmp = ft_strdup(line);
	get_args(ch, tmp, 6, 0);
	tmp = next_arg(ch, tmp);
	ch->last = 1;
	get_args(ch, tmp, 1, 1);
	ft_strdel(&tmp);
	if (only)
		ch->current_addr += ch->args[0][2] + 2 + ch->args[1][2];
	else
	{
		ch->byte[ch->current_addr++] = 2;
		ch->byte[ch->current_addr++] = calc_type_args(ch->args[0][1],
			ch->args[1][1], 0);
		put_bytes(ch, ch->args[0][0], ch->args[0][2]);
		put_bytes(ch, ch->args[1][0], ch->args[1][2]);
	}
	return (1);
}

int				st_check(t_asm *ch, char *line, int only)
{
	char			*tmp;

	ch->tmp = ch->current_addr;
	tmp = ft_strdup(line);
	get_args(ch, tmp, 1, 0);
	tmp = next_arg(ch, tmp);
	ch->last = 1;
	get_args(ch, tmp, 5, 1);
	ft_strdel(&tmp);
	if (only)
		ch->current_addr += ch->args[0][2] + 2 + ch->args[1][2];
	else
	{
		ch->byte[ch->current_addr++] = 3;
		ch->byte[ch->current_addr++] = calc_type_args(ch->args[0][1],
			ch->args[1][1], 0);
		put_bytes(ch, ch->args[0][0], ch->args[0][2]);
		put_bytes(ch, ch->args[1][0], ch->args[1][2]);
	}
	return (1);
}

int				add_check(t_asm *ch, char *line, int only)
{
	char			*tmp;

	tmp = ft_strdup(line);
	get_args(ch, tmp, 1, 0);
	tmp = next_arg(ch, tmp);
	get_args(ch, tmp, 1, 1);
	tmp = next_arg(ch, tmp);
	ch->last = 1;
	get_args(ch, tmp, 1, 2);
	ft_strdel(&tmp);
	if (only)
		ch->current_addr += ch->args[0][2] + 2 + ch->args[1][2]
			+ ch->args[2][2];
	else
	{
		ch->byte[ch->current_addr++] = 4;
		ch->byte[ch->current_addr++] = calc_type_args(ch->args[0][1],
			ch->args[1][1], ch->args[2][1]);
		put_bytes(ch, ch->args[0][0], ch->args[0][2]);
		put_bytes(ch, ch->args[1][0], ch->args[1][2]);
		put_bytes(ch, ch->args[2][0], ch->args[2][2]);
	}
	return (1);
}
