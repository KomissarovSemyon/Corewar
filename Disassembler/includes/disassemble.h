/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:38:45 by amerlon-          #+#    #+#             */
/*   Updated: 2019/03/28 14:13:45 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASSEMBLE_H
# define DISASSEMBLE_H

# include "libft.h"
# include "op.h"
# include <stdio.h>
# define MAX(a, b) (a > b ? a : b)

void	disassemble(int in, int out);
void	add_args(char *str, char cmd, unsigned char *bytes, unsigned char args);

#endif
