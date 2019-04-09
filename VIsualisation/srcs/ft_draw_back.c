/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:30:25 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/09 16:32:35 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void
	init_arr_double(double arr[2], double p1, double p2)
{
	arr[0] = p1;
	arr[1] = p2;
}

static void
	set_colors(t_data *data)
{
	data->mydata->color[0] = 0xc0c0c0;
	data->mydata->color[1] = 0x0000ff;
	data->mydata->color[2] = 0x9932cc;
	data->mydata->color[3] = 0xff0000;
	data->mydata->color[4] = 0x00ff00;
	data->mydata->color[5] = 0x00ffff;
	data->mydata->color[6] = 0xc0c000;
	data->mydata->color[7] = 0xc0c000;
	data->mydata->color[8] = 0xc0c000;
	data->mydata->color[9] = 0xc0c000;
}

void
	ft_draw_back(t_data *data)
{
	double	par[2][2];

	init_arr_double(par[0], 8, 8);
	init_arr_double(par[1], 1930, 980);
	draw_cube_empty(data, par, 0xff);
	init_arr_double(par[0], 1940, 8);
	init_arr_double(par[1], WIN_W - 8, 1291);
	draw_cube_empty(data, par, 0xffffff);
	init_arr_double(par[0], 8, 990);
	init_arr_double(par[1], 1930, 1291);
	draw_cube_empty(data, par, 0xffffff);
	set_colors(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->img_ptr, 0, 0);
}
