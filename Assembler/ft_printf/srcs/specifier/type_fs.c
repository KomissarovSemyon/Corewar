/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_fs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:43:09 by vferry            #+#    #+#             */
/*   Updated: 2019/02/04 19:46:48 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	izm_dop(char **str, int i, char *lol)
{
	lol[i] = '1';
	*str = ft_strjoin("-", lol);
	ft_strdel(&lol);
}

static void	izm(char **str)
{
	int		i;
	char	*lol;

	i = ft_strlen(*str) - 1;
	lol = *str;
	while (i >= 0)
		if (lol[i] == '-')
			izm_dop(str, i, lol);
		else if (lol[i] == '.' && i != 0)
			i--;
		else if (lol[i] == '9')
		{
			lol[i] = '0';
			if (i == 0)
			{
				*str = ft_strjoin("1", lol);
				ft_strdel(&lol);
			}
			i--;
		}
		else
		{
			lol[i] += 1;
			break ;
		}
}

static char	*ac_null_izm(char *str, long double f)
{
	int		w;

	f = f - (unsigned long long)f;
	if ((w = (int)(f * 10) % 10) >= 5)
		izm(&str);
	return (str);
}

static char	*stepen(int step, long double f, char **str)
{
	int		i;
	char	*new;
	char	*buff;
	int		w;

	i = 0;
	new = *str;
	while (i < step)
	{
		buff = new;
		f = f * 10;
		if (i + 1 == step && (w = (int)(f * 10) % 10) >= 5 &&
			(f += 1) >= 10.0)
		{
			izm(&new);
			f = f - 10.0;
		}
		new = ft_strjoin(new, ft_itoa((int)f));
		f = f - (int)f;
		ft_strdel(&buff);
		i++;
	}
	return (new);
}

void		new_f(long double d, long double f, int accuracy)
{
	char	*t;
	char	*str;

	t = ft_itoabasell((unsigned long long)d, 10);
	if (f < 0)
	{
		f = -f;
		str = ft_strjoin("-", t);
		ft_strdel(&t);
		t = str;
	}
	if (accuracy != 0)
	{
		f = f - (unsigned long long)f;
		str = ft_strjoin(t, ".");
		ft_strdel(&t);
		str = (stepen(accuracy, f, &str));
	}
	else
	{
		str = ac_null_izm(t, f);
		ft_strdel(&t);
	}
	info_add_strn(str, ft_strlen(str), 1);
	ft_strdel(&str);
}
