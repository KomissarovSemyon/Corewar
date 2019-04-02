/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:48:00 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/11 19:13:23 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int		i[3];

	i[0] = 0;
	if (!*to_find)
		return ((char *)str);
	while (i[0] < (int)n && str[i[0]] != '\0')
	{
		i[1] = 0;
		i[2] = -1;
		while (str[i[0]] == to_find[i[1]] && i[0] < (int)n)
		{
			if (i[2] == -1)
				i[2] = i[0];
			i[1]++;
			i[0]++;
			if (to_find[i[1]] == '\0')
				return ((char *)str + i[2]);
		}
		if (i[2] != -1)
			i[0] = i[2];
		i[0]++;
	}
	return (NULL);
}
