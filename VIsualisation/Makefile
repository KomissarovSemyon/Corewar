# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 00:42:52 by rrhaenys          #+#    #+#              #
#    Updated: 2019/04/11 18:44:57 by rrhaenys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMMAND = gcc
FLAGS = -Wall -Wextra -Werror
NAME = visual
SRCS = $(addprefix  ./srcs/, $(shell ls srcs | grep -E ".+\.c"))
OBJ	= $(SRCS:.c=.o)
INCLUDE = -I includes

FT_DIR	= ./libft
FT_LNK	= -L $(FT_DIR) -lft
FT_LIB	= $(addprefix $(FT_DIR), libft.a)
MLX = -framework OpenCL -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(FT_LIB) $(OBJ)
	@$(COMMAND) $(OBJ) $(FT_LNK) -o $(NAME) $(MLX) $(INCLUDE)

$(FT_LIB):
	@make -C $(FT_DIR)

.c.o:
	@$(COMMAND) $(FLAGS) $(INCLUDE) -g -c -o $@ $<

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(FT_DIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(FT_DIR) fclean

re: fclean all

retest: re test

.PHONY: clean fclean all re
