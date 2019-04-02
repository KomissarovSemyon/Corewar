/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:19:33 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/03/22 17:19:34 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_name_inner(t_asm *ch, char *line, int i, int *start)
{
	while (line[i])
	{
		if (line[i] == '"')
		{
			if (ch->name_init == 0)
				ch->name_init = 1;
			else
			{
				ch->name[(*start)++] = '\0';
				if (!check_simple_comment(line + i + 1))
					error_clear_exit(ch, "Найден мусор после имени!", 1, line);
				break ;
			}
		}
		if (ch->name_init == 1 && line[i] != '"')
			ch->name[(*start)++] = line[i];
		i++;
	}
}

int		check_name(t_asm *ch, char *line)
{
	int		i;
	int		start;

	i = ft_strlen(NAME_CMD_STRING);
	if (ft_strncmp(line, NAME_CMD_STRING, i) == 0)
	{
		start = 0;
		if (ch->name_init == 1)
			error_clear_exit(ch, "Найдено второе имя!", 1, line);
		check_name_inner(ch, line, i, &start);
		if (ch->name_init == 0)
			error_clear_exit(ch, "Ошибка в имени!!", 1, line);
		else
			ch->name[start] = '\0';
		return (1);
	}
	return (0);
}

void	check_comment_to_byte_inner(t_asm *ch, char *line, int *i)
{
	if (line[*i] == '"')
	{
		if (ch->last == 0)
			ch->last = 1;
		else
		{
			if (ch->tmp > 0)
				ft_strdel(&line);
			*i = -22;
		}
	}
}

int		check_comment_to_byte(t_asm *ch, char *line)
{
	int		i;

	i = ft_strlen(COMMENT_CMD_STRING);
	if (ft_strncmp(line, COMMENT_CMD_STRING, i) == 0)
	{
		ch->tmp = 0;
		ch->last = 0;
		while (i >= 0 && line[i])
		{
			check_comment_to_byte_inner(ch, line, &i);
			if (i >= 0 && line[i + 1] == 0)
				while (i != -1)
				{
					if (ch->tmp > 0)
						ft_strdel(&line);
					get_next_line(ch->fd, &line);
					ch->tmp = 1;
					if (line && line[0])
						i = -1;
				}
			i++;
		}
		return (1);
	}
	return (0);
}

void	ldi_check_inner(t_asm *ch)
{
	if (ch->args[0][1] == 2)
		ch->args[0][2] = 2;
	if (ch->args[1][1] == 2)
		ch->args[1][2] = 2;
}
