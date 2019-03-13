/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 03:05:48 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/13 01:15:15 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		malloc_err(void)
{
	ft_printf("Error: Can't allocate memory...");
	exit(0);
}

void		usage(void)
{
	ft_printf("\n  usage: [-help] | [-a] [-d N | -s N | -vis | -n] ");
	ft_printf("champ1.cor champ2.cor ...\n\n");
	exit(0);
}

void		help(void)
{
	ft_printf("\n  usage: [-help] | [-a] [-d N | -s N | -vis | -n] ");
	ft_printf("champ1.cor champ2.cor ...\n");
	ft_printf("%10s%10s %s\n", "-a", ":  ", "print champ's comment");
	ft_printf("%12s%8s %s\n", "-d N", ":  ",
								"dump memory after N cycles then exit");
	ft_printf("%12s%8s %s\n", "-s N", ":  ",
						"runs N cycles, dumps memory, pauses, then repeats");
	ft_printf("%10s%10s %s\n", "-n", ":  ", "ncurses output mode");
	ft_printf("%12s%8s %s\n\n", "-vis", ":  ", "visual output mode");
	exit(0);
}
