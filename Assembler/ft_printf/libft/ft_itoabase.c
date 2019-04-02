/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:38:02 by vferry            #+#    #+#             */
/*   Updated: 2018/12/03 13:50:44 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_simbol(unsigned int a, unsigned int range)
{
	char	s;

	if ((a % range) == 5)
		s = '5';
	if ((a % range) == 6)
		s = '6';
	if ((a % range) == 7)
		s = '7';
	if ((a % range) == 8)
		s = '8';
	if ((a % range) == 9)
		s = '9';
	if ((a % range) == 10)
		s = 'A';
	if ((a % range) == 11)
		s = 'B';
	if ((a % range) == 12)
		s = 'C';
	if ((a % range) == 13)
		s = 'D';
	if ((a % range) == 14)
		s = 'E';
	if ((a % range) == 15)
		s = 'F';
	return (s);
}

static char	*ft_zapis(unsigned int a, unsigned int range, size_t len)
{
	char	*s;
	size_t	i;

	i = -1;
	if (!(s = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (++i < len)
	{
		if ((a % range) == 0)
			s[i] = '0';
		if ((a % range) == 1)
			s[i] = '1';
		if ((a % range) == 2)
			s[i] = '2';
		if ((a % range) == 3)
			s[i] = '3';
		if ((a % range) == 4)
			s[i] = '4';
		if ((a % range) > 4)
			s[i] = ft_simbol(a, range);
		a = a / range;
	}
	s[i] = 0;
	return (s);
}

static char	*ft_perezapis(char *s, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)malloc(sizeof(char) * len + 1);
	while (len--)
	{
		str[i] = s[len];
		i++;
	}
	s[i] = 0;
	return (str);
}

char		*ft_itoabase(unsigned int a, unsigned int range)
{
	char				*str;
	size_t				len;
	unsigned int		a1;

	len = 1;
	a1 = a;
	while ((a1 / range) != 0)
	{
		a1 = a1 / range;
		len++;
	}
	str = ft_perezapis(ft_zapis(a, range, len), len);
	return (str);
}
