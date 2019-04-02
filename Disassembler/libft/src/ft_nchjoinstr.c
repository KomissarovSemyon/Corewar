/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nchjoinstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:29:35 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/26 18:45:40 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nchjoinstr(char c, int n, char **str, int flag)
{
	char	*res;
	int		i;
	int		j;

	if (!str || !(*str))
		return (NULL);
	res = ft_strnew(ft_strlen(*str) + n);
	j = -1;
	while (n--)
		res[++j] = c;
	i = -1;
	while ((*str)[++i])
		res[++j] = (*str)[i];
	if (flag)
		ft_strdel(str);
	return (res);
}
