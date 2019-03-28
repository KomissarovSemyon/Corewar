/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:25:18 by amerlon-          #+#    #+#             */
/*   Updated: 2018/11/29 17:38:13 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	res = ft_strnew(len);
	if (!s || !res || len > (size_t)ft_strlen(s))
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s[start + i];
	return (res);
}
