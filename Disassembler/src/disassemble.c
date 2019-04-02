/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:41:48 by amerlon-          #+#    #+#             */
/*   Updated: 2019/03/28 14:17:12 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassemble.h"

static int	count_args_size(char cmd, unsigned char args)
{
	int		res;
	int		dir_size;

	res = 0;
	if (cmd == 9 || cmd == 10 || cmd == 11 ||
		cmd == 12 || cmd == 14 || cmd == 15)
		dir_size = 2;
	else
		dir_size = 4;
	res += (unsigned char)(args >> 6) == REG_CODE ? 1 : (0);
	res += (unsigned char)(args >> 6) == DIR_CODE ? dir_size : (0);
	res += (unsigned char)(args >> 6) == IND_CODE ? 2 : (0);
	res += ((unsigned char)(args << 2) >> 6) == REG_CODE ? 1 : (0);
	res += ((unsigned char)(args << 2) >> 6) == DIR_CODE ? dir_size : (0);
	res += ((unsigned char)(args << 2) >> 6) == IND_CODE ? 2 : (0);
	res += ((unsigned char)(args << 4) >> 6) == REG_CODE ? 1 : (0);
	res += ((unsigned char)(args << 4) >> 6) == DIR_CODE ? dir_size : (0);
	res += ((unsigned char)(args << 4) >> 6) == IND_CODE ? 2 : (0);
	return (res);
}

static void	add_cmd_continue(char *str, char cmd)
{
	if (cmd == 12)
		ft_strcat(str, "fork ");
	else if (cmd == 13)
		ft_strcat(str, "lld ");
	else if (cmd == 14)
		ft_strcat(str, "lldi ");
	else if (cmd == 15)
		ft_strcat(str, "lfork ");
	else if (cmd == 16)
		ft_strcat(str, "aff ");
}

static void	add_cmd(char *str, char cmd)
{
	if (cmd == 1)
		ft_strcat(str, "live ");
	else if (cmd == 2)
		ft_strcat(str, "ld ");
	else if (cmd == 3)
		ft_strcat(str, "st ");
	else if (cmd == 4)
		ft_strcat(str, "add ");
	else if (cmd == 5)
		ft_strcat(str, "sub ");
	else if (cmd == 6)
		ft_strcat(str, "and ");
	else if (cmd == 7)
		ft_strcat(str, "or ");
	else if (cmd == 8)
		ft_strcat(str, "xor ");
	else if (cmd == 9)
		ft_strcat(str, "zjmp ");
	else if (cmd == 10)
		ft_strcat(str, "ldi ");
	else if (cmd == 11)
		ft_strcat(str, "sti ");
	else
		add_cmd_continue(str, cmd);
}

static void	parse_cmds(int in, int out)
{
	char			cmd;
	unsigned char	args;
	unsigned char	*buff;
	char			*str;

	buff = (unsigned char *)ft_memalloc(13);
	str = ft_strnew(100);
	while (read(in, &cmd, 1))
	{
		if (cmd == 1 || cmd == 9 || cmd == 12 || cmd == 15)
			args = 128;
		else
			read(in, &args, 1);
		read(in, buff, count_args_size(cmd, args));
		add_cmd(str, cmd);
		add_args(str, cmd, buff, args);
		ft_putendl_fd(str, out);
		ft_strclr(str);
		ft_strclr((char *)buff);
	}
	free(buff);
	ft_strdel(&str);
}

void		disassemble(int in, int out)
{
	char	buff[MAX(PROG_NAME_LENGTH, COMMENT_LENGTH) + 1];
	int		len;

	read(in, buff, 4);
	len = read(in, buff, PROG_NAME_LENGTH);
	buff[len] = '\0';
	ft_putstr_fd(NAME_CMD_STRING, out);
	ft_putstr_fd(" \"", out);
	ft_putstr_fd(buff, out);
	ft_putendl_fd("\"", out);
	read(in, buff, 8);
	len = read(in, buff, COMMENT_LENGTH);
	buff[len] = '\0';
	ft_putstr_fd(COMMENT_CMD_STRING, out);
	ft_putstr_fd(" \"", out);
	ft_putstr_fd(buff, out);
	ft_putendl_fd("\"\n", out);
	read(in, buff, 4);
	parse_cmds(in, out);
}
