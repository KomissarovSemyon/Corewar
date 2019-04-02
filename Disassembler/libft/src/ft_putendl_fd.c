/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:12:03 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/27 09:12:38 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl_fd(char const *s, int fd)
{
	int	i;

	if (!s)
		return (-1);
	i = -1;
	while (s[++i])
		write(fd, s + i, 1);
	write(fd, "\n", 1);
	return (i + 1);
}
