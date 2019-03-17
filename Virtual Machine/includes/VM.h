/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:48:39 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/17 09:06:08 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define DEFAULT_MODE 0
# define DUMP_MODE 1
# define STEP_MODE 2
# define NCURSES_MODE 3
# define VIS_MODE 4

# define LIVE 1
# define LD 2
# define ST 3
# define ADD 4
# define SUB 5
# define AND 6
# define OR 7
# define XOR 8
# define ZJMP 9
# define LDI 10
# define STI 11
# define FORK 12
# define LLD 13
# define LLDI 14
# define LFORK 15
# define AFF 16

/* чемпион */
typedef struct		s_champ
{
	char			*file;
	unsigned int	magic;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	champ_size;
	char			champ[CHAMP_MAX_SIZE + 1];
	char			null_term[4];
	int				color;
}					t_champ;

/*ячейка памяти*/
typedef struct		s_cage
{
	char		value;
	int			color;
	int			process;
}					t_cage;

/*операция*/
typedef struct		s_op
{
	unsigned char	*ptr;
	char			type;
	unsigned char	arg_type[3];
	unsigned char	*arg[3];
}					t_op;

/*каретка*/
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

/*флаги программы*/
typedef	struct		s_flags
{
	char	comment;
	int		step;
	char	verb;
	char	mode;
	int		id;
}					t_flags;

/*основные параметры*/
typedef struct		s_param
{
	int				champ_arg;
	t_champ			champs[MAX_PLAYERS];
	int				players;
	t_flags			flag;
	unsigned char	map[MEM_SIZE + 1];
	t_process		*process;
	int				cycles_to_die;
	unsigned int	current_cycle;
	int				winner;
}					t_param;

int					get_champ(char *str, t_param *p, int id);

void				usage(void);
void				help(void);
void				malloc_err(void);

void				print_bytes(unsigned char *str, int len);
void				map_init(t_param *p);
void				map_print(t_param *p);

void				op_read(t_process *p);
void				op_args(t_process *p);

void				process_new(t_param *p, t_process *parent, unsigned char *pc);
void				process_die(t_param *p, t_process *die);

unsigned char		*get_step(unsigned char *map, unsigned char *ptr, int step);
long				get_value(unsigned char *ptr, int size);
void				set_value(unsigned char *dst, long src, int size);

void				do_op(t_param *param, t_process *process);
void				start_game(t_param *param);

#endif
