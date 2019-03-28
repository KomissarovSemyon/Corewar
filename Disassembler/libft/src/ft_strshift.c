/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:22:23 by amerlon-          #+#    #+#             */
/*   Updated: 2018/12/04 21:19:00 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strshift(char **str, size_t n)
{
	char	*res;

	if (!str || !(*str))
		return (NULL);
	res = ft_strsub(*str, n, ft_strlen(*str) - n);
	if (!res)
		return (NULL);
	free(*str);
	*str = NULL;
	return (res);
}
