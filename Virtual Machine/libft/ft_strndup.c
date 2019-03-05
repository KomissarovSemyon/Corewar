/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strndup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:55:37 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/23 12:56:56 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *src, size_t num)
{
	char	*dest;
	int		n;

	n = 0;
	if (!(dest = ft_strnew(num)))
		return (NULL);
	return (ft_strncpy(dest, src, num));
}
