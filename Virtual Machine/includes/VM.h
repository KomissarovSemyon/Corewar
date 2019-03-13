/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:48:39 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/13 02:51:55 by jcorwin          ###   ########.fr       */
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

typedef struct		s_champ
{
	unsigned int	magic;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	champ_size;
	char			champ[CHAMP_MAX_SIZE + 1];
	char			null_term[4];
}					t_champ;

typedef	struct		s_flags
{
	char	comment;
	int		step;
	char	verb;
	char	mode;
	int		id;
}					t_flags;



typedef struct		s_param
{
	int			champ_arg;
	t_champ		*champs;
	t_flags		flag;
}					t_param;

int					get_champ(char *str, t_param *p, int id);

void				usage(void);
void				help(void);
void				malloc_err(void);

void				print_bytes(char *str, int len);

#endif
