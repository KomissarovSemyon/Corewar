/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_won.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 03:49:52 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/11 04:54:28 by rrhaenys         ###   ########.fr       */
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
	ft_win_won(t_data *data, char *name)
{
	static int	pos[2];
	static int	vel[2];
	static int	step;
	double		angle;

	if (pos[0] == 0)
	{
		angle = rand() % 360;
		pos[0] = 9 + rand() % 1920;
		pos[1] = 9 + rand() % 970;
		vel[0] = 1 * cos(angle);
		vel[1] = 1 * cos(angle);
	}
	pos[0] += vel[0];
	pos[1] += vel[1];
	ft_printf("ft_strlen = %d (%d) %d\n", ft_strlen(name), ft_strlen(name) * 60, 1930 - ft_strlen(name) * 60);
	if ((ft_strlen(name) * 60) >= (1930 - 60))
	{
		pos[0] = 9;
		pos[1] = 9;
	}
	else
	{
		if (pos[0] <= 8 || pos[0] >= (1930 - ft_strlen(name) * 60 - 10))
			vel[0] = abs(vel[0]) * (1 - 2 * (pos[0] >= (1930 - ft_strlen(name) * 60 - 10)));
		if (pos[1] <= 8 || pos[1] >= (980 - 100))
			vel[1] = abs(vel[1]) * (1 - 2 * (pos[1] >= (980 - 100)));
	}
	int			index;
	static int	delta;
	int			shag;

	shag = 3;
	if (delta >= 0 && delta <= 49 * shag)
		++delta;
	else
		delta = 0;
	index = -1;
	while (name[++index] != '\0')
		ft_draw_char_big(data, (int[2]){pos[0] + index * 60, pos[1]},
		name[index], index * 5 + (delta / shag));
}