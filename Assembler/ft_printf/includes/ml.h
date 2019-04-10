/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:11:54 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/02/03 18:11:55 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ML_H
# define ML_H
# include "ft_printf.h"

t_bigdata	g_modlen[ML_LEN] = {
	{"h", {{"d", &ml_di_h}, {"i", &ml_di_h}, {"o", &ml_o_h}, {"u", &ml_u_h},
			{"x", &ml_x_h}, {"X", &ml_upx_h}, {"f", &type_f}, {"c", &type_c},
			{"p", &type_p}, {"s", &type_s}, {"U", &ml_u_ll}, {"O", &ml_o_ll},
			{"D", &ml_di_l}, {NULL, NULL}}},
	{"hh", {{"d", &ml_di_hh}, {"i", &ml_di_hh}, {"o", &ml_o_hh},
			{"u", &ml_u_hh}, {"x", &ml_x_hh}, {"X", &ml_upx_hh}, {"f", &type_f},
			{"c", &type_c}, {"p", &type_p}, {"s", &type_s}, {"U", &ml_u_ll},
			{"O", &ml_o_ll}, {"D", &ml_di_l}, {NULL, NULL}}},
	{"l", {{"d", &ml_di_l}, {"i", &ml_di_l}, {"o", &ml_o_l}, {"u", &ml_u_l},
			{"x", &ml_x_l}, {"X", &ml_upx_l}, {"f", &type_f}, {"c", &type_l_c},
			{"C", &type_l_c}, {"p", &type_p}, {"s", &type_l_s}, {"U", &ml_u_ll},
			{"O", &ml_o_ll}, {"D", &ml_di_l}, {NULL, NULL}}},
	{"ll", {{"d", &ml_di_ll}, {"i", &ml_di_ll}, {"o", &ml_o_ll},
			{"u", &ml_u_ll}, {"x", &ml_x_ll}, {"X", &ml_upx_ll}, {"f", &type_f},
			{"c", &type_c}, {"p", &type_p}, {"s", &type_s}, {"U", &ml_u_ll},
			{"O", &ml_o_ll}, {"D", &ml_di_l}, {NULL, NULL}}},
	{"L", {{"d", &type_di}, {"i", &type_di}, {"o", &type_o}, {"u", &type_u},
			{"x", &type_x}, {"X", &type_upx}, {"f", &ml_f}, {"c", &type_c},
			{"p", &type_p}, {"s", &type_s}, {"U", &ml_u_ll}, {"O", &ml_o_ll},
			{"D", &ml_di_l}, {NULL, NULL}}},
	{"j", {{"d", &ml_di_ll}, {"i", &ml_di_ll}, {"o", &ml_o_ll}, {"u", &ml_u_ll},
			{"x", &ml_x_ll}, {"X", &ml_upx_ll}, {"f", &type_f}, {"c", &type_c},
			{"p", &type_p}, {"s", &type_s}, {"U", &ml_u_ll}, {"O", &ml_o_ll},
			{"D", &ml_di_l}, {NULL, NULL}}},
	{"z", {{"d", &ml_di_ll}, {"i", &ml_di_ll}, {"o", &ml_o_ll}, {"u", &ml_u_ll},
			{"x", &ml_x_ll}, {"X", &ml_upx_ll}, {"f", &type_f}, {"c", &type_c},
			{"p", &type_p}, {"s", &type_s}, {"U", &ml_u_ll}, {"O", &ml_o_ll},
			{"D", &ml_di_l}, {NULL, NULL}}}
};
#endif
