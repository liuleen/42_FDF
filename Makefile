# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 17:39:16 by rliu              #+#    #+#              #
#    Updated: 2017/12/06 16:26:45 by rliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = Libft/libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
MINILIBXFLAGS = -L minilibx -lmlx -framework OpenGL -framework Appkit -I minilibx
SRC = main2.c

all: $(NAME)

$(NAME):
	@make -C Libft
	@$(CC) $(FLAGS) $(MINILIBXFLAGS) $(SRC) -o $(NAME)
	@echo "\033[32mCompiled Executable\033[0m"

clean:
	@make -C Libft clean
	@echo "\033[32mRemoved Object Files\033[0m"
fclean:
	@/bin/rm -f $(NAME)
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all
