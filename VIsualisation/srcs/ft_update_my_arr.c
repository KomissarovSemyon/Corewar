/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_my_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:22:41 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/11 19:00:29 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void
	ft_read_str_and_color(t_data *data)
{
	int			i;
	char		*str;

	i = -1;
	while (++i < MEM_SIZE)
	{
		free(data->mydata->arr[i].str);
		data->mydata->arr[i].str = ft_rebase(data->mydata->param->map[i], 16);
		if (ft_strlen(data->mydata->arr[i].str) == 1)
		{
			str = ft_strdup("00");
			str[1] = data->mydata->arr[i].str[0];
			free(data->mydata->arr[i].str);
			data->mydata->arr[i].str = str;
		}
		data->mydata->arr[i].color = data->mydata->param->map_color[i];
	}
	if (data->mydata->process != NULL)
		free(data->mydata->process);
}

static int
	ft_is_win(t_data *data, int magic)
{
	if (magic == VIS_STOP)
		data->mydata->win = 0;
	if (data->mydata->win == 0)
		return (1);
	return (0);
}

void
	ft_update_my_arr(t_data *data)
{
	int			magic;
	int			i;

	if (((unsigned long)read(0, &magic, sizeof(int)) < sizeof(int)) ||
		ft_is_win(data, magic))
		return ;
	if (magic != VIS_MAGIC)
	{
		ft_printf("VIS_MAGIC Error!!!\n");
		exit(0);
	}
	if (data->mydata->param != NULL)
		free(data->mydata->param);
	data->mydata->param = (t_param *)malloc(sizeof(t_param));
	if ((unsigned long)read(0, data->mydata->param, sizeof(t_param)) <
		sizeof(t_param))
		return ;
	ft_read_str_and_color(data);
	data->mydata->process = (t_process *)malloc(sizeof(t_process) *
	(data->mydata->param->proc_nbr));
	data->mydata->process_count = data->mydata->param->proc_nbr;
	i = -1;
	while (++i < data->mydata->param->proc_nbr)
		read(0, &(data->mydata->process[i]), sizeof(t_process));
}
