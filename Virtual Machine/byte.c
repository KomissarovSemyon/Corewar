/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 01:33:41 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/13 01:56:00 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void		main()
{
	char	c;
	int		i = 0;

	while (read(0, &c, 1) != 0)
	{
		printf("%hhx", c);
		if (++i == 4)
			printf("\nmagic\n");
		if (i == 132)
			printf("\nname\n");
		if (i == 136)
			printf("\nnull\n");
		if (i == 140)
			printf("\nlen\n");
		if (i == 2188)
			printf("\ncomment\n");
		if (i == 2192)
			printf("\nnull\n");
	}
}
