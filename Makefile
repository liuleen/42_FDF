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

LIBFT_DIR 		= ./libft/
MINILIBX_DIR 	= ./minilibx
SRC_DIR 		= ./src/
INC_DIR 		= ./includes/

#  -g tells the compiler to include debugging symbols (lldb)
FLAGS			= -Wall -Wextra -Werror -g
MINILIBXFLAGS	= -L $(MINILIBX) -lmlx -framework OpenGL -framework Appkit
FLAGS			= -I $(LIBFT_DIR) -I $(MINILIBX_DIR) -I (INC_DIR)

SRC_FILES 		= main.c read_fdf.c 
# fdf.c mlx.c
# INC_FILES		= fdf.h

SRC 			= $(addprefix $(SRC_DIR), $(SRC_FILES))
# INC				= $(addprefix $(INC_DIR), $(INC_FILES))
LIBFT 			= $(LIBFT_DIR)/libft.a 
MLX 			= $(MINILIBX_DIR)/libmlx.a

all: $(NAME)

# To produce only the compiled code -C (creates .o files)
$(NAME):
	@make -C (LIBFT_DIR)
	@make -C (MINILIBX_DIR)
	@gcc $(FLAGS) $(MINILIBXFLAGS) $(SRC) $(LIBFT) $(MLX) -o $(NAME)
	@echo "\033[32mCompiled Executable ^.^\033[0m"

clean:
	@make -C (LIBFT_DIR) clean
	@make -C (MINILIBX_DIR) clean
	@echo "\033[32mRemoved Object Files\033[0m"
	
fclean:
	@/bin/rm -f $(NAME)
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all
