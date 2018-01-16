# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 17:39:16 by rliu              #+#    #+#              #
#    Updated: 2017/12/18 17:05:42 by rliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf

#  -g tells the compiler to include debugging symbols (lldb)
FLAGS			= -Wall -Wextra -Werror -g
MINILIBXFLAGS	= -L $(MINILIBX) -lmlx -framework OpenGL -framework Appkit

SRC_DIR 		= ./src/
INC_DIR 		= ./includes/

SRC_FILES 		= main.c read_fdf.c fdf.c

LIBFT 			= libft/libft.a
MINILIBX 		= minilibx/libmlx.a
SRC 			= $(addprefix $(SRC_DIR), $(SRC_FILES))

all: $(NAME)

# To produce only the compiled code -C (creates .o files)
$(NAME):
	@make -C $(LIBFT)
	@make -C $(MINILIBX)
	@gcc $(FLAGS) $(MINILIBXFLAGS) $(SRC) -o $(NAME)
	@echo "\033[32mCompiled Executable ^.^\033[0m"

clean:
	@make -C $(LIBFT) clean
	@make -C $(MINILIBX) clean
	@echo "\033[32mRemoved Object Files\033[0m"
	
fclean:
	@/bin/rm -f $(NAME)
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all
