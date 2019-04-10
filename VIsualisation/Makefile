# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 00:42:52 by rrhaenys          #+#    #+#              #
#    Updated: 2019/04/11 01:00:21 by rrhaenys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMMAND = gcc
FLAGS = #-Wall -Wextra -Werror
NAME = visual
SOURCES	= ../Virtual_Machine/srcs/commands.c \
		  ../Virtual_Machine/srcs/help.c \
		  ../Virtual_Machine/srcs/map.c \
		  ../Virtual_Machine/srcs/op_check.c \
		  ../Virtual_Machine/srcs/process.c\
		  ../Virtual_Machine/srcs/usage.c
SRCS = $(addprefix  ./srcs/, $(shell ls srcs | grep -E ".+\.c"))
OBJ	= $(SRCS:.c=.o) $(SOURCES:.c=.o)
INCLUDE = -I includes

FT_DIR	= ./libft
FT_LNK	= -L $(FT_DIR) -lft
FT_LIB	= $(addprefix $(FT_DIR), libft.a)
MLX = -framework OpenCL -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit


all: $(FT_LIB) $(NAME)

$(NAME): $(OBJ)
	$(COMMAND) $(OBJ) $(FT_LNK) -o $(NAME) $(MLX) $(INCLUDE)

$(FT_LIB):
	make -C $(FT_DIR)

.c.o:
	$(COMMAND) $(FLAGS) $(INCLUDE) -g -c -o $@ $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

retest: re test

.PHONY: clean fclean all re
