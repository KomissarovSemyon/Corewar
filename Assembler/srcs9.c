/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:46:51 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/03/22 16:46:52 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			fork_check(t_asm *ch, char *line, int only)
{
	ch->tmp = ch->current_addr;
	ch->last = 1;
	get_args(ch, line, 2, 0);
	if (only)
		ch->current_addr += 3;
	else
	{
		ch->byte[ch->current_addr++] = 12;
		put_bytes(ch, ch->args[0][0], 2);
	}
	return (1);
}

int			lld_check(t_asm *ch, char *line, int only)
{
	char			*tmp;

	ch->tmp = ch->current_addr;
	tmp = ft_strdup(line);
	get_args(ch, tmp, 6, 0);
	tmp = next_arg(ch, tmp);
	ch->last = 1;
	get_args(ch, tmp, 1, 1);
	free_str(tmp);
	if (only)
		ch->current_addr += ch->args[0][2] + 2 + ch->args[1][2];
	else
	{
		ch->byte[ch->current_addr++] = 13;
		ch->byte[ch->current_addr++] = calc_type_args(ch->args[0][1],
			ch->args[1][1], 0);
		put_bytes(ch, ch->args[0][0], ch->args[0][2]);
		put_bytes(ch, ch->args[1][0], ch->args[1][2]);
	}
	return (1);
}

void		check_this_out(t_asm *ch)
{
	ch->args[0][2] = ch->args[0][2] == 4 ? 2 : ch->args[0][2];
	ch->args[1][2] = ch->args[1][2] == 4 ? 2 : ch->args[1][2];
}

int			lldi_check(t_asm *ch, char *line, int only)
{
	char			*tmp;

	ch->tmp = ch->current_addr;
	tmp = ft_strdup(line);
	get_args(ch, tmp, 7, 0);
	tmp = next_arg(ch, tmp);
	get_args(ch, tmp, 4, 1);
	tmp = next_arg(ch, tmp);
	ch->last = 1;
	get_args(ch, tmp, 1, 2);
	free_str(tmp);
	check_this_out(ch);
	if (only)
		ch->current_addr += ch->args[0][2] + 3 + ch->args[1][2];
	else
	{
		ch->byte[ch->current_addr++] = 14;
		ch->byte[ch->current_addr++] = calc_type_args(ch->args[0][1],
			ch->args[1][1], ch->args[2][1]);
		put_bytes(ch, ch->args[0][0], ch->args[0][2]);
		put_bytes(ch, ch->args[1][0], ch->args[1][2]);
		put_bytes(ch, ch->args[2][0], 1);
	}
	return (1);
}

int			lfork_check(t_asm *ch, char *line, int only)
{
	ch->tmp = ch->current_addr;
	ch->last = 1;
	get_args(ch, line, 2, 0);
	if (only)
		ch->current_addr += 3;
	else
	{
		ch->byte[ch->current_addr++] = 15;
		put_bytes(ch, ch->args[0][0], 2);
	}
	return (1);
}
