/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:08:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/18 03:10:46 by rrhaenys         ###   ########.fr       */
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

int			ft_draw(t_data *data)
{
	int		index;
	char	*str;

	index = 0;
	draw_cube(data, 1, 2, 1);
	draw_cube(data, 1, 3, 2);
	draw_cube(data, 1, 4, 3);
	draw_cube(data, 1, 5, 4);
	draw_cube_active(data, 3, 2, 1);
	draw_cube_active(data, 3, 3, 1);
	draw_cube(data, 3, 3, 1);
	while (++index <= 10)
	{
		draw_cube_size(data, 2, index, 2, index / 10.0);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->img_ptr, 0, 0);
	mlx_string_put(data->mlx_ptr, data->mlx_win,
	WIN_W - 700, 50, 0xffffff, "Cycles:");
	if (data->mydata->run != 0)
		++data->mydata->cycles;
	str = ft_itoa(data->mydata->cycles);
	mlx_string_put(data->mlx_ptr, data->mlx_win,
	WIN_W - 630, 50, 0xffffff, str);
	free(str);
	if (data->mydata->run == 0)
		mlx_string_put(data->mlx_ptr, data->mlx_win,
		WIN_W - 700, 20, 0xff0000, "< STOP >");
	else
		mlx_string_put(data->mlx_ptr, data->mlx_win,
		WIN_W - 695, 20, 0x00ff00, "< RUN >");
	return (1);
}
