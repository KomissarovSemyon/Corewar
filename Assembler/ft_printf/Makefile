# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/19 17:33:12 by ltuffleb          #+#    #+#              #
#    Updated: 2019/04/09 20:39:13 by amerlon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	libftprintf.a
NAME_MAIN_FILE		=	main.c
NAME_LFT			=	libftprintf.a
NAME_LFT_SHORT		=	lftprintf
NAME_LIB_SHORT		=	lft
NAME_PRINT_SHORT	=	lftprintf
SRC_FOLDER			=	srcs
GENERAL_SRC			=	ft_printf.c
LFT_SRCS			=	ft_memcpy.c ft_strjoin.c ft_strsub.c ft_atoi.c ft_itoa.c ft_itoabase.c\
						ft_itoabase_size_p.c ft_itoabasell.c ft_strdup.c ft_strlen.c ft_tolower.c
PRINT_SRCS			=	sv_zveno.c field_width.c conver.c
SPEC_SRCS			=	type_fs.c accuracy.c type_updupoupu.c type_csp.c type_dioux.c type_f.c type_proc.c
ML_SRCS				=	ml_c_l.c ml_h.c ml_hh.c ml_l.c ml_ll.c
FLAGS_SRCS			=	flags1.c flags2.c flags3.c
HELP_SRCS			=	htlpers1.c htlpers2.c htlpers3.c



SPEC_PATH			=	specifier
ML_PATH				=	ml
FLAGS_PATH			=	flags

PRINT_OBJS			=	$(PRINT_SRCS:.c=.o)
SPEC_OBJ			=	$(SPEC_SRS:.c=.o)
MOD_LEN_OBJ			=	$(MOD_LEN_SRC:.c=.o)
FLAGS_OBJS			=	$(FLAGS_SRCS:.c=.o)

LIB_FOLDER			=	includes/
LIBFT_PATH			=	libft/
FLAGS				=	-Wall -Wextra -Werror

ALL_SRCS			=	$(GENERAL_SRC)
ALL_SRCS			+=	$(patsubst %,$(LIBFT_PATH)%,$(LFT_SRCS))
ALL_SRCS			+=	$(patsubst %,$(SRC_FOLDER)/%,$(PRINT_SRCS))
ALL_SRCS			+=	$(patsubst %,$(SRC_FOLDER)/$(SPEC_PATH)/%,$(SPEC_SRCS))
ALL_SRCS			+=	$(patsubst %,$(SRC_FOLDER)/$(ML_PATH)/%,$(ML_SRCS))
ALL_SRCS			+=	$(patsubst %,$(SRC_FOLDER)/$(FLAGS_PATH)/%,$(FLAGS_SRCS))
ALL_SRCS			+=	$(patsubst %,$(SRC_FOLDER)/%,$(HELP_SRCS))

ALL_OBJS			=	$(GENERAL_SRC:.c=.o)\
						$(LFT_SRCS:.c=.o)	\
						$(PRINT_SRCS:.c=.o)	\
						$(SPEC_SRCS:.c=.o)	\
						$(ML_SRCS:.c=.o)	\
						$(FLAGS_SRCS:.c=.o)	\
						$(HELP_SRCS:.c=.o)

OBJS				=	$(ALL_SRCS:.c=.o)



all: $(NAME)

.c.o:
	@gcc $(FLAGS) -I $(LIB_FOLDER) -I $(LIBFT_PATH)$(LIB_FOLDER) -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME_LFT) $(OBJS)
	@ranlib $(NAME_LFT)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME_LFT)

go:
	gcc -I $(LIBFT_PATH)$(LIB_FOLDER) -I $(LIB_FOLDER) -L. -$(NAME_LFT_SHORT) -o $(NAME) $(NAME_MAIN_FILE)
	./ft_printf

re: fclean all
