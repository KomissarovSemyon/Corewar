/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 06:29:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/17 07:16:11 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

#include "vm.h"

void			check_int(int p1, int p2);
void			set_map_pos(t_process *p, int pos, unsigned char par);
void			set_map_params(t_process *p, int start_pos, int size1, int par1, int size2, int par2, int par3);
int				check_me(t_process *p, int pc, int expected);
t_process		init_process(void);

void			check_lives(void);
void			check_ld(void);
void			check_st(void);
void			check_add(void);
void			check_sub(void);
void			check_and(void);
void			check_or(void);
void			check_xor(void);
void			check_ldi(void);
void			check_sti(void);
void			check_lld(void);
void			check_lldi(void);
void			check_aff(void);

#endif
