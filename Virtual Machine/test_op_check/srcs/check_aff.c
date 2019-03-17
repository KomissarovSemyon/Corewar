/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_aff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 06:57:49 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/17 06:59:08 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void
	check_aff
	(void)
{
	t_process	p;

	p = init_process();

	ft_printf("\033[0;33m%s\033[0m\n", "test aff:");
	p.op.type = 16;

	set_map_pos(&p, 1, (1 << 6) + (0 << 4) + (0 << 2));
	set_map_params(&p, 2,
	1, 1,
	1, 1,
	1);
	check_me(&p, 0, 1);

	set_map_pos(&p, 1, (1 << 6) + (1 << 4) + (0 << 2));
	check_me(&p, 0, 0);

}
