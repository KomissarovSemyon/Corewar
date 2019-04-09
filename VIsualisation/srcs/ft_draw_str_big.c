/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_str_big.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:24:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/09 16:55:58 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "const_str_big.h"

int
	get_color_big_str(int x, int y, int step)
{
	int		d;

	d = (x + y + step) % (7 * 7);
	return (g_colors[d / 7]);
}

static long
	ft_get_ch(t_data *data, char str)
{
	long	error;
	long	ch;

	error = 31;
	ch = error;
	if (str >= 'a' && str <= 'z')
		ch = g_chars[str - 'a'];
	else if (str >= 'A' && str <= 'Z')
		ch = g_chars[str - 'A'];
	else if (str >= '0' && str <= '9')
		ch = g_nums[str - '0'];
	return (ch);
}

void
	ft_draw_char_big(t_data *data, int pos[2], char str, int i)
{
	long	error;
	char	*n_str;
	int		index;
	int		line;
	long	ch;

	error = 31;
	ch = ft_get_ch(data, str);
	n_str = (char *)malloc(sizeof(char) * 2);
	n_str[1] = '\0';
	line = -1;
	while (++line < 7)
	{
		index = 0;
		while (index < 5)
		{
			n_str[0] = ((ch >> (34 - (index + line * 5))) & 1);
			n_str[0] = ' ' * (n_str[0] == 0) + '#' * (n_str[0] != 0);
			mlx_string_put(data->mlx_ptr, data->mlx_win, pos[0] + index * 10,
			pos[1] + line * 15, get_color_big_str(index, line, i), n_str);
			index++;
		}
	}
	free(n_str);
}

void
	ft_draw_str_big(t_data *data, int x, int y, char *str)
{
	int			index;
	static int	delta;
	int			shag;

	shag = 3;
	if (delta >= 0 && delta <= 49 * shag)
		++delta;
	else
		delta = 0;
	index = -1;
	while (str[++index] != '\0')
		ft_draw_char_big(data, (int[2]){x + index * 60, y},
		str[index], index * 5 + (delta / shag));
}
