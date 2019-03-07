/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:20:11 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/29 20:45:54 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		flag;

	flag = 1;
	ptr = (char*)s;
	while (*ptr)
		if (*(ptr++) == c)
			flag = 0;
	if (flag)
		return (c == '\0' ? ptr : NULL);
	while (*ptr != c && ptr != (char*)s)
		ptr--;
	return (ptr);
}
