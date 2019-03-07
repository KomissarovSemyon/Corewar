/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:44:42 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/29 21:38:17 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

long long int	ft_atoll(const char *str)
{
	unsigned long long	n;
	unsigned long long	maxll;
	int					sign;
	int					i;

	i = -1;
	maxll = 1;
	while (++i < 62)
		maxll |= maxll << 1;
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
	return ((long long)(n * sign));
}
