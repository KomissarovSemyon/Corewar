/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rebase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:56:48 by rgyles            #+#    #+#             */
/*   Updated: 2019/03/22 20:03:48 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	get_size(unsigned long long n, int base)
{
	int index;

	index = 0;
	while (n > 0)
	{
		index++;
		n /= base;
	}
	return (index);
}

char		*ft_rebase(unsigned long long n, int base)
{
	char	*str;
	char	*res;
	int		index;

	str = "0123456789abcdef";
	if ((res = (char *)malloc(sizeof(char) * (get_size(n, base) + 1))) == NULL)
		return (NULL);
	index = get_size(n, base) + 1;
	res[--index] = '\0';
	if (n == 0)
		res[index] = '0';
	while (n > 0)
	{
		res[--index] = str[n % base];
		n /= base;
	}
	return (res);
}
