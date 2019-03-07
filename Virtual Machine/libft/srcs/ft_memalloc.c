/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:08:04 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/25 21:18:25 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	if (size == 0)
		return (NULL);
	if (!(mem = (void *)malloc(size)))
		return (NULL);
	i = 0;
	ft_bzero(mem, size);
	return (mem);
}
