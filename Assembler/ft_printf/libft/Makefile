#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 14:56:40 by ltuffleb          #+#    #+#              #
#    Updated: 2018/12/14 20:46:17 by ltuffleb         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_PROG = test
NAME_MAIN_FILE = test.c
NAME = libft.a
NAME_LIB_SHORT = lft
SRC_FOLDER = srcs/
SRCS = ft_atoi.c ft_btrcount.c ft_btrin.c ft_btrnew.c ft_btrpost.c ft_btrpre.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_btrsearch.c ft_btrinsert.c ft_del_list_el.c ft_lstadend.c ft_lstcount.c ft_itoabase.c ft_itoabase_size_p.c ft_itoabasell.c
OBJS = $(SRCS:.c=.o)
LIB_FOLDER = includes/

all: $(NAME)

go:
	./$(NAME_PROG)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRCS) -I $(LIB_FOLDER)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(NAME_PROG):
	@gcc $(NAME_MAIN_FILE) -Wall -Werror -Wextra -I $(LIB_FOLDER) -L. -$(NAME_LIB_SHORT) -o $(NAME_PROG)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
