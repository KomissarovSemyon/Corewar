/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 21:30:19 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/02/01 21:41:51 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*init_char1(unsigned int t, size_t *size)
{
	unsigned char	*s;

	s = (unsigned char *)malloc(2);
	s[0] = t;
	s[1] = 0;
	*size = 1;
	return ((char *)s);
}

char	*init_char2(unsigned int t, size_t *size)
{
	unsigned char	*s;

	s = (unsigned char *)malloc(3);
	s[1] = 128 + (t % 64);
	t /= 64;
	s[0] = 192 + t;
	s[2] = 0;
	*size = 2;
	return ((char *)s);
}

char	*init_char3(unsigned int t, size_t *size)
{
	unsigned char	*s;

	s = (unsigned char *)malloc(4);
	s[2] = 128 + (t % 64);
	t /= 64;
	s[1] = 128 + (t % 64);
	t /= 64;
	s[0] = 224 + t;
	s[3] = 0;
	*size = 3;
	return ((char *)s);
}

char	*init_char4(unsigned int t, size_t *size)
{
	unsigned char	*s;

	s = (unsigned char *)malloc(5);
	s[3] = 128 + t % 64;
	t /= 64;
	s[2] = 128 + t % 64;
	t /= 64;
	s[1] = 128 + t % 64;
	t /= 64;
	s[0] = 240 + t;
	s[4] = 0;
	*size = 4;
	return ((char *)s);
}

char	*conver(unsigned int a, size_t *size)
{
	if (a < 128)
		return (init_char1(a, size));
	if (a >= 128 && a < 2048)
		return (init_char2(a, size));
	if (a >= 2248 && a < 65536)
		return (init_char3(a, size));
	if (a >= 65536 && a < 1114112)
		return (init_char4(a, size));
	return (NULL);
}
