/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:19:01 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/29 20:29:29 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	if (!(s2 = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s2[len] = '\0';
	while (len-- > 0)
		s2[len] = s1[len];
	return (s2);
}
