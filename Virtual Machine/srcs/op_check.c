/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 23:23:48 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/17 07:22:33 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_funs				g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 4, &op_check_live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 4, &op_check_ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 4, &op_check_st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 4, &op_check_add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 4, &op_check_sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 4, &op_check_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 4, &op_check_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 4, &op_check_xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 2, &op_check_zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 2, &op_check_ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 2, &op_check_sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 2, &op_check_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 4, &op_check_lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 2, &op_check_lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 2, &op_check_lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 4, &op_check_aff},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0}
};

static unsigned char
	get_map_pos
	(t_process *p, int pos)
{
	while (pos >= MEM_SIZE)
		pos -= MEM_SIZE;
	return (*(p->map + pos));
}

static int
	check_reg
	(int reg)
{
	return (reg > 0 && reg <= REG_NUMBER);
}

static t_funs
	*get_fun_type
	(char id)
{
	int		index;

	index = -1;
	while (g_op_tab[++index].name != 0)
	{
		if (g_op_tab[index].id == id)
			return (&g_op_tab[index]);
	}
	return (NULL);
}

int
	op_check
	(t_process *p)
{
	t_funs		*op;

	if ((op = get_fun_type(p->op.type)) == NULL)
		return (0);
	return (op->check_fun(p));
}

int
	op_check_live
	(t_process *p)
{
	return (1);
}

int
	op_check_ld
	(t_process *p)
{
	unsigned char	reg;
	int				codage;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (((codage >> 6) & 3) == 1)
		return (0);
	if (((codage >> 6) & 3) == 2)
		reg = get_map_pos(p, (p->pc - p->map) + 2 + g_op_tab[1].label_size);
	else
		reg = get_map_pos(p, (p->pc - p->map) + 2 + 2);
	if (!check_reg(reg))
		return (0);
	return (1);
}

int
	op_check_st
	(t_process *p)
{
	unsigned char	reg;
	int				codage;

	reg = get_map_pos(p, (p->pc - p->map) + 2);
	if (!check_reg(reg))
		return (0);
	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (((codage >> 6) & 3) != 1)
		return (0);
	if (((codage >> 4) & 3) == 2)
		return (0);
	if (((codage >> 4) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 3)))
			return (0);
	return (1);
}

int
	op_check_add
	(t_process *p)
{
	unsigned char	reg;
	int				codage;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (codage != (4 + 16 + 64))
		return (0);
	reg = get_map_pos(p, (p->pc - p->map) + 2);
	if (!check_reg(reg))
		return (0);
	reg = get_map_pos(p, (p->pc - p->map) + 3);
	if (!check_reg(reg))
		return (0);
	reg = get_map_pos(p, (p->pc - p->map) + 4);
	if (!check_reg(reg))
		return (0);
	return (1);
}

int
	op_check_sub
	(t_process *p)
{
	unsigned char	reg;
	int				codage;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (codage != (4 + 16 + 64))
		return (0);
	reg = get_map_pos(p, (p->pc - p->map) + 2);
	if (!check_reg(reg))
		return (0);
	reg = get_map_pos(p, (p->pc - p->map) + 3);
	if (!check_reg(reg))
		return (0);
	reg = get_map_pos(p, (p->pc - p->map) + 4);
	if (!check_reg(reg))
		return (0);
	return (1);
}

int
	op_check_and
	(t_process *p)
{
	unsigned char	reg;
	int				codage;
	int				size;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (((codage >> 2) & 3) != 1)
		return (0);
	if (((codage >> 6) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2)))
			return (0);
	size = 1;
	if (((codage >> 6) & 3) == 2)
		size = g_op_tab[5].label_size;
	else if (((codage >> 6) & 3) == 3)
		size = 2;
	if (((codage >> 4) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2 + size)))
			return (0);
	size += 1;
	if (((codage >> 4) & 3) == 2)
		size += g_op_tab[5].label_size - 1;
	else if (((codage >> 4) & 3) == 3)
		size += 2 - 1;
	if (((codage >> 2) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2 + size)))
			return (0);
	return (1);
}

