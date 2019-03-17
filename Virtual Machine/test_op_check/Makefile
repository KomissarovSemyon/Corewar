# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 00:42:52 by rrhaenys          #+#    #+#              #
#    Updated: 2019/03/17 06:32:03 by rrhaenys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMMAND = gcc
FLAGS = #-Wall -Wextra -Werror
NAME = test.out
SOURCES	= ../srcs/read_champs.c \
		  ../srcs/usage.c \
		  ../srcs/map.c \
		  ../srcs/command_read.c \
		  ../srcs/command_do.c \
		  ../srcs/op_check.c
SRCS = $(addprefix  ./srcs/, $(shell ls srcs | grep -E ".+\.c"))
OBJ	= $(SRCS:.c=.o) $(SOURCES:.c=.o)
INCLUDE = -I ../includes -I includes

FT_DIR	= ../libft/
FT_LNK	= -L $(FT_DIR) -lft
FT_LIB	= $(addprefix $(FT_DIR), libft.a)

all: $(FT_LIB) $(NAME)

$(NAME): $(OBJ)
	$(COMMAND) $(OBJ) $(INCLUDE) $(FT_LNK) -o $(NAME)

$(FT_LIB):
	make -C $(FT_DIR)

.c.o:
	$(COMMAND) $(FLAGS) $(INCLUDE) -g -c -o $@ $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

test: all
	./test.out

retest: re
	./test.out

.PHONY: clean fclean all re
