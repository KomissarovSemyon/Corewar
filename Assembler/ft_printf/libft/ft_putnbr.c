/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:17:09 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/02 16:13:11 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	work_with_minus(int n)
{
	char	c;

	write(1, "-", 1);
	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
	}
	else
	{
		n = -n;
		if (n >= 10)
			ft_putnbr(n / 10);
		c = (n % 10) + 48;
		write(1, &c, 1);
	}
}

void			ft_putnbr(int n)
{
	char	c;

	if (n < 0)
		work_with_minus(n);
	else
	{
		if (n < 10)
		{
			c = n + 48;
			write(1, &c, 1);
		}
		else
		{
			ft_putnbr(n / 10);
			c = (n % 10) + 48;
			write(1, &c, 1);
		}
	}
}
