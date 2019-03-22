/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 07:03:09 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/22 15:26:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "vm.h"

t_my_array
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

static void
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
	set_colors(t_data *data)
{
	data->mydata->color[0] = 0xc0c0c0;
	data->mydata->color[1] = 0x0000ff;
	data->mydata->color[2] = 0x9932cc;
	data->mydata->color[3] = 0xff0000;
	data->mydata->color[4] = 0x00ff00;
	data->mydata->color[5] = 0x00ffff;
}

void
	ft_start_game(t_data *data, char *str, int argc, char **argv)
{
	int		index;
	double	par[2][2];

	if ((data->mydata->arr =
	(t_my_array *)malloc(sizeof(t_my_array) * MEM_SIZE)) == NULL)
		ft_close(data);
	data->mydata->cycles = 0;
	data->mydata->run = 0;
	index = -1;
	while (++index < MEM_SIZE)
		data->mydata->arr[index] = ft_init_my_arr(0, "9f");
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

void
	ft_open_win(char *str, int argc, char **argv)
{
	t_data	data;

	if (((data.mlx_ptr = mlx_init()) == 0) ||
		((data.mlx_win =
		mlx_new_window(data.mlx_ptr, WIN_W, WIN_H, str)) == NULL) ||
		((data.img = (t_img *)malloc(sizeof(t_img))) == NULL) ||
		((data.mydata = (t_mydata *)malloc(sizeof(t_mydata))) == NULL))
		return ;
	mlx_do_key_autorepeaton(data.mlx_ptr);
	mlx_loop_hook(data.mlx_ptr, ft_draw, &data);
	mlx_hook(data.mlx_win, 2, 1L << 2, key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 3, key_release, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, ft_close, &data);
	data.img->img_ptr = mlx_new_image(data.mlx_ptr, WIN_W, WIN_H);
	data.img->data = (int *)mlx_get_data_addr(data.img->img_ptr,
		&data.img->bpp, &data.img->size_l, &data.img->endian);
	ft_start_game(&data, str, argc, argv);
	mlx_loop(data.mlx_ptr);
}
