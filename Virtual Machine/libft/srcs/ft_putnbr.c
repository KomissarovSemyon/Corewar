/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:42:16 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/25 14:02:42 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(int n)
{
	int		sign;

	sign = n < 0 ? -1 : 1;
	if (sign == -1)
		ft_putchar('-');
	if (n > 9 || n < -9)
		ft_putnbr(n / 10 * sign);
	ft_putchar(n % 10 * sign + '0');
}
