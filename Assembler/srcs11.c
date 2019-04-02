/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs11.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:55:17 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/03/22 16:55:18 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	is_label_inner(t_asm *ch, char *line, int first, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	tmp = ft_strncpy((char *)malloc(i + 1), line, i);
	tmp[i] = '\0';
	while (j < ch->labels_count)
	{
		if (ft_strcmp(tmp, ch->labels[j].label) == 0)
		{
			if (first == 1)
				ch->labels[j].addr = ch->current_addr + H;
			j = ch->labels_count;
		}
		j++;
	}
	ft_strdel(&tmp);
	if (j != ch->labels_count + 1)
		error_clear_exit(ch, "Ошибка! Указана несуществующая метка!", 1, line);
}

int		is_label(t_asm *ch, char *line, int first)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == LABEL_CHAR && i > 0)
		{
			is_label_inner(ch, line, first, i);
			return (i + 1);
		}
		if (check_symbol(line[i]) == 0)
			return (-1);
		i++;
	}
	return (-1);
}

void	check_comment_inner(t_asm *ch, char *line, int *start, int *i)
{
	if (line[*i] == '"')
	{
		if (ch->comment_init == 0)
			ch->comment_init = 1;
		else
		{
			if (!check_simple_comment(line + *i + 1))
			{
				ft_strdel(&ch->for_del);
				error_clear_exit(ch, "Найден мусор после комментария!",
					1, line);
			}
			if (ch->tmp > 0)
				ft_strdel(&line);
			*i = -100;
		}
	}
	if (*i >= 0 && ch->comment_init == 1 && line[*i] != '"')
		ch->comment[(*start)++] = line[*i];
}

void	check_comment_middle(t_asm *ch, char *line, int *start, int *i)
{
	while (*i >= 0 && line[*i])
	{
		check_comment_inner(ch, line, start, i);
		if (*i >= 0 && line[*i + 1] == 0)
			while (*i != -1)
			{
				if (ch->tmp > 0)
					ft_strdel(&line);
				if (get_next_line(ch->fd, &line) != 1)
					error_clear_exit(ch, "Ошибка в .comment", 1, line);
				ch->tmp = 1;
				ch->comment[(*start)++] = '\n';
				ch->row++;
				if (line && line[0])
					*i = -1;
			}
		(*i)++;
	}
}

int		check_comment(t_asm *ch, char *line)
{
	int		i;
	int		start;

	i = ft_strlen(COMMENT_CMD_STRING);
	if (ft_strncmp(line, COMMENT_CMD_STRING, i) == 0)
	{
		ch->tmp = 0;
		ch->for_del = line;
		start = 0;
		if (ch->comment_init == 1)
			error_clear_exit(ch, "Найдено второй комментарий!", 1, line);
		check_comment_middle(ch, line, &start, &i);
		if (ch->comment_init == 0)
			error_clear_exit(ch, "Ошибка в .comment!!", 1, line);
		else
			ch->comment[start] = '\0';
		return (1);
	}
	return (0);
}
