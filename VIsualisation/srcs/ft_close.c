/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 01:36:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/18 00:23:22 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


int				ft_close(t_data *data)
{
	if (data->mydata && data->mydata->arr)
		free(data->mydata->arr);
	if (data->mydata)
		free(data->mydata);
	if (data->img)
		free(data->img);
	exit(0);
	return (0);
}
