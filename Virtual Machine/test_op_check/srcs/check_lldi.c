/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lldi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 07:02:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/17 07:23:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void
	check_lldi
	(void)
{
	t_process	p;

	p = init_process();

	ft_printf("\033[0;33m%s\033[0m\n", "test lldi:");
	p.op.type = 14;

	set_map_pos(&p, 1, (1 << 6) + (1 << 4) + (1 << 2));
	set_map_pos(&p, 1 + 1, 1);
	set_map_pos(&p, 1 + 1 + 1, 1);
	set_map_pos(&p, 1 + 1 + 1 + 1, 1);
	check_me(&p, 0, 1);

	set_map_pos(&p, 1, (2 << 6) + (2 << 4) + (1 << 2));
	set_map_pos(&p, 1 + 1 + 2 + 2, 1);
	check_me(&p, 0, 1);
}
