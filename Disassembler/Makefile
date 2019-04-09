# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 17:58:27 by amerlon-          #+#    #+#              #
#    Updated: 2019/04/09 20:46:14 by amerlon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	disassemble
FLAGS		=	-g -Wall -Werror -Wextra
LIBFT_DIR	=	./libft
SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./include
INCLUDES	=	-Iincludes -Ilibft/inc
SRC			=	main.c \
				disassemble.c \
				add_args.c \

OBJS		= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
LIBFT		= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@gcc $(LIBFT) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(FLAGS) -c $< $(INCLUDES) -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean

fclean: clean
	@make -C libft fclean

re: fclean all

norm:
	@make -C libft norm
	@norminette $(SRC_DIR) $(INC_DIR)

.PHONY: all clean fclean re norm
