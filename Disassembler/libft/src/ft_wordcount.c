/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:22:28 by amerlon-          #+#    #+#             */
/*   Updated: 2018/12/01 16:13:15 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *str, char del)
{
	int	i;
	int	wc;
	int	flag;

	if (!str || del == '\0')
		return (-1);
	i = -1;
	wc = 0;
	flag = 0;
	while (str[++i])
	{
		if (str[i] == del)
			flag = 0;
		else if (!flag)
		{
			flag = 1;
			wc++;
		}
	}
	return (wc);
}
