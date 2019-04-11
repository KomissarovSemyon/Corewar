/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_champs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:36:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/11 18:47:27 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void
	ft_print_champs(t_data *data, t_champ *champs)
{
	int		index;
	int		x;
	int		y;

	x = WIN_W - 550;
	index = -1;
	while (++index < data->mydata->param->players)
	{
		y = 250 + 100 * (index);
		mlx_string_put(data->mlx_ptr, data->mlx_win, x, y, 0xffffff, "Name:");
		mlx_string_put(data->mlx_ptr, data->mlx_win, x + 80, y,
		data->mydata->color[index + 1], champs[index].name);
		mlx_string_put(data->mlx_ptr, data->mlx_win, x, y + 15, 0xffffff,
		"Comment:");
		mlx_string_put(data->mlx_ptr, data->mlx_win, x + 80, y + 15, 0x00ff00,
		champs[index].comment);
		ft_out_params(data, (t_win_par){x, y + 30, 0xffffff, 0x00ff00,
		"champ_size:", champs[index].champ_size});
		ft_out_params(data, (t_win_par){WIN_W - 550, 250 + 100 * (index) + 45,
		0xffffff, 0x00ff00, "proc_nbr:",
		data->mydata->param->player_proc_nbr[index]});
	}
}
