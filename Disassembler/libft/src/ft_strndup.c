/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:38:01 by amerlon-          #+#    #+#             */
/*   Updated: 2018/12/04 21:42:02 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*res;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	len = n < len ? n : len;
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s1[i];
	return (res);
}
