# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 17:47:51 by thgiraud          #+#    #+#              #
#    Updated: 2019/04/10 07:22:44 by jcorwin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%.c : %.o

NAME	= corewar

SOURCES	= main.c \
		  read_champs.c \
		  usage.c \
		  map.c \
		  command_read.c \
		  commands.c \
		  commands1.c \
		  commands2.c \
		  commands3.c \
		  help.c \
		  process.c \
		  check_cycle.c \
		  game.c \
		  op_check.c \
		  op_check1.c \
		  op_check2.c \
		  op_check3.c \
		  op_check4.c \
		  args.c \

INCLUDES= libft.h \
		  vm.h \
		  ft_printf.h

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# ft library
FT_DIR	= ./libft/
FT_LNK	= -L $(FT_DIR) -lft
FT_LIB	= $(addprefix $(FT_DIR), libft.a)

# directories
SRCDIR	= ./srcs/
INCDIR	= ./includes/

SRC		= $(addprefix $(SRCDIR), $(SOURCES))
OBJ		= $(SRC:.c=.o)
INC		= $(addprefix $(INCDIR), $(INCLUDES))

all: $(FT_LIB) $(SRC) $(NAME)

$(NAME): $(INC) $(OBJ)
	@$(CC) $(OBJ) $(FT_LNK) -o $@

.c.o:
	@$(CC) -I $(INCDIR) -c $< -o $@

$(FT_LIB):
	@make -C $(FT_DIR)

clean:
	@rm -rf $(OBJ)
	@make clean -C $(FT_DIR)

fclean: clean
	@rm -rf $(NAME)
	@make clean -C $(FT_DIR) fclean

re: fclean all
