/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:29:58 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/11 18:49:01 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_my_array
	ft_init_my_arr(int color, const char *str)
{
	t_my_array	res;

	res.color = color;
	res.str = ft_strdup(str);
	return (res);
}

static void
	init_arr_double(double arr[2], double p1, double p2)
{
	arr[0] = p1;
	arr[1] = p2;
}

void
	draw_cube_empty(t_data *data, double par[2][2], int color)
{
	double	pos[4][2];

	init_arr_double(pos[0], par[0][0], par[0][1]);
	init_arr_double(pos[1], par[1][0], par[0][1]);
	init_arr_double(pos[2], par[1][0], par[1][1]);
	init_arr_double(pos[3], par[0][0], par[1][1]);
	line_fast(data, pos[0], pos[1], color);
	line_fast(data, pos[1], pos[2], color);
	line_fast(data, pos[2], pos[3], color);
	line_fast(data, pos[3], pos[0], color);
}

void
	ft_start_game(t_data *data)
{
	int		index;

	if ((data->mydata->arr =
	(t_my_array *)malloc(sizeof(t_my_array) * MEM_SIZE)) == NULL)
		ft_close(data);
	data->mydata->run = 2;
	data->mydata->process = NULL;
	data->mydata->param = NULL;
	data->mydata->process_count = 0;
	data->mydata->first_proces = 0;
	data->mydata->active_proces_line = -1;
	data->mydata->active_proces = -1;
	data->mydata->first_reg = 0;
	data->mydata->win = -1;
	index = -1;
	while (++index < MEM_SIZE)
		data->mydata->arr[index] = ft_init_my_arr(0, "00");
	ft_draw_back(data);
}
