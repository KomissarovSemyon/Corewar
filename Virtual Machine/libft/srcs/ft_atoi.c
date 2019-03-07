/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 01:04:18 by jcorwin           #+#    #+#             */
/*   Updated: 2019/01/01 02:20:55 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int			ft_isdigit_base(char *c, int base)
{
	int		num;

	if (*c >= 'a' && *c <= 'z')
		*c = *c - 'a' + 'A';
	if (*c >= '0' && *c <= '9')
		num = *c - '0';
	else if (*c >= 'A' && *c <= 'Z')
		num = *c - 'A' + 10;
	else
		return (0);
	return (num < base ? 1 : 0);
}

int			ft_atoi(const char *str)
{
	unsigned long long	n;
	unsigned long long	maxll;
	int					sign;

	maxll = 9223372036854775807;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\r' ||
			*str == '\f' || *str == '\n' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-' ? -1 : 1;
	n = 0;
	while (ft_isdigit((int)*str))
		if ((n = n * 10 + *str++ - '0') >
			(unsigned long long)(sign == 1 ? maxll : ~maxll))
			return (sign == 1 ? -1 : 0);
	return ((int)(n * sign));
}

int			ft_atoi_base(const char *str, int base)
{
	unsigned long long	n;
	unsigned long long	maxll;
	int					sign;
	unsigned long long	digit;
	char				c;

	maxll = 9223372036854775807;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\r' ||
			*str == '\f' || *str == '\n' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-' ? -1 : 1;
	n = 0;
	c = *str++;
	while (ft_isdigit_base(&c, base))
	{
		digit = (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
		if ((n = n * base + digit) >
				(unsigned long long)(sign == 1 ? maxll : ~maxll))
			return (sign == 1 ? -1 : 0);
		c = *str++;
	}
	return ((int)(n * sign));
}
