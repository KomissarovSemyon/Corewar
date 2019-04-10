/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 07:04:05 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/17 07:04:53 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void
	check_st
	(void)
{
	t_process	p;

	p = init_process();

	ft_printf("\033[0;33m%s\033[0m\n", "test st:");
	p.op.type = 3;
	set_map_pos(&p, 1, 64);
	set_map_pos(&p, 2, 1);
	check_me(&p, 0, 1);
	set_map_pos(&p, 1, 64 + 32);
	set_map_pos(&p, 2, 1);
	check_me(&p, 0, 0);
}
