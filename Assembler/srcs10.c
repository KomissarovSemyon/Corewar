/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:46:58 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/03/22 16:46:59 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			aff_check(t_asm *ch, char *line, int only)
{
	ch->last = 1;
	get_args(ch, line, 1, 0);
	if (only)
		ch->current_addr += 2 + ch->args[0][2];
	else
	{
		ch->byte[ch->current_addr++] = 16;
		ch->byte[ch->current_addr++] = 0x40;
		put_bytes(ch, ch->args[0][0], ch->args[0][2]);
	}
	return (1);
}

void		cmsd_init_f(t_asm *ch)
{
	ch->cmds[0].fun = live_check;
	ch->cmds[1].fun = ldi_check;
	ch->cmds[2].fun = sti_check;
	ch->cmds[3].fun = add_check;
	ch->cmds[4].fun = sub_check;
	ch->cmds[5].fun = and_check;
	ch->cmds[6].fun = or_check;
	ch->cmds[7].fun = xor_check;
	ch->cmds[8].fun = zjmp_check;
	ch->cmds[9].fun = ld_check;
	ch->cmds[10].fun = st_check;
	ch->cmds[11].fun = fork_check;
	ch->cmds[12].fun = lldi_check;
	ch->cmds[13].fun = lld_check;
	ch->cmds[14].fun = lfork_check;
	ch->cmds[15].fun = aff_check;
}

void		cmds_init(t_asm *ch)
{
	ft_strcpy(ch->cmds[0].name, "live");
	ft_strcpy(ch->cmds[1].name, "ldi");
	ft_strcpy(ch->cmds[2].name, "sti");
	ft_strcpy(ch->cmds[3].name, "add");
	ft_strcpy(ch->cmds[4].name, "sub");
	ft_strcpy(ch->cmds[5].name, "and");
	ft_strcpy(ch->cmds[6].name, "or");
	ft_strcpy(ch->cmds[7].name, "xor");
	ft_strcpy(ch->cmds[8].name, "zjmp");
	ft_strcpy(ch->cmds[9].name, "ld");
	ft_strcpy(ch->cmds[10].name, "st");
	ft_strcpy(ch->cmds[11].name, "fork");
	ft_strcpy(ch->cmds[12].name, "lldi");
	ft_strcpy(ch->cmds[13].name, "lld");
	ft_strcpy(ch->cmds[14].name, "lfork");
	ft_strcpy(ch->cmds[15].name, "aff");
	cmsd_init_f(ch);
}

void		header_init(t_asm *ch)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ch->byte[i++] = 0;
	}
}

void		asm_init(t_asm *ch)
{
	ch->len = 0;
	ch->name[0] = '\0';
	ch->comment[0] = '\0';
	ch->comment_init = 0;
	ch->name_init = 0;
	ch->labels_count = 0;
	ch->current_addr = START;
	ch->val = 0;
	ch->type = 0;
	ch->last = 0;
	ch->row_index = 0;
	ch->byte_index = 0;
	ch->row = 1;
	ch->for_del = NULL;
	cmds_init(ch);
	header_init(ch);
}
