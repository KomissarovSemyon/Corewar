/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:53:22 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/03/11 14:53:22 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	t_asm	*ch;

	ch = (t_asm *)malloc(sizeof(t_asm));
	asm_init(ch);
	if (ac == 2)
	{
		read_champ(av[1], ch);
		write_bytes(av[1], ch);
	}
	free(ch);
	return (0);
}
