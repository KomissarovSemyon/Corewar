/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:45:39 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/02/03 18:45:41 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H
# include "ft_printf.h"

t_bigdata	g_flags[FLAGS_LEN] = {
	{"#", {{"o", &flag_diez_o}, {"u", &flag_null_d}, {"x", &flag_diez_x},
			{"X", &flag_diez_upx}, {"f", &flag_diez_f}, {"a", &flag_diez_f},
			{"A", &flag_diez_f}, {"e", &flag_diez_f}, {"E", &flag_diez_f},
			{"F", &flag_diez_f}, {"g", &flag_diez_f}, {"G", &flag_diez_f},
			{"O", &flag_diez_o}, {NULL, NULL}}},
	{"0", {{"d", &flag_null_d}, {"i", &flag_null_d}, {"o", &flag_null_d},
			{"u", &flag_null_d}, {"x", &flag_null_d}, {"X", &flag_null_d},
			{"c", &flag_null_d}, {"p", &flag_null_d}, {"s", &flag_null_d},
			{"f", &flag_null_f}, {"D", &flag_null_d}, {"O", &flag_null_d},
			{"U", &flag_null_d}, {NULL, NULL}}},
	{"-", {{NULL, NULL}}},
	{"+", {{"d", &flag_plus}, {"i", &flag_plus}, {"c", &flag_plus},
			{"s", &flag_plus}, {"f", &flag_plus}, {"D", &flag_plus},
			{"o", &flag_plus}, {NULL, NULL}}},
	{" ", {{"d", &flag_probel}, {"i", &flag_probel}, {"s", &flag_probel},
			{"f", &flag_probel}, {"D", &flag_probel}, {"O", &flag_probel},
			{"U", &flag_probel}, {"o", &flag_probel}, {NULL, NULL}}}
};
#endif
