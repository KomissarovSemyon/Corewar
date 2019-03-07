/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:11:05 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/28 22:48:47 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		maxsizet;

	maxsizet = -1;
	if (!s || start == (size_t)(maxsizet))
		return (NULL);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len--)
		str[len] = s[start + len];
	return (str);
}
