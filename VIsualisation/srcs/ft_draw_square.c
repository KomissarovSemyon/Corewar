/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:03:32 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/04/09 16:15:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void
	ft_draw_square
	(t_data *data, int *pos, int rad, int color)
{
	int	dx;
	int	dy;

	dx = pos[0] - rad - 1;
	while (++dx < (pos[0] + rad))
	{
		dy = pos[1] - rad - 1;
		while (++dy < (pos[1] + rad))
			ft_draw_px(data, dx, dy, color);
	}
}
