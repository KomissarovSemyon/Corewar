/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_csp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:37:45 by vferry            #+#    #+#             */
/*   Updated: 2019/02/01 15:34:26 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_l_c(va_list ap)
{
	unsigned int	c;
	char			*str;
	size_t			size;

	c = va_arg(ap, unsigned int);
	str = conver(c, &size);
	info_add_strn(str, size, 1);
}

void	type_l_s(va_list ap)
{
	unsigned int	*s;
	size_t			i;
	char			*t2;
	size_t			size;

	i = 0;
	s = va_arg(ap, unsigned int *);
	if (s[0] == 0)
		info_add_strn("", 0, 1);
	while (s[i])
	{
		if (s[i] == 0)
			g_info.len++;
		t2 = conver(s[i], &size);
		info_add_strn(t2, size, 0);
		ft_strdel(&t2);
		i++;
	}
}

void	type_s(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		info_add_strn("(null)", 6, 1);
	else
		info_add_strn(str, ft_strlen(str), 1);
}

void	type_p(va_list ap)
{
	char	*str;
	size_t	p;
	int		i;

	i = 0;
	p = va_arg(ap, size_t);
	str = ft_itoabase_size_p(p, 16);
	if ((g_info.accuracy->data && g_info.accuracy->data[0] == '0'))
		str[0] = 0;
	else
		while (str[i])
		{
			str[i] = ft_tolower(str[i]);
			i++;
		}
	g_info.side = 0;
	info_add_strn("0x", 2, 1);
	info_add_strn(str, ft_strlen(str), 0);
}

void	type_c(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	info_add_strn(&c, 1, 1);
}
