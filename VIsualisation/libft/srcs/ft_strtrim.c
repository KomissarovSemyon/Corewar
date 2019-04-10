/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:34:06 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/27 20:03:32 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*str;
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	len = 0;
	i = 0;
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i < len ? len - i + 1 : 1))))
		return (NULL);
	ptr = str;
	while (i < len)
		*ptr++ = s[i++];
	*ptr = '\0';
	return (str);
}
