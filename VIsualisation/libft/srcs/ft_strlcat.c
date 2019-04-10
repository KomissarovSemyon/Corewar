/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:51:56 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/29 20:51:42 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*s1;
	char	*s2;
	size_t	slen;
	size_t	dlen;

	slen = 0;
	dlen = 0;
	while (dst[dlen])
		dlen++;
	while (src[slen])
		slen++;
	if (size == 0)
		return (size < dlen ? slen + size : slen + dlen);
	s1 = (char*)dst;
	s2 = (char*)src;
	i = 0;
	while (s1[i] && i < size - 1)
		i++;
	while (*s2 && i < size - 1)
		s1[i++] = *s2++;
	if (s2 != src)
		s1[i] = '\0';
	return (size < dlen ? slen + size : slen + dlen);
}
