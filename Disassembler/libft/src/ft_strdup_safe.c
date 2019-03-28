/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:35:19 by amerlon-          #+#    #+#             */
/*   Updated: 2018/12/11 19:35:35 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_safe(const char *s1)
{
	int		i;
	char	*res;

	if (!s1)
		return (NULL);
	i = -1;
	res = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	res[i] = '\0';
	return (res);
}
