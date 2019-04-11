/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:08:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/11 18:41:26 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void
	ft_draw_on_game(t_data *data)
{
	int		index;
	int		pos;
	int		size;

	size = 64;
	index = -1;
	while (++index < data->mydata->process_count)
	{
		pos =
		data->mydata->process[index].pc - data->mydata->process[index].map;
		if (data->mydata->active_proces == index)
			mlx_string_put(data->mlx_ptr, data->mlx_win,
			13 + 30 * (pos % size), 10 + 15 * (pos / size), 0xff0000, "__");
		else
			mlx_string_put(data->mlx_ptr, data->mlx_win,
			13 + 30 * (pos % size), 10 + 15 * (pos / size), 0xffffff, "__");
	}
	index = -1;
	while (++index < MEM_SIZE)
	{
		mlx_string_put(data->mlx_ptr, data->mlx_win,
		13 + 30 * (index % size), 10 + 15 * (index / size),
		data->mydata->color[data->mydata->arr[index].color],
		data->mydata->arr[index].str);
	}
}

static void
	ft_update(t_data *data)
{
	if (data->mydata->run)
	{
		ft_update_my_arr(data);
		mlx_string_put(data->mlx_ptr, data->mlx_win,
		WIN_W - 495, 20, 0x00ff00, "< RUN >");
		data->mydata->run = (data->mydata->run == 1);
	}
	else
		mlx_string_put(data->mlx_ptr, data->mlx_win,
		WIN_W - 495, 20, 0xff0000, "< STOP >");
}

static void
	ft_print_info(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->mlx_win, WIN_W - 700, WIN_H - 300,
	0xffffff, "Process");
	ft_out_params(data, (t_win_par){WIN_W - 700, WIN_H - 285, 0xffffff,
	0xffffff, "from:", (data->mydata->first_proces + 1)});
	ft_out_params(data, (t_win_par){WIN_W - 700, WIN_H - 270, 0xffffff,
	0xffffff, "count:", data->mydata->process_count});
	ft_out_params(data, (t_win_par){WIN_W - 500, 50, 0xffffff, 0xffffff,
	"Cycles:", data->mydata->param->current_cycle});
	ft_out_params(data, (t_win_par){WIN_W - 500, 70, 0xffffff, 0xffffff,
	"Players:", data->mydata->param->players});
	ft_out_params(data, (t_win_par){WIN_W - 500, 90, 0xffffff, 0xffffff,
	"cycles_to_die:", data->mydata->param->cycles_to_die});
	ft_out_params(data, (t_win_par){WIN_W - 500, 110, 0xffffff, 0xffffff,
	"last_check:", data->mydata->param->last_check});
	ft_out_params(data, (t_win_par){WIN_W - 500, 130, 0xffffff, 0xffffff,
	"checks:", data->mydata->param->checks});
	ft_out_params(data, (t_win_par){WIN_W - 500, 150, 0xffffff, 0xffffff,
	"live_nbr:", data->mydata->param->live_nbr});
	ft_out_params(data, (t_win_par){WIN_W - 500, 170, 0xffffff, 0xffffff,
	"winner:", data->mydata->param->winner});
}

static void
	ft_print_help(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->mlx_win, WIN_W - 550, WIN_H - 90,
	0xffffff, "use vertical arrows to move register list");
	mlx_string_put(data->mlx_ptr, data->mlx_win, WIN_W - 550, WIN_H - 70,
	0xffffff, "use horizontal arrows to move process list");
	mlx_string_put(data->mlx_ptr, data->mlx_win, WIN_W - 550, WIN_H - 50,
	0xffffff, "use space to stop or make 1 step");
	mlx_string_put(data->mlx_ptr, data->mlx_win, WIN_W - 550, WIN_H - 30,
	0xffffff, "use command to stop or run programm");
}

int
	ft_draw(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->img_ptr, 0, 0);
	ft_update(data);
	ft_print_process(data);
	if (data->mydata->win < 0)
		ft_draw_on_game(data);
	else
		ft_win_won(data,
		data->mydata->param->champs[data->mydata->param->winner - 1].name);
	ft_print_info(data);
	ft_print_help(data);
	ft_print_champs(data, data->mydata->param->champs);
	return (1);
}
