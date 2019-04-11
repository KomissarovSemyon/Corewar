/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:25:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/11 18:46:29 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int
	key_release(int key, t_data *data)
{
	if (key == B_SPACE)
		data->mydata->run = 0;
	return (1);
}

int
	key_press(int key, t_data *data)
{
	if (key == B_SPACE)
		data->mydata->run = 2;
	else if (key == B_COMMAND)
		data->mydata->run = (data->mydata->run == 0);
	else if (key == B_ESC)
		ft_close(data);
	data->mydata->first_proces +=
	(key == 124 &&
	data->mydata->first_proces < (data->mydata->process_count - 1)) -
	(key == 123 && data->mydata->first_proces > 0);
	data->mydata->first_reg +=
	(key == 125 && data->mydata->first_reg < (REG_NUMBER - 11)) -
	(key == 126 && data->mydata->first_reg > 0);
	ft_printf("key_press=%d\n", key);
	return (1);
}

int
	mouse_move(int x, int y, t_data *data)
{
	if (x >= 8 && x <= 1930 && y >= 990 && y <= 1291)
		data->mydata->active_proces_line = (x - 13) / 125;
	else
		data->mydata->active_proces_line = -1;
	return (0);
}
