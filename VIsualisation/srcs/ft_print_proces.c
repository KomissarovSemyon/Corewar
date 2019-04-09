/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_proces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:59:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/09 17:14:50 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void
	byte_to_str(char *str, int ch)
{
	str[0] = ((ch / 16) < 10) ? (ch / 16 + '0') : (ch / 16 - 10 + 'a');
	str[1] = ((ch % 16) < 10) ? (ch % 16 + '0') : (ch % 16 - 10 + 'a');
}

static void
	ft_print_regs(t_data *data, int x, int y, t_process *proc, int active)
{
	char	*str;
	int		index;

	index = data->mydata->first_reg - 1;
	while (++index < REG_NUMBER && index <= data->mydata->first_reg + 10)
	{
		str = ft_itoa(index);
		mlx_string_put(data->mlx_ptr, data->mlx_win,
		x, y + 133 + 15 * (index - data->mydata->first_reg), 0xffffff, str);
		mlx_string_put(data->mlx_ptr, data->mlx_win, x + 20,
		y + 133 + 15 * (index - data->mydata->first_reg), 0xffffff, ":");
		free(str);
		str = ft_strdup("00000000");
		byte_to_str(str, proc->r[index][0]);
		byte_to_str(&str[2], proc->r[index][1]);
		byte_to_str(&str[4], proc->r[index][2]);
		byte_to_str(&str[6], proc->r[index][3]);
		mlx_string_put(data->mlx_ptr, data->mlx_win, x + 30,
		y + 133 + 15 * (index - data->mydata->first_reg), 0xffffff, str);
		free(str);
	}
}

void
	ft_print_proces(t_data *data, int x, int y, t_process *p, int active)
{
	int		index;
	int		c[2];

	if (p == NULL)
		return ;
	c[0] = 0xffffff - active * 0x00ffff;
	c[1] = 0xffffff;
	ft_out_params(data, (t_win_par){x, y, c[0], c[1], "ID:", p->id});
	ft_out_params(data, (t_win_par){x, y + 15, c[0], c[1], "Carry:", p->carry});
	ft_out_params(data, (t_win_par){x, y + 38, c[0], c[1], "Wait:", p->wait});
	ft_out_params(data, (t_win_par){x, y + 53, c[0], c[1], "Pos_y:",
	(p->pc - p->map) / 64});
	ft_out_params(data, (t_win_par){x, y + 68, c[0], c[1], "Pos_x:",
	(p->pc - p->map) % 64});
	ft_out_params(data, (t_win_par){x, y + 83, c[0], c[1], "Livin:",
	data->mydata->param->current_cycle - p->livin});
	mlx_string_put(data->mlx_ptr, data->mlx_win, x, y + 98, c[0], "Comm:");
	if (p->op.id >= 0 && p->op.id <= 16)
		mlx_string_put(data->mlx_ptr, data->mlx_win, x + 50, y + 98, c[1],
		g_op_tab[p->op.id].name);
	else
		mlx_string_put(data->mlx_ptr, data->mlx_win, x + 50, y + 98, c[1],
		"none");
	mlx_string_put(data->mlx_ptr, data->mlx_win, x, y + 113, c[0], "Reg:");
	ft_print_regs(data, x, y, p, active);
}
