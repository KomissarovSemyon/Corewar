/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:26:45 by amerlon-          #+#    #+#             */
/*   Updated: 2018/11/29 20:18:10 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ndst;
	unsigned const char	*nsrc;
	size_t				i;

	ndst = (unsigned char *)dst;
	nsrc = (unsigned const char *)src;
	i = -1;
	while (++i < n)
	{
		ndst[i] = nsrc[i];
		if (ndst[i] == (unsigned char)c)
			return (ndst + i + 1);
	}
	return (NULL);
}
