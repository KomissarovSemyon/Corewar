/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_won.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 03:49:52 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/11 18:54:01 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void
	get_pos_start(char *name, int pos[2], int vel[2])
{
	double		angle;

	angle = rand() % 100 * (double)M_PI;
	pos[0] = 19 + rand() % (1910 - ft_strlen(name) * 60);
	pos[1] = 19 + rand() % 960;
	vel[0] = 8 * cos(angle);
	vel[1] = 8 * cos(angle);
}

static void
	big_name(char *name, int pos[2])
{
	static double	start;
	static double	delta;

	if (delta == 0)
		delta = -0.04;
	start = start + delta;
	if (start >= (ft_strlen(name) - 29))
		delta = -delta;
	if (start < -3)
		delta = -delta;
	pos[0] = 9 - start * 60;
	pos[1] = 400;
}

static int
	*get_pos(char *name)
{
	static int	pos[2];
	static int	vel[2];

	if ((ft_strlen(name) * 60) >= (1920 - 60))
	{
		big_name(name, pos);
		return (pos);
	}
	if (pos[0] == 0)
		get_pos_start(name, pos, vel);
	pos[0] += vel[0];
	pos[1] += vel[1];
	if (pos[0] <= 18 || pos[0] >= (1920 - (int)ft_strlen(name) * 60))
		vel[0] =
		abs(vel[0]) * (1 - 2 * (pos[0] >= (1920 - (int)ft_strlen(name) * 60)));
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
	pos = get_pos(name);
	index = -1;
	while (name[++index] != '\0')
		if ((pos[0] + index * 60) < 1870 &&
			(pos[0] + index * 60) > 8)
			ft_draw_char_big(data, (int[2]){pos[0] + index * 60, pos[1]},
			name[index], index * 5 + (delta / shag));
}
