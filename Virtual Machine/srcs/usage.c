/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 03:05:48 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/09 10:14:13 by jcorwin          ###   ########.fr       */
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
	ft_printf("\n  usage: [-help] | [-vis] | [-dump N | -step N [-map -param]] ");
	ft_printf("[-cycle] [-process] [-oper] [-check] [-n N] ");
	ft_printf("champ1.cor champ2.cor ...\n\n");
	exit(0);
}

void		help(void)
{
	ft_printf("\n  usage: [-help] | [-vis] | [-dump N | -step N [-map -param]] ");
	ft_printf("[-cycle] [-process] [-oper] [-check] [-n N] ");
	ft_printf("champ1.cor champ2.cor ...\n");
	ft_printf("%12s%8s %s\n", "-vis", ":  ", "visual output mode");
	ft_printf("%12s%8s %s\n", "-dump N", ":  ",
								"dump memory after N cycles then exit");
	ft_printf("%12s%8s %s\n", "-step N", ":  ",
						"runs N cycles, show data, pauses, then repeats");
	ft_printf("%12s%8s %s\n", "-cycle", ":  ", "show current cycle");
	ft_printf("%12s%8s %s\n", "-process", ":  ", "show each process info");
	ft_printf("%12s%8s %s\n", "-oper", ":  ", "operation execution");
	ft_printf("%12s%8s %s\n", "-check", ":  ", "show check result");
	exit(0);
}
