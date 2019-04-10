/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 07:05:08 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/17 07:06:05 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void
	check_add
	(void)
{
	t_process	p;

	p = init_process();

	ft_printf("\033[0;33m%s\033[0m\n", "test add:");
	p.op.type = 4;

	set_map_pos(&p, 1, 64 + 16 + 4);
	set_map_pos(&p, 2, 1);
	set_map_pos(&p, 3, 1);
	set_map_pos(&p, 4, 1);
	check_me(&p, 0, 1);

	set_map_pos(&p, 1, 64 + 16 + 0);
	check_me(&p, 0, 0);

	set_map_pos(&p, 1, 64 + 16 + 4);
	set_map_pos(&p, 4, 0);
	check_me(&p, 0, 0);

	set_map_pos(&p, 1, 128 + 16 + 4);
	set_map_pos(&p, 2, 1);
	set_map_pos(&p, 6, 1);
	set_map_pos(&p, 7, 1);
	check_me(&p, 0, 0);
}
