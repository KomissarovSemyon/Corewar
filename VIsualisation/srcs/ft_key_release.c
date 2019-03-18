/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:25:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/18 03:05:59 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int				key_release(int key, t_data *data)
{
	if (key == B_SPACE)
		data->mydata->run = 0;
	return (1);
}

int				key_press(int key, t_data *data)
{
	if (key == B_SPACE)
		data->mydata->run = 1;
	else if (key == B_COMMAND)
		data->mydata->run = !data->mydata->run;
	else if (key == B_ESC)
		ft_close(data);
	ft_printf("key_press=%d\n", key);
	return (1);
}
