/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:45:37 by jcorwin           #+#    #+#             */
/*   Updated: 2019/01/18 16:18:32 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pr_atoi(char **str)
{
	unsigned long	n;
	unsigned int	maxi;

	maxi = 0x7FFFFFFF;
	n = 0;
	while (pr_isdigit((int)**str))
	{
		if ((n = n * 10 + **str - '0') > (unsigned long)maxi)
		{
			while (pr_isdigit((int)**str))
				++(*str);
			return (-1);
		}
		++(*str);
	}
	return ((int)(n));
}
