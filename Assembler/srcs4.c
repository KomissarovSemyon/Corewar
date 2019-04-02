/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:20:46 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/03/22 16:20:47 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_command(t_asm *ch, char *line, int only, int first)
{
	int		i;
	int		res;

	i = -1;
	if ((i = is_label(ch, line, first)) != -1)
		res = parse_command(ch, line + i, only);
	else
		res = parse_command(ch, line, only);
	if (res == 0 && i == -1)
		error_clear_exit(ch, "Ошибка. Не существующая команда!", 1, line);
	return (0);
}

int		free_str(char *s)
{
	ft_strdel(&s);
	return (1);
}

int		parse_command(t_asm *ch, char *line, int only)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	tmp = ft_strtrim(line);
	if (!tmp)
		return (0);
	while (i < CMD_COUNT)
	{
		if (ft_strncmp(tmp, ch->cmds[i].name, ft_strlen(ch->cmds[i].name)) == 0)
		{
			tmp2 = ft_strtrim(tmp + ft_strlen(ch->cmds[i].name));
			ft_strdel(&tmp);
			if ((!tmp2 || !tmp2[0]) && free_str(tmp2))
				error_clear_exit(ch, "Ошибка. Отсутствуют аргументы", 1, line);
			ch->cmds[i].fun(ch, tmp2, only);
			ft_strdel(&tmp2);
			return (1);
		}
		i++;
	}
	ft_strdel(&tmp);
	return (0);
}

int		check_name_to_byte(char *line)
{
	int		i;

	i = ft_strlen(NAME_CMD_STRING);
	if (ft_strncmp(line, NAME_CMD_STRING, i) == 0)
		return (1);
	return (0);
}

int		check_line(t_asm *ch, char *line, int only_addr)
{
	if (!check_name(ch, line) && !check_comment(ch, line))
	{
		if (!ch->comment_init || !ch->name_init)
			error_clear_exit(ch,
				"Ошибка! Отсутствует .name или .comment!", 1, line);
		check_command(ch, line, only_addr, 1);
	}
	return (0);
}
