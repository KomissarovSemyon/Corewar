/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:21:04 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/03/22 16:21:05 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			sub_check(t_asm *ch, char *line, int only)
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
		ch->current_addr += ch->args[0][2] + 2 +
			ch->args[1][2] + ch->args[2][2];
	else
	{
		ch->byte[ch->current_addr++] = 5;
		ch->byte[ch->current_addr++] = calc_type_args(ch->args[0][1],
			ch->args[1][1], ch->args[2][1]);
		put_bytes(ch, ch->args[0][0], ch->args[0][2]);
		put_bytes(ch, ch->args[1][0], ch->args[1][2]);
		put_bytes(ch, ch->args[2][0], ch->args[2][2]);
	}
	return (1);
}

int			and_check(t_asm *ch, char *line, int only)
{
	char			*tmp;

	ch->tmp = ch->current_addr;
	tmp = ft_strdup(line);
	get_args(ch, tmp, 7, 0);
	tmp = next_arg(ch, tmp);
	get_args(ch, tmp, 7, 1);
	tmp = next_arg(ch, tmp);
	ch->last = 1;
	get_args(ch, tmp, 1, 2);
	free_str(tmp);
	if (only)
		ch->current_addr += ch->args[0][2] + 2 +
			ch->args[1][2] + ch->args[2][2];
	else
	{
		ch->byte[ch->current_addr++] = 6;
		ch->byte[ch->current_addr++] = calc_type_args(ch->args[0][1],
			ch->args[1][1], ch->args[2][1]);
		put_bytes(ch, ch->args[0][0], ch->args[0][2]);
		put_bytes(ch, ch->args[1][0], ch->args[1][2]);
		put_bytes(ch, ch->args[2][0], ch->args[2][2]);
	}
	return (1);
}

int			or_check(t_asm *ch, char *line, int only)
{
	char			*tmp;

	ch->tmp = ch->current_addr;
	tmp = ft_strdup(line);
	get_args(ch, tmp, 7, 0);
	tmp = next_arg(ch, tmp);
	get_args(ch, tmp, 7, 1);
	tmp = next_arg(ch, tmp);
	ch->last = 1;
	get_args(ch, tmp, 1, 2);
	free_str(tmp);
	if (only)
		ch->current_addr += ch->args[0][2] + 2 +
			ch->args[1][2] + ch->args[2][2];
	else
	{
		ch->byte[ch->current_addr++] = 7;
		ch->byte[ch->current_addr++] = calc_type_args(ch->args[0][1],
			ch->args[1][1], ch->args[2][1]);
		put_bytes(ch, ch->args[0][0], ch->args[0][2]);
		put_bytes(ch, ch->args[1][0], ch->args[1][2]);
		put_bytes(ch, ch->args[2][0], ch->args[2][2]);
	}
	return (1);
}

int			xor_check(t_asm *ch, char *line, int only)
{
	char			*tmp;

	ch->tmp = ch->current_addr;
	tmp = ft_strdup(line);
	get_args(ch, tmp, 7, 0);
	tmp = next_arg(ch, tmp);
	get_args(ch, tmp, 7, 1);
	tmp = next_arg(ch, tmp);
	ch->last = 1;
	get_args(ch, tmp, 1, 2);
	free_str(tmp);
	if (only)
		ch->current_addr += ch->args[0][2] + 2 +
			ch->args[1][2] + ch->args[2][2];
	else
	{
		ch->byte[ch->current_addr++] = 8;
		ch->byte[ch->current_addr++] = calc_type_args(ch->args[0][1],
			ch->args[1][1], ch->args[2][1]);
		put_bytes(ch, ch->args[0][0], ch->args[0][2]);
		put_bytes(ch, ch->args[1][0], ch->args[1][2]);
		put_bytes(ch, ch->args[2][0], ch->args[2][2]);
	}
	return (1);
}

int			zjmp_check(t_asm *ch, char *line, int only)
{
	ch->tmp = ch->current_addr;
	ch->last = 1;
	get_args(ch, line, 2, 0);
	if (only)
		ch->current_addr += 3;
	else
	{
		ch->byte[ch->current_addr++] = 9;
		put_bytes(ch, ch->args[0][0], 2);
	}
	return (1);
}
