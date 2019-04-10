/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 00:42:47 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/17 07:17:33 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int
	main
	(void)
{
	t_process	p;

	p = init_process();

	check_lives();
	check_ld();
	check_st();
	check_add();
	check_sub();
	check_and();
	check_or();
	check_xor();
	check_ldi();
	check_sti();
	check_lld();
	check_lldi();
	check_aff();
	return (0);
}