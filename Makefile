# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 17:39:16 by rliu              #+#    #+#              #
#    Updated: 2018/02/12 19:51:42 by rliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf

LIBFT_DIR 		= ./libft/
MINILIBX_DIR 	= ./minilibx/
SRC_DIR 		= ./src/
INC_DIR 		= ./includes/
OBJ_DIR			= obj/

#  -g tells the compiler to include debugging symbols (lldb)
FLAGS			= -Wall -Wextra -Werror -g
MINILIBXFLAGS	= -L $(MINILIBX_DIR) -lmlx -framework OpenGL -framework Appkit
FLAGS			= -I $(LIBFT_DIR)$(INC_DIR) -I $(MINILIBX_DIR) -I $(INC_DIR) 
FLAGS			= -L $(LIBFT_DIR) -lft

SRC_FILES 		= main.c \
				  read_fdf.c \
				  mlx.c \
				  create_imgdata.c \
				  fdf.c \
				  rotate.c \
				  set.c

SRC 			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				= $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))
LIBFT 			= $(LIBFT_DIR)/libft.a 
MLX 			= $(MINILIBX_DIR)/libmlx.a

all:
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MINILIBX_DIR)
	@$(MAKE) -j $(NAME)

# To produce only the compiled code -C (creates .o files)
$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ) 
	@gcc $(FLAGS) $(MINILIBXFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)
	@echo "\033[32mCompiled Executable ^.^\033[0m"

	@echo "\033[36;1m                           \033[0m";
	@echo "\033[36;1m        ,--,               \033[0m";
	@echo "\033[36;1m      ,--.'|      ,----,   \033[0m";
	@echo "\033[36;1m   ,--,  | :    .'   .' \  \033[0m";
	@echo "\033[36;1m,---.'|  : '  ,----,'    | \033[0m";    
	@echo "\033[36;1m;   : |  | ;  |    :  .  ; \033[0m";
	@echo "\033[36;1m|   | :  : |  ;    |.'  /  \033[0m";
	@echo "\033[36;1m:   : |.'  |  \`----'/  ;   \033[0m";
	@echo "\033[36;1m|   ' '  ; :    /  ;  /    \033[0m";
	@echo "\033[36;1m\   \  .'. |   ;  /  /-,   \033[0m";
	@echo "\033[36;1m \`---\`:  : |  .  /  /  ;   \033[0m";
	@echo "\033[36;1m      '  ; | /__;  '   :   \033[0m";
	@echo "\033[36;1m      |  : ;|   :    .'    \033[0m";
	@echo "\033[36;1m      '  ,/ ;   | .'       \033[0m";
	@echo "\033[36;1m      '--'  \`---'         \033[0m";
	@echo "\033[36;1m                           \033[0m";
	@echo "\033[34;1mFDF created\n\033[0m";

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJ))

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINILIBX_DIR) clean
	@echo "\033[32mRemoved Object Files\033[0m"
	
fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all

$(LIBFT):
	@make -j  -C $(LIBFT_DIR)

$(MLX):
	@make -j  -C $(MINILIBX_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc -Wall -Wextra -Werror -I $(LIBFT_DIR)$(INC_DIR) -I $(MINILIBX_DIR) -I $(INC_DIR) -c $< -o $@
