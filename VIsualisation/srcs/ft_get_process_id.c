/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_process_id.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:22:18 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/09 17:22:28 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_process
	*ft_get_process_id(t_data *data, int id)
{
	if (id < data->mydata->process_count)
		return (&data->mydata->process[data->mydata->process_count - 1 - id]);
	return (NULL);
}
