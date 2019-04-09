/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:08:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/09 17:36:32 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void
	ft_print_champs(t_data *data, int x, int y, t_champ *champs, int color)
{
	mlx_string_put(data->mlx_ptr, data->mlx_win, x, y, 0xffffff, "Name:");
	mlx_string_put(data->mlx_ptr, data->mlx_win, x + 80, y, color,
	champs->name);
	mlx_string_put(data->mlx_ptr, data->mlx_win, x, y + 15, 0xffffff,
	"Comment:");
	mlx_string_put(data->mlx_ptr, data->mlx_win, x + 80, y + 15, 0x00ff00,
	champs->comment);
	ft_out_params(data, (t_win_par){x, y + 30, 0xffffff, 0x00ff00,
	"champ_size:", champs->champ_size});
}

int
	ft_draw(t_data *data)
{
	int		index;
	int		size;
	int		pos;
	int		delta;

	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->img_ptr, 0, 0);
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
	size = 64;
	index = data->mydata->first_proces - 1;
	mlx_string_put(data->mlx_ptr, data->mlx_win, WIN_W - 700, WIN_H - 300, 0xffffff, "Process");
	ft_out_params(data, (t_win_par){WIN_W - 700, WIN_H - 285, 0xffffff, 0xffffff, "from:", (data->mydata->first_proces + 1)});
	ft_out_params(data, (t_win_par){WIN_W - 700, WIN_H - 270, 0xffffff, 0xffffff, "count:", data->mydata->process_count});
	data->mydata->active_proces = -1;
	delta = 0;
	while (++index < data->mydata->process_count && index < data->mydata->first_proces + 14)
	{
		while (ft_get_process_id(data, index + delta) == NULL)
			++delta;
		ft_print_proces(data, 13 + 125 * (index - data->mydata->first_proces), WIN_H - 310, ft_get_process_id(data, index + delta), ((index - data->mydata->first_proces) == data->mydata->active_proces_line));
		if (data->mydata->active_proces_line == (index - data->mydata->first_proces))
			data->mydata->active_proces = data->mydata->process_count - 1 - index + delta;
	}
	index = -1;
	if (data->mydata->win < 0)
		while (++index < data->mydata->process_count)
		{
			pos = data->mydata->process[index].pc - data->mydata->process[index].map;
			if (data->mydata->active_proces == index)
				mlx_string_put(data->mlx_ptr, data->mlx_win, 13 + 30 * (pos % size), 10 + 15 * (pos / size), 0xff0000, "__");
			else
				mlx_string_put(data->mlx_ptr, data->mlx_win, 13 + 30 * (pos % size), 10 + 15 * (pos / size), 0xffffff, "__");
		}
	index = -1;
	if (data->mydata->win < 0)
		while (++index < MEM_SIZE)
		{
			mlx_string_put(data->mlx_ptr, data->mlx_win,
			13 + 30 * (index % size), 10 + 15 * (index / size),
			data->mydata->color[data->mydata->arr[index].color],
			data->mydata->arr[index].str);
		}
	ft_out_params(data, (t_win_par){WIN_W - 500, 50, 0xffffff, 0xffffff, "Cycles:", data->mydata->param->current_cycle});
	ft_out_params(data, (t_win_par){WIN_W - 500, 70, 0xffffff, 0xffffff, "Players:", data->mydata->param->players});
	ft_out_params(data, (t_win_par){WIN_W - 500, 90, 0xffffff, 0xffffff, "cycles_to_die:", data->mydata->param->cycles_to_die});
	ft_out_params(data, (t_win_par){WIN_W - 500, 110, 0xffffff, 0xffffff, "last_check:", data->mydata->param->last_check});
	ft_out_params(data, (t_win_par){WIN_W - 500, 130, 0xffffff, 0xffffff, "checks:", data->mydata->param->checks});
	ft_out_params(data, (t_win_par){WIN_W - 500, 150, 0xffffff, 0xffffff, "live_nbr:", data->mydata->param->live_nbr});
	ft_out_params(data, (t_win_par){WIN_W - 500, 170, 0xffffff, 0xffffff, "winner:", data->mydata->param->winner});

	mlx_string_put(data->mlx_ptr, data->mlx_win, WIN_W - 550, WIN_H - 90, 0xffffff, "use vertical arrows to move register list");
	mlx_string_put(data->mlx_ptr, data->mlx_win, WIN_W - 550, WIN_H - 70, 0xffffff, "use horizontal arrows to move process list");
	mlx_string_put(data->mlx_ptr, data->mlx_win, WIN_W - 550, WIN_H - 50, 0xffffff, "use space to stop or make 1 step");
	mlx_string_put(data->mlx_ptr, data->mlx_win, WIN_W - 550, WIN_H - 30, 0xffffff, "use command to stop or run programm");
	index = -1;
	while (++index < data->mydata->param->players)
	{
		ft_print_champs(data, WIN_W - 550, 250 + 100 * (index), &(data->mydata->param->champs[index]), data->mydata->color[index + 1]);
		ft_out_params(data, (t_win_par){WIN_W - 550, 250 + 100 * (index) + 45, 0xffffff, 0x00ff00, "proc_nbr:", data->mydata->param->player_proc_nbr[index]});
	}
	if (data->mydata->win >= 0)
		ft_draw_str_big(data, 50, WIN_H - 450, data->mydata->param->champs[data->mydata->param->winner - 1].name);
	return (1);
}
