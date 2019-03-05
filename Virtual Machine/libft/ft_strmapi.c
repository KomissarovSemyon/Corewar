/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:50:04 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/28 22:38:30 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	if (!(str = ft_strnew((size_t)ft_strlen(s))))
		return (NULL);
	i = 0;
	while (*s)
	{
		str[i] = f(i, *s++);
		i++;
	}
	return (str);
}
