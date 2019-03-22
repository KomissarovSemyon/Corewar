/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 07:13:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/17 07:13:18 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void
	check_xor
	(void)
{
	t_process	p;

	p = init_process();

	ft_printf("\033[0;33m%s\033[0m\n", "test xor:");
	p.op.type = 8;

	set_map_pos(&p, 1, 64 + 16 + 4);
	set_map_pos(&p, 2, 1);
	set_map_pos(&p, 3, 1);
	set_map_pos(&p, 4, 1);
	check_me(&p, 0, 1);

	set_map_pos(&p, 4, 0);
	check_me(&p, 0, 0);

	set_map_pos(&p, 1, 128 + 16 + 4);
	set_map_pos(&p, 2, 1);
	set_map_pos(&p, 6, 1);
	set_map_pos(&p, 7, 1);
	check_me(&p, 0, 1);

	set_map_pos(&p, 1, 128 + 32 + 4);
	set_map_pos(&p, 2, 1);
	set_map_pos(&p, 6, 1);
	set_map_pos(&p, 10, 1);
	check_me(&p, 0, 1);

	set_map_pos(&p, 1, 128 + 32 + 8);
	check_me(&p, 0, 0);
}