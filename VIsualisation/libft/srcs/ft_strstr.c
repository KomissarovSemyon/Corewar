/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:41:52 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/29 20:43:57 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	int			j;

	if (!(*needle))
		return ((char*)haystack);
	i = -1;
	while (haystack[++i])
		if (haystack[i] == needle[0])
		{
			j = 1;
			while (needle[j] && haystack[i + j] == needle[j])
				j++;
			if (!needle[j])
				return ((char*)&haystack[i]);
		}
	return (NULL);
}
