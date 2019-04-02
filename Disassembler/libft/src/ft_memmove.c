/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:18:26 by amerlon-          #+#    #+#             */
/*   Updated: 2018/11/27 20:03:47 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ndst;
	const char	*nsrc;
	size_t		i;

	ndst = dst;
	nsrc = src;
	i = -1;
	if (ndst > nsrc)
		while (len > 0)
		{
			--len;
			ndst[len] = nsrc[len];
		}
	else if (ndst < nsrc)
		while (++i < len)
			ndst[i] = nsrc[i];
	return (dst);
}
