/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:20:42 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/03/22 16:20:43 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	open_file(t_asm *ch, char *file)
{
	if ((ch->fd = open(file, O_RDONLY, 0)) == -1)
		error_clear_exit(NULL, "Error to open file!", 0, NULL);
}

int		check_simple_comment(char *line)
{
	int		i;
	char	*tmp;

	tmp = ft_strtrim(line);
	i = 0;
	if (tmp && tmp[i] != COMMENT_CHAR && ft_strlen(tmp) != 0)
	{
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (1);
}

int		check_symbol(char c)
{
	int		i;

	i = 0;
	while (LABEL_CHARS[i])
	{
		if (LABEL_CHARS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		is_label_correct(t_asm *ch, char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == LABEL_CHAR && i > 0)
		{
			ft_strncpy(ch->labels[ch->labels_count].label, line, i);
			ch->labels[ch->labels_count].label[i] = '\0';
			ch->labels[ch->labels_count].num = ch->labels_count;
			ch->labels_count++;
			return (i + 1);
		}
		if (check_symbol(line[i]) == 0)
			return (-1);
		i++;
	}
	return (-1);
}
