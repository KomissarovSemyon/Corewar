/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:16:49 by amerlon-          #+#    #+#             */
/*   Updated: 2019/04/11 19:11:27 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassemble.h"
#include "vm.h"

void		start(int fd, char *argv)
{
	int		fd_out;
	int		i;
	char	*name;

	name = ft_strnew(ft_strlen(argv) - 2);
	ft_memmove(name, argv, ft_strlen(argv) - 2);
	i = ft_strrchr(name, '.') - name;
	name[i + 1] = 's';
	name[i + 2] = '\0';
	fd_out = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	lseek(fd, 0, SEEK_SET);
	disassemble(fd, fd_out);
	ft_putstr("Writing output program to ");
	ft_putendl(name);
	close(fd);
	close(fd_out);
	ft_strdel(&name);
}

static void	ft_printf(char *str, char *str2)
{
	ft_putstr(str);
	ft_putendl(str2);
}

void		champ_err(int value, int f, char *str, int expect)
{
	if (f == 1)
		ft_printf("  can't open ", str);
	else if (f == 2)
		ft_printf(str, " is not champion");
	else if (f == 5)
		ft_printf(str, " has invalid operations");
	else if (value == -1)
		ft_printf("  can't read ", str);
	else if (value < expect)
		ft_printf("Invalid champion ", str);
	else
		return ;
	exit(0);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_param	p;

	if (argc > 1)
	{
		get_champ(argv[1], &p, 1);
		fd = open(argv[1], O_RDONLY);
		start(fd, argv[1]);
	}
	else
		ft_putstr("usage: file.cor\n");
	return (0);
}
