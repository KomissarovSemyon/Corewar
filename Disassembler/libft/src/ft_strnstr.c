/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:57:18 by amerlon-          #+#    #+#             */
/*   Updated: 2018/12/04 22:04:27 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = -1;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[++i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			k = i;
			while (needle[++j] && haystack[++k] && haystack[k] == needle[j]
				&& k < len)
				;
			if (!needle[j])
				return ((char *)(haystack + i));
		}
	}
	return (NULL);
}
