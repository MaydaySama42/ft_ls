# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdalil <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 13:54:48 by mdalil            #+#    #+#              #
#    Updated: 2017/11/13 00:22:09 by mdalil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

INCLUDE_PATH = ./includes
SRC_LIBFT_PATH = ./srcs

SRC_LIBFT = ft_atoi.c\
		ft_bzero.c\
		ft_char_swap.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_lltoa_base.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putchar.c\
		ft_putendl_fd.c\
		ft_putendl.c\
		ft_putnbr_fd.c\
		ft_putnbr.c\
		ft_putstr_fd.c\
		ft_putstr.c\
		ft_recursive_power.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strrev.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_ulltoa_base.c\
		ft_printfast_flag_print.c\
		ft_printfast_flag.c\
		ft_printfast.c\

SRC = $(addprefix $(SRC_LIBFT_PATH)/,$(SRC_LIBFT))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o : %.c
	@clang -Wall -Wextra -Werror -I $(INCLUDE_PATH) -c $< -o $@

clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
