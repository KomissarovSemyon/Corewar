/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:00:38 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/29 20:40:48 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_dst;
	char	*ptr_src;

	ptr_dst = (char*)dst;
	ptr_src = (char*)src;
	if (ptr_dst < ptr_src)
		while (len--)
			*ptr_dst++ = *ptr_src++;
	else if (ptr_dst > ptr_src)
	{
		ptr_dst += len - 1;
		ptr_src += len - 1;
		while (len--)
			*ptr_dst-- = *ptr_src--;
	}
	return (dst);
}
