/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_proces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:59:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/11 18:47:49 by rrhaenys         ###   ########.fr       */
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
	ft_print_regs(t_data *data, t_print_proces o)
{
	char	*str;
	int		index;

	index = data->mydata->first_reg - 1;
	while (++index < REG_NUMBER && index <= data->mydata->first_reg + 10)
	{
		str = ft_itoa(index);
		mlx_string_put(data->mlx_ptr, data->mlx_win,
		o.x, o.y + 133 + 15 * (index - data->mydata->first_reg), 0xffffff, str);
		mlx_string_put(data->mlx_ptr, data->mlx_win, o.x + 20,
		o.y + 133 + 15 * (index - data->mydata->first_reg), 0xffffff, ":");
		free(str);
		str = ft_strdup("00000000");
		byte_to_str(str, o.p->r[index][0]);
		byte_to_str(&str[2], o.p->r[index][1]);
		byte_to_str(&str[4], o.p->r[index][2]);
		byte_to_str(&str[6], o.p->r[index][3]);
		mlx_string_put(data->mlx_ptr, data->mlx_win, o.x + 30,
		o.y + 133 + 15 * (index - data->mydata->first_reg), 0xffffff, str);
		free(str);
	}
}

void
	ft_print_proces(t_data *data, t_print_proces o)
{
	int		c1;
	int		c2;
	char	*str;

	if (o.p == NULL)
		return ;
	c1 = 0xffffff - o.active * 0x00ffff;
	c2 = 0xffffff;
	ft_out_params(data, (t_win_par){o.x, o.y, c1, c2, "ID:", o.p->id});
	ft_out_params(data, (t_win_par){o.x, o.y + 15, c1, c2, "Carry:",
	o.p->carry});
	ft_out_params(data, (t_win_par){o.x, o.y + 38, c1, c2, "Wait:", o.p->wait});
	ft_out_params(data, (t_win_par){o.x, o.y + 53, c1, c2, "Pos_y:",
	(o.p->pc - o.p->map) / 64});
	ft_out_params(data, (t_win_par){o.x, o.y + 68, c1, c2, "Pos_x:",
	(o.p->pc - o.p->map) % 64});
	ft_out_params(data, (t_win_par){o.x, o.y + 83, c1, c2, "Livin:",
	data->mydata->param->current_cycle - o.p->livin});
	mlx_string_put(data->mlx_ptr, data->mlx_win, o.x, o.y + 98, c1, "Comm:");
	str = (o.p->op.id >= 0 && o.p->op.id <= 16) ? g_op_tab[o.p->op.id].name :
	"none";
	mlx_string_put(data->mlx_ptr, data->mlx_win, o.x + 50, o.y + 98, c2, str);
	mlx_string_put(data->mlx_ptr, data->mlx_win, o.x, o.y + 113, c1, "Reg:");
	ft_print_regs(data, o);
}
