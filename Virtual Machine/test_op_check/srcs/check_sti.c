/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 07:09:15 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/17 07:09:33 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void
	check_sti
	(void)
{
	t_process	p;

	p = init_process();

	ft_printf("\033[0;33m%s\033[0m\n", "test sti:");
	p.op.type = 11;

	set_map_pos(&p, 1, (1 << 6) + (1 << 4) + (1 << 2));
	set_map_pos(&p, 2, 1);
	set_map_pos(&p, 3, 1);
	set_map_pos(&p, 4, 1);
	check_me(&p, 0, 1);

	set_map_pos(&p, 1, (2 << 6) + (1 << 4) + (1 << 2));
	check_me(&p, 0, 0);

	set_map_pos(&p, 1, (1 << 6) + (1 << 4) + (3 << 2));
	check_me(&p, 0, 0);

	set_map_pos(&p, 1, (1 << 6) + (2 << 4) + (2 << 2));
	check_me(&p, 0, 1);
}
