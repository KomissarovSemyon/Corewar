/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:37:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/09 20:17:11 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void
	ft_print_process(t_data *data)
{
	int		index;
	int		delta;

	data->mydata->active_proces = -1;
	delta = 0;
	index = data->mydata->first_proces - 1;
	while (++index < data->mydata->process_count &&
	index < data->mydata->first_proces + 14)
	{
		while (ft_get_process_id(data, index + delta) == NULL)
			++delta;
		ft_print_proces(data,
		(t_print_proces){13 + 125 * (index - data->mydata->first_proces),
		WIN_H - 310, ft_get_process_id(data, index + delta),
		((index - data->mydata->first_proces) ==
		data->mydata->active_proces_line)});
		if (data->mydata->active_proces_line ==
			(index - data->mydata->first_proces))
			data->mydata->active_proces =
			data->mydata->process_count - 1 - index + delta;
	}
}
