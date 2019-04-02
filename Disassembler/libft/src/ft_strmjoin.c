/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 02:01:06 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/17 02:07:40 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mstrjoin(char **s1, char **s2, int flag)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2 || !(*s1) || !(*s2))
		return (NULL);
	if (!(res = ft_strnew(ft_strlen(*s1) + ft_strlen(*s2))))
		return (NULL);
	i = -1;
	while ((*s1)[++i])
		res[i] = (*s1)[i];
	j = -1;
	while ((*s2)[++j])
		res[i++] = (*s2)[j];
	if (flag == 1 || flag > 2)
		ft_strdel(s1);
	if (flag >= 2)
		ft_strdel(s2);
	return (res);
}
