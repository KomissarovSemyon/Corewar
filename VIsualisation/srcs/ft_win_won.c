/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_won.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 03:49:52 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/11 06:00:21 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "const_str_big.h"

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
	char	*n_str;
	int		index;
	int		line;
	long	ch;

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
			pos[1] + line * 15, g_colors[get_color_big_str(index, line, i)], n_str);
			index++;
		}
	}
	free(n_str);
}

static void
	get_pos_start(t_data *data, char *name, int pos[2], int vel[2])
{
	double		angle;

	angle = rand() % 100 * (double)M_PI;
	pos[0] = 19 + rand() % (1910 - ft_strlen(name) * 60);
	pos[1] = 19 + rand() % 960;
	vel[0] = 8 * cos(angle);
	vel[1] = 8 * cos(angle);
}

static void
	big_name(t_data *data, char *name, int pos[2])
{
	static double	start;
	static double	delta;

	if (delta == 0)
		delta = -0.01;
	start = start + delta;
	if (start >= (ft_strlen(name) - 31))
		delta = -delta;
	if (start < -1)
		delta = -delta;
	pos[0] = 9 - start * 60;
	pos[1] = 400;
}

static int
	*get_pos(t_data *data, char *name)
{
	static int	pos[2];
	static int	vel[2];
	double		angle;

	if ((ft_strlen(name) * 60) >= (1920 - 60))
	{
		big_name(data, name, pos);
		return (pos);
	}
	if (pos[0] == 0)
		get_pos_start(data, name, pos, vel);
	pos[0] += vel[0];
	pos[1] += vel[1];
	if (pos[0] <= 18 || pos[0] >= (1920 - ft_strlen(name) * 60))
		vel[0] =
		abs(vel[0]) * (1 - 2 * (pos[0] >= (1920 - ft_strlen(name) * 60)));
	if (pos[1] <= 18 || pos[1] >= (865))
		vel[1] = abs(vel[1]) * (1 - 2 * (pos[1] >= (865)));
	return (pos);
}

void
	ft_win_won(t_data *data, char *name)
{
	int			index;
	static int	delta;
	int			shag;
	int			*pos;

	shag = 3;
	if (delta >= 0 && delta <= 49 * shag)
		++delta;
	else
		delta = 0;
	pos = get_pos(data, name);
	index = -1;
	while (name[++index] != '\0')
		if ((pos[0] + index * 60) < 1870 &&
			(pos[0] + index * 60) > 8)
			ft_draw_char_big(data, (int[2]){pos[0] + index * 60, pos[1]},
			name[index], index * 5 + (delta / shag));
}
