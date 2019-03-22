/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:08:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/22 20:25:19 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "vm.h"

void		line_fast(t_data *env, double *p1, double *p2, int color)
{
	int i;
	int x[2];
	int p[2];

	x[0] = abs((int)(p2[Y_P] - p1[Y_P])) >> 1;
	x[1] = abs((int)(p2[X_P] - p1[X_P])) >> 1;
	ft_draw_px(env, (p[0] = p1[X_P]),
				(p[1] = p1[Y_P]), color);
	if (((i = -1) == -1) && abs((int)(p2[X_P] - p1[X_P])) >=
		abs((int)(p2[Y_P] - p1[Y_P])))
		while (++i < abs((int)(p2[X_P] - p1[X_P])))
		{
			BLOCK_2(x[1], abs((int)(p2[X_P] - p1[X_P])), p[1],
			SGN(p2[Y_P] - p1[Y_P]), abs((int)(p2[Y_P] - p1[Y_P])));
			ft_draw_px(env, (p[0] += SGN(p2[X_P] - p1[X_P])), p[1], color);
		}
	else
		while (++i < abs((int)(p2[Y_P] - p1[Y_P])))
		{
			BLOCK_2(x[0], abs((int)(p2[Y_P] - p1[Y_P])), p[0],
			SGN(p2[X_P] - p1[X_P]), abs((int)(p2[X_P] - p1[X_P])));
			ft_draw_px(env, p[0], (p[1] += SGN(p2[Y_P] - p1[Y_P])), color);
		}
}

void		ft_draw_px(t_data *data, int x, int y, int color)
{
	data->img->data[y * WIN_W + x] = color;
}

void		line_vertical(t_data *data, int x, int *y, int color)
{
	int	ind_y;

	ind_y = y[0] - 1;
	while (++ind_y <= y[1])
		data->img->data[ind_y * WIN_H + x] = color;
}

void		ft_linefast_int(t_data *data, int *p1, int *p2, int color)
{
	double	f1[2];
	double	f2[2];

	f1[0] = p1[0];
	f1[1] = p1[1];
	f2[0] = p2[0];
	f2[1] = p2[1];
	line_fast(data, f1, f2, color);
}

void		draw_cube_size(t_data *data, int x, int y, int color, double size)
{
	int		pos[2];
	int		colors[5];

	colors[0] = 0xc0c0c0;
	colors[1] = 0x0000ff;
	colors[2] = 0x9932cc;
	colors[3] = 0xff0000;
	colors[4] = 0x00ff00;
	pos[0] = 20 + x * 20;
	pos[1] = 20 + y * 20;
	while (size > 1)
		size -= 1.0;
	ft_draw_square(data, pos, 10, 0x008000);
	ft_draw_square(data, pos, 9 * size, colors[color]);
}

void		draw_cube(t_data *data, int x, int y, int color)
{
	draw_cube_size(data, x, y, color, 1);
}

void		draw_cube_active(t_data *data, int x, int y, int color)
{
	int		pos[2];
	int		colors[5];

	colors[0] = 0xc0c0c0;
	colors[1] = 0x0000ff;
	colors[2] = 0x9932cc;
	colors[3] = 0xff0000;
	colors[4] = 0x00ff00;
	pos[0] = 20 + x * 20;
	pos[1] = 20 + y * 20;
	ft_draw_square(data, pos, 10, 0xffff00);
	ft_draw_square(data, pos, 8, colors[color]);
}

void		ft_update_my_arr(t_data *data)
{
	int			magic;
	t_param		param;
	int			i;
	char		*str;

	read(0, &magic, sizeof(int));
	++data->mydata->cycles;
	if (magic != VIS_MAGIC)
		exit(0);
	read(0, &param, sizeof(t_param));
	i = -1;
	while (++i < MEM_SIZE)
	{
		free(data->mydata->arr[i].str);
		data->mydata->arr[i].str = ft_rebase(param.map[i], 16);
		ft_printf("%d\n", param.map[i]);
		if (ft_strlen(data->mydata->arr[i].str) == 1)
		{
			str = ft_strdup("00");
			str[1] = data->mydata->arr[i].str[0];
			free(data->mydata->arr[i].str);
			data->mydata->arr[i].str = str;
		}
		data->mydata->arr[i].color = param.map_color[i];
	}
	// i = -1;
	// while (++i < param.proc_nbr)
	// {
	// 	process_new(&param, NULL, param.map);
	// 	read(0, param.process, sizeof(t_process));
	// }
}

int			ft_draw(t_data *data)
{
	int		index;
	char	*str;
	int		size;

	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->img_ptr, 0, 0);
	ft_update_my_arr(data);
	index = -1;
	size = 64;
	while (++index < MEM_SIZE)
	{
		mlx_string_put(data->mlx_ptr, data->mlx_win,
		13 + 30 * (index % size), 10 + 15 * (index / size),
		data->mydata->color[data->mydata->arr[index].color],
		data->mydata->arr[index].str);
	}
	mlx_string_put(data->mlx_ptr, data->mlx_win,
	WIN_W - 500, 50, 0xffffff, "Cycles:");
	str = ft_itoa(data->mydata->cycles);
	mlx_string_put(data->mlx_ptr, data->mlx_win,
	WIN_W - 430, 50, 0xffffff, str);
	free(str);
	if (data->mydata->run == 0)
		mlx_string_put(data->mlx_ptr, data->mlx_win,
		WIN_W - 500, 20, 0xff0000, "< STOP >");
	else
		mlx_string_put(data->mlx_ptr, data->mlx_win,
		WIN_W - 495, 20, 0x00ff00, "< RUN >");
	return (1);
}