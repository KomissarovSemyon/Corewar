/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearwin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 01:37:54 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/09 16:14:20 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			ft_clearwin(t_data *data)
{
	int index;

	if (data->img->size_l <= 100)
		return ;
	index = -1;
	while (++index < (WIN_W * WIN_H))
		data->img->data[index] = 0;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->img_ptr, 0, 0);
}
