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

NAME = ft_ls

INCLUDE_LIBFT = ./libft/includes
INCLUDE_FTLS = ./includes/

SRC_FTLS_FILE = ft_file_sort_utils.c\
				ft_file_sort.c\
				ft_file.c\
				ft_free.c\
				ft_options_l.c\
				ft_options_o.c\
				ft_options_r.c\
				ft_options_time.c\
				ft_options_x.c\
				ft_padding.c\
				ft_parser_options.c\
				ft_parser.c\
				ft_print_args.c\
				ft_sort_args_utils.c\
				ft_sort_args.c\
				main.c
SRC_FTLS_PATH = ./srcs/
SRC_FTLS = $(addprefix $(SRC_FTLS_PATH),$(SRC_FTLS_FILE))

SRC = $(SRC_FTLS)
OBJ = $(SRC_FTLS_FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@clang -Wall -Werror -Wextra $(OBJ) -o $(NAME) -Llibft -lft

%.o : $(SRC_FTLS_PATH)%.c
	@clang -Wall -Wextra -Werror -I $(INCLUDE_LIBFT) -I $(INCLUDE_FTLS) -c $< -o $@

clean:
	@/bin/rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
