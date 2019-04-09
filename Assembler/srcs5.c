/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:20:50 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/03/22 16:20:51 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_line_to_byte(t_asm *ch, char *line, int only_addr)
{
	ch->for_del = line;
	if (!check_name_to_byte(line)
		&& !check_comment_to_byte(ch, line))
	{
		check_command(ch, line, only_addr, 0);
	}
	return (0);
}

int		check_command_quick(t_asm *ch, char *line, int ind)
{
	int		i;
	int		res;

	i = -1;
	if (ind != -1)
		res = parse_command(ch, line + i, 1);
	else
		res = parse_command(ch, line, 1);
	return (0);
}

void	init_labels(char *file, t_asm *ch)
{
	char	*line;
	char	*tmp;
	int		i;

	open_file(ch, file);
	while ((get_next_line(ch->fd, &line)) > 0)
	{
		tmp = ft_strtrim(line);
		ft_strdel(&line);
		if (tmp)
		{
			if (tmp[0] != COMMENT_CHAR)
				i = is_label_correct(ch, tmp);
			ft_strdel(&tmp);
			ch->tmp = 1;
		}
		else
			ch->tmp = 0;
	}
	check_end_symbol(ch);
	close(ch->fd);
}

void	name_to_byte(t_asm *ch)
{
	int		i;

	i = 0;
	while (ch->name[i] && i < PROG_NAME_LENGTH)
	{
		ch->byte[ch->current_addr++] = ch->name[i];
		i++;
	}
	while (i < PROG_NAME_LENGTH)
	{
		ch->byte[ch->current_addr++] = 0;
		i++;
	}
}

void	comment_to_byte(t_asm *ch)
{
	int		i;

	i = 0;
	while (ch->comment[i] && i < COMMENT_LENGTH)
	{
		ch->byte[ch->current_addr++] = ch->comment[i];
		i++;
	}
	while (i < COMMENT_LENGTH)
	{
		ch->byte[ch->current_addr++] = 0;
		i++;
	}
}
