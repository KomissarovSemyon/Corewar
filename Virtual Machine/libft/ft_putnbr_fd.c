/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:44:48 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/28 22:33:32 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;

	if (fd < 0)
		return ;
	sign = n < 0 ? -1 : 1;
	if (sign < 0)
		ft_putchar_fd('-', fd);
	if (n > 9 || n < -9)
		ft_putnbr_fd(n / 10 * sign, fd);
	ft_putchar_fd(n % 10 * sign + '0', fd);
}
