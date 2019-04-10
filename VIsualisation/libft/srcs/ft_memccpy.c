/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:03:49 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/29 20:50:08 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ptr_d;
	char	*ptr_s;

	ptr_d = (char*)dst;
	ptr_s = (char*)src;
	while (n--)
	{
		*ptr_d++ = *ptr_s++;
		if ((unsigned char)*(ptr_s - 1) == (unsigned char)c)
			return ((void*)ptr_d);
	}
	return (NULL);
}
