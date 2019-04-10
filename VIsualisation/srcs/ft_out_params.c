/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:58:14 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/09 20:16:07 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void
	ft_out_params(t_data *data, t_win_par par)
{
	int		width;
	char	*num;

	mlx_string_put(data->mlx_ptr, data->mlx_win, par.x, par.y,
	par.color_str, par.str);
	width = ft_strlen(par.str);
	num = ft_itoa(par.par);
	if (num == NULL)
		return ;
	mlx_string_put(data->mlx_ptr, data->mlx_win, par.x + width * 10 + 5, par.y,
	par.color_num, num);
	free(num);
}
