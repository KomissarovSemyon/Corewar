/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_DOU.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:29:19 by vferry            #+#    #+#             */
/*   Updated: 2019/02/03 16:12:08 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ml_upo_l(va_list ap)
{
	unsigned int	upo_l;
	char			*str;

	upo_l = va_arg(ap, unsigned long int);
	str = ft_itoabase(upo_l, (unsigned int)8);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}

void	ml_upu_l(va_list ap)
{
	unsigned int	upu_l;
	char			*str;

	upu_l = va_arg(ap, unsigned long int);
	str = ft_itoabase(upu_l, (unsigned int)10);
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}
