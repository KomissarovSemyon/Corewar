/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:46:50 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/02 16:18:45 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	work_with_minus_nbr(int n, int fd)
{
	char	c;

	write(fd, "-", 1);
	if (n == -2147483648)
	{
		write(fd, "2147483648", 10);
	}
	else
	{
		n = -n;
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		c = (n % 10) + 48;
		write(fd, &c, 1);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	char c;

	if (n < 0)
		work_with_minus_nbr(n, fd);
	else
	{
		if (n < 10)
		{
			c = n + 48;
			write(fd, &c, 1);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			c = (n % 10) + 48;
			write(fd, &c, 1);
		}
	}
}
