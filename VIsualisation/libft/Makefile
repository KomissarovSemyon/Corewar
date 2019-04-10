%.c : %.o

NAME		= libft.a
CFLAGS		= -Wall -Werror -Wextra -I includes -c
FILES		= *.c
OBJ			= $(FILES:%.c=%.o)

SOURCES = ft_atoi.c ft_memcmp.c ft_putstr_fd.c ft_strjoin.c ft_strrchr.c \
		  ft_atoll.c ft_memcpy.c ft_strcat.c ft_strlcat.c ft_strrev.c \
		  ft_bzero.c ft_memdel.c ft_strchr.c ft_strlen.c ft_strsplit.c \
		  ft_isalnum.c ft_memmove.c ft_strclr.c ft_strmap.c ft_strstr.c \
		  ft_isalpha.c ft_memset.c ft_strcm.c ft_strmapi.c ft_strsub.c \
		  ft_isascii.c ft_putchar.c ft_strcmp.c ft_strncat.c ft_strtrim.c \
		  ft_isdigit.c ft_putchar_fd.c ft_strcpy.c ft_strncmp.c ft_tolower.c \
		  ft_isprint.c ft_putendl.c ft_strdel.c ft_strncpy.c ft_toupper.c \
		  ft_itoa.c ft_putendl_fd.c ft_strdup.c ft_strndup.c matrix_del.c \
		  ft_memalloc.c ft_putnbr.c ft_strequ.c ft_strnequ.c matrix_make.c \
		  ft_memccpy.c ft_putnbr_fd.c ft_striter.c ft_strnew.c putl.c \
		  ft_memchr.c ft_putstr.c ft_striteri.c ft_strnstr.c \
		  colors.c pars.c pr_isdigit.c pr_wstrlen.c print_num.c print_wchar.c \
		  ft_fprintf.c pr_atoi.c pr_strchri.c print_bin.c print_str.c \
		  ft_printf.c pr_bufaddstr.c pr_strlen.c print_float.c print_unum.c
INCLUDES = libft.h ft_printf.h

SRCDIR = ./srcs/
INCDIR = ./includes/

SRC = $(addprefix $(SRCDIR), $(SOURCES))
OBJ = $(SRC:.c=.o)
INC = $(addprefix $(INCDIR), $(INCLUDES))

all: $(NAME)

$(NAME): $(INC) $(OBJ)
	@ar rcs $(NAME) $(OBJ)

#$(OBJ): $(SRC)
#	gcc $(CFLAGS) -I $(INCDIR) $(SRC)

.c.o:
	@gcc $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
