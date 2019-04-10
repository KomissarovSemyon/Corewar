# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 17:47:51 by thgiraud          #+#    #+#              #
#    Updated: 2019/04/10 21:35:02 by amerlon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-Iincludes
SRC_DIR		=	./srcs
OBJ_DIR		=	./obj
LIBFT_DIR	=	./libft
LIBFT_NAME	=	$(LIBFT_DIR)/libft.a

SRC			=	main.c \
				read_champs.c \
				usage.c \
				command_read.c \
				map.c \
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

OBJS		= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT_NAME):
	@make -C libft

$(NAME): $(LIBFT_NAME) $(OBJ_DIR) $(OBJS)
	@$(CC) $(LIBFT_NAME) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
