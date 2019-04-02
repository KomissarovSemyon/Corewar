/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:39:08 by amerlon-          #+#    #+#             */
/*   Updated: 2018/11/30 18:22:08 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	check;

	check = 0;
	if (size == check - 1)
		return (NULL);
	res = ft_memalloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	return (res);
}
