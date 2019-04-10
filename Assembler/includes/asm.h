/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:54:18 by ltuffleb          #+#    #+#             */
/*   Updated: 2019/04/09 14:17:31 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "get_next_line.h"
# include "ft_printf.h"
# include "op.h"
# include <stdio.h>
# define CMD_COUNT 16
# define START 0
# define LABELS 9999
# define BYTES 999999
# define H PROG_NAME_LENGTH + COMMENT_LENGTH + 16

typedef struct s_asm	t_asm;
typedef struct			s_label
{
	char				label[100];
	int					num;
	int					addr;
}						t_label;
typedef struct			s_cmds
{
	char				name[10];
	int					(*fun)(t_asm *ch, char *line, int only_addr);
}						t_cmds;

struct					s_asm
{
	char				body[999999];
	size_t				len;
	char				name[PROG_NAME_LENGTH + 1];
	int					name_init;
	char				comment[COMMENT_LENGTH + 1];
	int					comment_init;
	t_cmds				cmds[CMD_COUNT];
	t_label				labels[LABELS];
	int					labels_count;
	int					current_addr;
	int					last_addr;
	unsigned char		byte[BYTES];
	int					byte_index;
	int					val;
	int					type;
	int					args[3][3];
	int					last;
	int					row_index;
	int					tmp;
	int					row;
	t_header			header;
	int					fd;
	char				*for_del;
};
void					error_clear_exit(t_asm *ch, char *msg,
							int clear, char *s);
int						get_arg_r(t_asm *ch, char *line, int i);
int						get_arg_d(t_asm *ch, char *line, int i);
int						get_arg_i(t_asm *ch, char *line, int i);
int						check_non_last(char *line);
int						check_num(t_asm *ch, char *line);
int						get_args(t_asm *ch, char *line, int args, int i);
unsigned char			get_byte(unsigned int a, int num);
int						get_addr(t_asm *ch, char *line);
int						only_num(char *line);
void					open_file(t_asm *ch, char *file);
int						check_simple_comment(char *line);
int						check_symbol(char c);
int						is_label_correct(t_asm *ch, char *line);
int						is_label(t_asm *ch, char *line, int first);
int						parse_command(t_asm *ch, char *line, int only);
int						check_command(t_asm *ch, char *line,
							int only, int first);
int						check_comment(t_asm *ch, char *line);
int						check_name(t_asm *ch, char *line);
int						check_name_to_byte(char *line);
int						check_comment_to_byte(t_asm *ch, char *line);
int						check_line(t_asm *ch, char *line, int only_addr);
int						check_line_to_byte(t_asm *ch, char *line,
							int only_addr);
int						check_command_quick(t_asm *ch, char *line, int ind);
void					init_labels(char *file, t_asm *ch);
void					name_to_byte(t_asm *ch);
void					comment_to_byte(t_asm *ch);
void					magic_name_comment_to_byte(t_asm *ch);
void					part_byte(t_asm *ch, char *file);
int						read_champ(char *file, t_asm *ch);
void					put_bytes(t_asm *ch, int a, int count);
char					*next_arg(t_asm *ch, char *line);
unsigned char			calc_type_args(int t1, int t2, int t3);
int						live_check(t_asm *ch, char *line, int only);
int						ld_check(t_asm *ch, char *line, int only);
int						st_check(t_asm *ch, char *line, int only);
int						add_check(t_asm *ch, char *line, int only);
int						sub_check(t_asm *ch, char *line, int only);
int						and_check(t_asm *ch, char *line, int only);
int						or_check(t_asm *ch, char *line, int only);
int						xor_check(t_asm *ch, char *line, int only);
int						zjmp_check(t_asm *ch, char *line, int only);
int						ldi_check(t_asm *ch, char *line, int only);
int						sti_check(t_asm *ch, char *line, int only);
int						fork_check(t_asm *ch, char *line, int only);
int						lld_check(t_asm *ch, char *line, int only);
int						lldi_check(t_asm *ch, char *line, int only);
int						lfork_check(t_asm *ch, char *line, int only);
int						aff_check(t_asm *ch, char *line, int only);
void					cmsd_init_f(t_asm *ch);
void					cmds_init(t_asm *ch);
void					header_init(t_asm *ch);
void					asm_init(t_asm *ch);
void					open_write_file(t_asm *ch, char *file);
void					write_bytes(char *file, t_asm *ch);
int						free_str(char *s);
void					is_label_inner(t_asm *ch, char *line, int first,
							int i);
void					check_comment_inner(t_asm *ch, char *line,
							int *start, int *i);
void					check_comment_middle(t_asm *ch, char *line,
							int *start, int *i);
void					check_comment_to_byte_inner(t_asm *ch,
							char *line, int *i);
void					check_name_inner(t_asm *ch, char *line, int i,
							int *start);
void					ldi_check_inner(t_asm *ch);
void					sti_check_inner(t_asm *ch);
void					check_end_symbol(t_asm *ch);
#endif
