/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:14:57 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/07 14:15:47 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i[3];

	i[0] = 0;
	if (!*to_find)
		return ((char *)str);
	while (str[i[0]] != '\0')
	{
		i[1] = 0;
		i[2] = -1;
		while (str[i[0]] == to_find[i[1]])
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
	return (0);
}
