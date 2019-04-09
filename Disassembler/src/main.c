/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:16:49 by amerlon-          #+#    #+#             */
/*   Updated: 2019/04/09 21:24:53 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassemble.h"

void	start(int fd, char *argv)
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

int		main(int argc, char **argv)
{
	int		fd;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr("File error\n");
			return (0);
		}
		start(fd, argv[1]);
	}
	else
		ft_putstr("usage: file.cor\n");
	return (0);
}
