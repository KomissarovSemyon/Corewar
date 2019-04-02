/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:21:30 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/11/26 14:02:51 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	if (size == 0)
		return (NULL);
	new = (void *)malloc(size);
	if (!new)
		return (NULL);
	while (size > 0)
	{
		((char *)new)[size - 1] = 0;
		size--;
	}
	return (new);
}