int
	op_check_or
	(t_process *p)
{
	unsigned char	reg;
	int				codage;
	int				size;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (((codage >> 2) & 3) != 1)
		return (0);
	if (((codage >> 6) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2)))
			return (0);
	size = 1;
	if (((codage >> 6) & 3) == 2)
		size = g_op_tab[6].label_size;
	else if (((codage >> 6) & 3) == 3)
		size = 2;
	if (((codage >> 4) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2 + size)))
			return (0);
	size += 1;
	if (((codage >> 4) & 3) == 2)
		size += g_op_tab[6].label_size - 1;
	else if (((codage >> 4) & 3) == 3)
		size += 2 - 1;
	if (((codage >> 2) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2 + size)))
			return (0);
	return (1);
}

int
	op_check_xor
	(t_process *p)
{
	unsigned char	reg;
	int				codage;
	int				size;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (((codage >> 2) & 3) != 1)
		return (0);
	if (((codage >> 6) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2)))
			return (0);
	size = 1;
	if (((codage >> 6) & 3) == 2)
		size = g_op_tab[7].label_size;
	else if (((codage >> 6) & 3) == 3)
		size = 2;
	if (((codage >> 4) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2 + size)))
			return (0);
	size += 1;
	if (((codage >> 4) & 3) == 2)
		size += g_op_tab[7].label_size - 1;
	else if (((codage >> 4) & 3) == 3)
		size += 2 - 1;
	if (((codage >> 2) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2 + size)))
			return (0);
	return (1);
}

int
	op_check_zjmp
	(t_process *p)
{
	return (1);
}

int
	op_check_ldi
	(t_process *p)
{
	unsigned char	reg;
	int				codage;
	int				size;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (((codage >> 4) & 3) == 3)
		return (0);
	if (((codage >> 2) & 3) != 1)
		return (0);
	if (((codage >> 6) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2)))
			return (0);
	size = 1;
	if (((codage >> 6) & 3) == 2)
		size = g_op_tab[9].label_size;
	else if (((codage >> 6) & 3) == 3)
		size = 2;
	if (((codage >> 4) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2 + size)))
			return (0);
	size += 1;
	if (((codage >> 4) & 3) == 2)
		size += g_op_tab[9].label_size - 1;
	if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2 + size)))
		return (0);
	return (1);
}

int
	op_check_sti
	(t_process *p)
{
	unsigned char	reg;
	int				codage;
	int				size;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (((codage >> 6) & 3) != 1)
		return (0);
	if (((codage >> 2) & 3) == 3)
		return (0);
	if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2)))
		return (0);
	if (((codage >> 4) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 3)))
			return (0);
	size = 1;
	if (((codage >> 4) & 3) == 2)
		size += g_op_tab[10].label_size - 1;
	else if (((codage >> 4) & 3) == 3)
		size += 2 - 1;
	if (((codage >> 2) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 3 + size)))
			return (0);
	return (1);
}

int
	op_check_fork
	(t_process *p)
{
	return (1);
}

int
	op_check_lld
	(t_process *p)
{
	unsigned char	reg;
	int				codage;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (((codage >> 6) & 3) == 1)
		return (0);
	if (((codage >> 6) & 3) == 2)
		reg = get_map_pos(p, (p->pc - p->map) + 2 + g_op_tab[12].label_size);
	else
		reg = get_map_pos(p, (p->pc - p->map) + 2 + 2);
	if (!check_reg(reg))
		return (0);
	return (1);
}

int
	op_check_lldi
	(t_process *p)
{
	unsigned char	reg;
	int				codage;
	int				size;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (((codage >> 4) & 3) == 3)
		return (0);
	if (((codage >> 2) & 3) != 1)
		return (0);
	if (((codage >> 6) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2)))
			return (0);
	size = 1;
	if (((codage >> 6) & 3) == 2)
		size += g_op_tab[13].label_size - 1;
	else if (((codage >> 6) & 3) == 3)
		size += 2 - 1;
	if (((codage >> 4) & 3) == 1)
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2 + size)))
			return (0);
	size += 1;
	if (((codage >> 4) & 3) == 2)
		size += g_op_tab[13].label_size - 1;
	ft_printf("op_check_lldi %d\n", size);
	if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2 + size)))
		return (0);
	return (1);
}

int
	op_check_lfork
	(t_process *p)
{
	return (1);
}

int
	op_check_aff
	(t_process *p)
{
	unsigned char	reg;
	int				codage;
	int				size;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (codage == 64)
	{
		if (!check_reg(get_map_pos(p, (p->pc - p->map) + 2)))
			return (0);
	}
	else
		return (0);
	return (1);
}
