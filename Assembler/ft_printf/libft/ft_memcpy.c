/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:58:45 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/03 16:07:28 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	void	*temp;

	if (!dst && !src)
		return (NULL);
	i = 0;
	temp = dst;
	while (n > 0)
	{
		*((char *)temp) = *((char *)src);
		n--;
		temp++;
		src++;
	}
	return (dst);
}
