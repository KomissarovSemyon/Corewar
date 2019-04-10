/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:00:33 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/11/30 15:29:47 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_num_len(size_t *minus, long long *t)
{
	size_t		len;
	long long	temp;

	*minus = 0;
	if (*t < 0)
	{
		*minus = 1;
		*t = -*t;
	}
	temp = *t;
	len = 0;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	if (len == 0)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	size_t		len;
	char		*new;
	size_t		minus;
	long long	t;

	t = n;
	len = get_num_len(&minus, &t);
	new = (char *)malloc(sizeof(char) * (len + minus + 1));
	if (!new)
		return (NULL);
	new[len-- + minus] = '\0';
	if (t == 0)
		new[0] = '0';
	while (t != 0)
	{
		new[len-- + minus] = (t % 10) + 48;
		t /= 10;
	}
	if (minus == 1)
		new[0] = '-';
	return (new);
}
