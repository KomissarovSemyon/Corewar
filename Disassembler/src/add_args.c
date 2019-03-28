/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 23:03:55 by amerlon-          #+#    #+#             */
/*   Updated: 2019/03/28 14:23:08 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassemble.h"

void	add_reg(char *str, unsigned char byte)
{
	char	tmp[3];

	ft_strcat(str, "r");
	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = 0;
	if (byte < 10)
		tmp[0] = byte % 10 + '0';
	else
	{
		tmp[0] = byte / 10 + '0';
		tmp[1] = byte % 10 + '0';
	}
	ft_strcat(str, tmp);
}

int		add_dir(char *str, char cmd, unsigned char *bytes)
{
	char	*tmp;
	char	c[2];
	int		len[2];

	if (cmd == 9 || cmd == 10 || cmd == 11 ||
		cmd == 12 || cmd == 14 || cmd == 15)
		len[0] = 2;
	else
		len[0] = 4;
	c[0] = bytes[0];
	bytes[0] = bytes[len[0] - 1];
	bytes[len[0] - 1] = c[0];
	if (len[0] == 4)
	{
		c[0] = bytes[1];
		bytes[1] = bytes[len[0] - 2];
		bytes[len[0] - 2] = c[0];
	}
	len[1] = len[0] == 2 ? (*((short *)bytes)) : (*((int *)bytes));
	tmp = ft_ltoa_base(len[1], 10);
	c[0] = DIRECT_CHAR;
	c[1] = 0;
	ft_strcat(ft_strcat(str, c), tmp);
	ft_strdel(&tmp);
	return (len[0]);
}

int		add_ind(char *str, unsigned char *bytes)
{
	char	*tmp;
	char	c;
	short	nbr;

	c = bytes[0];
	bytes[0] = bytes[1];
	bytes[1] = c;
	nbr = *((short *)bytes);
	tmp = ft_ltoa_base(nbr, 10);
	ft_strcat(str, tmp);
	ft_strdel(&tmp);
	return (2);
}

void	add_args(char *str, char cmd, unsigned char *bytes, unsigned char args)
{
	char	sep[2];
	int		i;
	int		j;

	i = 0;
	j = 0;
	sep[0] = SEPARATOR_CHAR;
	sep[1] = 0;
	while ((unsigned char)(args << i) >> 6)
	{
		if ((unsigned char)(args << i) >> 6 == REG_CODE)
			add_reg(str, bytes[j++]);
		if ((unsigned char)(args << i) >> 6 == DIR_CODE)
			j += add_dir(str, cmd, bytes + j);
		if ((unsigned char)(args << i) >> 6 == IND_CODE)
			j += add_ind(str, bytes + j);
		i += 2;
		if (((unsigned char)(args << i) >> 6))
			ft_strcat(str, sep);
	}
}
