/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:21:58 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/29 22:20:08 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	if (!(*needle))
		return ((char*)haystack);
	i = 0;
	j = 0;
	while (haystack[i] && i + j < len)
	{
		if (haystack[i] == needle[j])
		{
			while (needle[j] && i + j < len && haystack[i + j] == needle[j])
				j++;
			if (!needle[j])
				return ((char*)&haystack[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
