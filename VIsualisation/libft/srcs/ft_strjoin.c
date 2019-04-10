/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:21:07 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/26 20:41:46 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (int)(len1 + len2 + 1))))
		return (NULL);
	str[len1 + len2] = '\0';
	i = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	return (str);
}

char	*ft_rejoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s2)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (int)(len1 + len2 + 1))))
		return (NULL);
	str[len1 + len2] = '\0';
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	while (i < len1 + len2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	if (s1)
		free(s1);
	return (str);
}
