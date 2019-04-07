/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_str_big.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:24:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/07 14:54:15 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int
	get_color_big_str(int x, int y, int step)
{
	int		d;
	int		colors[7] =
	{0xff0000, 0xff7f00, 0xffff00, 0x00ff00, 0x0000ff, 0x4b0082, 0x8f00ff};

	d = (x + y + step) % 7;
	return (colors[d]);
}

void
	ft_draw_char_big(t_data *data, int pos[2], char str, int i)
{
	long	a[33] = { 16695412273, 32801506878, 15620129326, 32801080894,
		33840644639, 33840644624, 15620136494, 18842895921, 33424543903,
		33424544396, 18843847217, 17734058559, 19182175793, 18850958897,
		15621211694, 32801505808, 15621215821, 32801514131, 15620048430,
		33424543876, 18842437166, 18842436932, 18842441585, 18593485137,
		18842429572, 33321787935
		};
	char	*n_str;
	int		index;
	int		line;
	char	ch;

	ch = str;
	if (ch >= 'a' && ch <= 'z')
		ch = ch - 'a';
	else if (ch >= 'A' && ch <= 'Z')
		ch = ch - 'A';
	else
		return ;

	n_str = (char *)malloc(sizeof(char) * 2);
	n_str[1] = '\0';
	line = -1;
	while (++line < 7)
	{
		index = 0;
		while (index < 5)
		{
			printf("%d\n", (index + line * 5));
			n_str[0] = ((a[ch] >> (34 - (index + line * 5))) & 1);
			if (n_str[0] == 0)
				n_str[0] = ' ';
			else
				n_str[0] = '#';
			mlx_string_put(data->mlx_ptr, data->mlx_win, pos[0] + index * 10, pos[1] + line * 15, get_color_big_str(index, line, i), n_str);
			index++;
		}
	}
	free(n_str);
}

void
	ft_draw_str_big(t_data *data, int x, int y, char *str)
{
	int	index;
	static int delta;

	if (delta >= 0 && delta <= 70)
		++delta;
	else
		delta = 0;
	index = -1;
	while (str[++index] != '\0')
		ft_draw_char_big(data, (int[2]){x + index * 60, y}, str[index], index * 5 + (delta / 10));
}
