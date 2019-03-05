/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:01:12 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/25 13:50:47 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char*)s1;
	ptr2 = (char*)s2;
	while (n--)
		if (*ptr1++ != *ptr2++)
			return ((unsigned char)*(ptr1 - 1) - (unsigned char)*(ptr2 - 1));
	return (0);
}
