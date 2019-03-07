/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:48:39 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/07 03:18:38 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libft.h"
# include <stdlib.h>

# define DEFAULT_MODE 0
# define DUMP_MODE 1
# define STEP_MODE 2
# define NCURSES_MODE 3
# define VIS_MODE 4

typedef struct		s_champ
{
	char		name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
	int			champ_size;
	char		champ[CHAMP_MAX_SIZE + 1];
}					t_champ;

typedef	struct		s_flags
{
	char	comment;
	int		step;
	char	verb;
	char	mode;
}					t_flags;



typedef struct		s_param
{
	int			champ_arg;
	t_champ		*champs;
	t_flags		flag;
}					t_param;

int					get_champ(char *str, t_param *p);

void				usage(void);
void				help(void);


#endif
