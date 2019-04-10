/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:49:14 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/02/01 15:50:02 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITDATA_H
# define INITDATA_H
# include "ft_printf.h"

t_data		g_types[TYPES_LEN] = {
	{"d", &type_di},
	{"i", &type_di},
	{"o", &type_o},
	{"u", &type_u},
	{"x", &type_x},
	{"c", &type_c},
	{"p", &type_p},
	{"s", &type_s},
	{"f", &type_f},
	{"D", &ml_di_l},
	{"O", &ml_o_ll},
	{"U", &ml_u_ll},
	{"X", &type_upx},
	{"C", &type_l_c},
	{"S", &type_l_s},
	{"%%", &type_proc}
};
#endif
