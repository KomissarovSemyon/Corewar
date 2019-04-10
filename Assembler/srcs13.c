/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:20:50 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/03/22 17:20:50 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ldi_check(t_asm *ch, char *line, int only)
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
	ldi_check_inner(ch);
	free_str(tmp);
	if (only)
		ch->current_addr += 3 + ch->args[0][1] + ch->args[1][1];
	else
	{
		ch->byte[ch->current_addr++] = 10;
		ch->byte[ch->current_addr++] = calc_type_args(ch->args[0][1],
			ch->args[1][1], ch->args[2][1]);
		put_bytes(ch, ch->args[0][0], ch->args[0][2]);
		put_bytes(ch, ch->args[1][0], ch->args[1][2]);
		put_bytes(ch, ch->args[2][0], 1);
	}
	return (1);
}

void	sti_check_inner(t_asm *ch)
{
	if (ch->args[2][1] == 2)
		ch->args[2][2] = 2;
	if (ch->args[1][1] == 2)
		ch->args[1][2] = 2;
}

int		sti_check(t_asm *ch, char *line, int only)
{
	char			*tmp;

	ch->tmp = ch->current_addr;
	tmp = ft_strdup(line);
	get_args(ch, tmp, 1, 0);
	tmp = next_arg(ch, tmp);
	get_args(ch, tmp, 7, 1);
	tmp = next_arg(ch, tmp);
	ch->last = 1;
	get_args(ch, tmp, 4, 2);
	sti_check_inner(ch);
	free_str(tmp);
	if (only)
		ch->current_addr += 3 + ch->args[2][2] + ch->args[1][2];
	else
	{
		ch->byte[ch->current_addr++] = 11;
		ch->byte[ch->current_addr++] = calc_type_args(ch->args[0][1],
			ch->args[1][1], ch->args[2][1]);
		put_bytes(ch, ch->args[0][0], 1);
		put_bytes(ch, ch->args[1][0], ch->args[1][2]);
		put_bytes(ch, ch->args[2][0], ch->args[2][2]);
	}
	return (1);
}

void	open_write_file(t_asm *ch, char *file)
{
	if ((ch->fd = open(file, O_WRONLY | O_CREAT, S_IREAD | S_IWRITE)) == -1)
		error_clear_exit(ch, "Error to open write file!", 0, NULL);
}

void	write_bytes(char *file, t_asm *ch)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = file;
	while (ft_strchr(tmp + 1, '.'))
		tmp = ft_strchr(tmp + 1, '.');
	if (tmp)
	{
		i = tmp - file;
		tmp2 = ft_strncpy((char *)malloc(i + 5), file, i);
		tmp2[i++] = '.';
		tmp2[i++] = 'c';
		tmp2[i++] = 'o';
		tmp2[i++] = 'r';
		tmp2[i++] = '\0';
	}
	else
		tmp2 = ft_strdup("no_point.cor");
	open_write_file(ch, tmp2);
	ft_printf("Writing output program to %s\n", tmp2);
	ft_strdel(&tmp2);
	write(ch->fd, ch->byte, ch->current_addr);
	close(ch->fd);
}
