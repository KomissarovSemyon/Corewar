/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:48:39 by jcorwin           #+#    #+#             */
/*   Updated: 2019/04/10 23:06:20 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define MOD(x) (x > 0 ? x : -x)

# define VIS_MAGIC 0x1377713
# define VIS_STOP 0x36663

# define DEFAULT_MODE 0
# define DUMP_MODE 1
# define STEP_MODE 2
# define NCURSES_MODE 3
# define VIS_MODE 4

# define LIVE 0
# define LD 1
# define ST 2
# define ADD 3
# define SUB 4
# define AND 5
# define OR 6
# define XOR 7
# define ZJMP 8
# define LDI 9
# define STI 10
# define FORK 11
# define LLD 12
# define LLDI 13
# define LFORK 14
# define AFF 15

typedef struct		s_champ
{
	char			*file;
	int				n;
	unsigned int	magic;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	champ_size;
	char			champ[CHAMP_MAX_SIZE + 1];
	char			null_term[4];
	int				color;
}					t_champ;

typedef struct		s_op
{
	unsigned char	*ptr;
	unsigned char	id;
	unsigned char	next_id;
	unsigned char	arg_type[3];
	long long int	arg[3];
}					t_op;

typedef struct		s_process
{
	int					id;
	unsigned char		r[REG_NUMBER][REG_SIZE];
	int					carry;
	unsigned char		*map;
	unsigned char		*pc;
	int					wait;
	int					livin;
	int					step;
	int					moved;
	t_op				op;
	struct s_process	*next;
}					t_process;

typedef	struct		s_flags
{
	char	comment;
	int		help;
	int		vis;
	int		oper;
	int		dump;
	int		step;
	int		cycle;
	int		map;
	int		start;
	int		process;
	int		check;
}					t_flags;

typedef struct		s_param
{
	int				champ_arg;
	t_champ			champs[MAX_PLAYERS];
	int				players;
	int				player_proc_nbr[4];
	t_flags			flag;
	unsigned char	map[MEM_SIZE];
	int				map_color[MEM_SIZE];
	int				map_color_cycle[MEM_SIZE];
	t_process		*process;
	int				proc_nbr;
	int				cycles_to_die;
	int				current_cycle;
	int				last_check;
	int				checks;
	int				live_nbr;
	int				winner;
}					t_param;

typedef struct		s_funs
{
	char		*name;
	int			nb_params;
	char		params_type[3];
	int			id;
	int			cycles;
	char		description[50];
	int			codage;
	int			label_size;
	int			(*f_check)(t_process *p);
}					t_funs;

void				print_bytes(t_param *p, unsigned char *str, int len);
void				read_args(t_param *p, int argc, char **argv);
void				get_champ(char *str, t_param *p, int id);
void				champ_err(int value, int f, char *str, int expect);

void				usage(void);
void				help(void);
void				malloc_err(void);

void				set_color(t_param *p, int place, int size, int color);
void				map_print(t_param *p);
void				vis_print(t_param *p);

void				op_read(t_process *p);
void				op_args(t_process *p);

void				process_new(t_param *p, t_process *parent,
													unsigned char *pc);
t_process			*process_kill(t_param *p, t_process *die);
void				process_print(t_process *p);

int					check_cycle(t_param *param);
void				start_game(t_param *param);

unsigned char		*get_step(unsigned char *map, unsigned char *ptr, int step);
long long			get_signed_value(unsigned char *map,
											unsigned char *ptr, int size);
long long			get_value(unsigned char *map,
											unsigned char *ptr, int size);
void				set_value(unsigned char *map, unsigned char *dst,
												long long src, int size);
void				swap_champ(t_champ *c1, t_champ *c2);

char				get_map_pos(t_process *p, int pos);
int					check_reg(int reg);
int					op_check(t_process *p);
int					op_check_live(t_process *p);
int					op_check_ld(t_process *p);
int					op_check_st(t_process *p);
int					op_check_add(t_process *p);
int					op_check_sub(t_process *p);
int					op_check_and(t_process *p);
int					op_check_or(t_process *p);
int					op_check_xor(t_process *p);
int					op_check_zjmp(t_process *p);
int					op_check_ldi(t_process *p);
int					op_check_sti(t_process *p);
int					op_check_fork(t_process *p);
int					op_check_lld(t_process *p);
int					op_check_lldi(t_process *p);
int					op_check_lfork(t_process *p);
int					op_check_aff(t_process *p);

static t_funs		g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 4, &op_check_live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 4,
		&op_check_ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 4,
		&op_check_st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 4,
		&op_check_add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 4,
		&op_check_sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 4, &op_check_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 4, &op_check_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 4, &op_check_xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 2,
		&op_check_zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 2, &op_check_ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 2, &op_check_sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 2, &op_check_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 4,
		&op_check_lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 2, &op_check_lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 2,
		&op_check_lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 4, &op_check_aff},
	{0, 0, {0}, 0, 1, {0, 0, 0, 0, 0}, 0, 0, 0}
};

#endif
