# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/19 17:33:12 by ltuffleb          #+#    #+#              #
#    Updated: 2019/04/09 20:42:26 by amerlon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	asm
NAME_MAIN_FILE		=	main.c
NAME_LIB_SHORT		=	lft
NAME_LIB_PRINTF		=	lftprintf

SRCS				=	asm.c srcs1.c srcs2.c srcs3.c srcs4.c srcs5.c srcs6.c srcs7.c srcs8.c		\
						 srcs9.c srcs10.c srcs11.c srcs12.c srcs13.c srcs14.c
GNL_SRCS			=	get_next_line.c

SRCS_PATH			=	srcs
GNL_PATH			=	gnl/
PRINTF_PATH			=	ft_printf/

SRCS_OBJS			=	$(SRCS_PATH:.c=.o)
GNL_OBJS			+=	$(GNL_SRCS:.c=.o)

LIB_FOLDER			=	includes/
LIBFT_PATH			=	libft/
FLAGS				=	-g -Wall -Wextra -Werror

ALL_SRCS			=	$(SRCS)
ALL_SRCS			+=	$(patsubst %,$(GNL_PATH)/%,$(GNL_SRCS))

OBJS				=	$(ALL_SRCS:.c=.o)

all: $(NAME)

.c.o:
	@gcc $(FLAGS) -I. -I $(PRINTF_PATH)$(LIB_FOLDER) -I $(LIB_FOLDER) -I $(LIBFT_PATH)$(LIB_FOLDER) -I $(GNL_PATH)$(LIB_FOLDER) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH) all
	@make -C $(PRINTF_PATH) all
	@gcc $(FLAGS) -O3 -I $(LIBFT_PATH)$(LIB_FOLDER) -I $(LIB_FOLDER)									\
		-I $(GNL_PATH)$(LIB_FOLDER) -L $(LIBFT_PATH) -$(NAME_LIB_SHORT) 							\
		-I $(PRINTF_PATH)$(LIB_FOLDER) -L $(PRINTF_PATH) -$(NAME_LIB_PRINTF) 						\
		-o $(NAME) $(OBJS)

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(PRINTF_PATH) clean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(PRINTF_PATH) fclean

go:
	./$(NAME) < map.map

re: fclean all
