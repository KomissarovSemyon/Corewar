/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:02:28 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/11 16:51:43 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	prepear(const char *str, int *minus)
{
	int		i;

	i = 0;
	*minus = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
		(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		*minus = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	long int	n;
	int			i;
	int			minus;
	int			count;

	n = 0;
	count = 0;
	i = prepear(str, &minus);
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		count++;
		n = 10 * n + (str[i] - '0');
		if ((n < 0 || count > 19) && minus == 0)
			return (-1);
		if ((n < 0 || count > 19) && minus == 1)
			return (0);
		i++;
	}
	if (minus == 1)
		return ((int)-n);
	return ((int)n);
}
