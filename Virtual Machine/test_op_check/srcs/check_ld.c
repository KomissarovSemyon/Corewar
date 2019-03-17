/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 06:38:48 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/17 06:58:05 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void
	check_ld
	(void)
{
	t_process	p;

	p = init_process();
	ft_printf("\033[0;33m%s\033[0m\n", "test ld:");
	p.op.type = 2;
	set_map_pos(&p, 1, (2 << 6) + (0 << 4) + (0 << 2));
	set_map_params(&p, 2,
	4, 128,
	1, 1,
	0);
	check_me(&p, 0, 1);
	set_map_params(&p, 2,
	4, 128 + 64,
	1, 16,
	0);
	check_me(&p, 0, 1);
	set_map_params(&p, 2,
	4, 128 + 64,
	1, 17,
	0);
	check_me(&p, 0, 0);
}
