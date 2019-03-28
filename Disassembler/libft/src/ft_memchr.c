/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:06:50 by amerlon-          #+#    #+#             */
/*   Updated: 2018/11/27 20:02:22 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ns;
	size_t			i;

	i = -1;
	ns = (unsigned char *)s;
	while (++i < n)
		if (ns[i] == (unsigned char)c)
			return (ns + i);
	return (NULL);
}
