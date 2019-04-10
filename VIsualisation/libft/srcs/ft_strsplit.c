/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:24:13 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/27 22:03:29 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	countwords(char *str, char c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if (str[0] != c && str[0] != '\0')
		counter = 1;
	while (str[++i])
		if (str[i] != c && str[i - 1] == c)
			counter++;
	return (counter);
}

static char	*findnext(char *ptr, char c)
{
	while (++ptr)
		if (*(ptr - 1) == c && *ptr != c)
			return (ptr);
	return (NULL);
}

static char	*worddup(char *s, char c)
{
	int		len;
	char	*str;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	if (!(str = ft_strnew(sizeof(char) * len)))
		return (NULL);
	while (len--)
		str[len] = s[len];
	return (str);
}

static void	del(char **as, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (as[i])
			free(as[i]);
	}
	free(as);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**as;
	int		size;
	char	*ptr;
	int		i;

	if (!s)
		return (NULL);
	size = countwords((char *)s, c);
	if (!(as = (char**)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i <= size)
		as[i++] = NULL;
	ptr = s[0] == c ? findnext((char*)s, c) : (char*)s;
	i = -1;
	while (++i < size)
	{
		if (!(as[i] = worddup(ptr, c)))
		{
			del(as, size);
			return (NULL);
		}
		ptr = findnext(ptr, c);
	}
	return (as);
}
